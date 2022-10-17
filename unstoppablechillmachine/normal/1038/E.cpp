//author: extraterrestrial_
//I_l_M_P
#include <bits/stdc++.h>

#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
inline void * operator new ( size_t n ) {
  char *res = allocator_memory + allocator_pos;
  allocator_pos += n;
  assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
  return (void *)res;
}
inline void operator delete ( void * ) noexcept { }
//inline void * operator new [] ( size_t ) { assert(0); }
//inline void operator delete [] ( void * ) { assert(0); }
#endif

template <class T = int> inline T readInt();
inline double readDouble();
inline int readUInt();
inline int readChar();
inline void readWord(char *s);
inline bool readLine(char *s);
inline bool isEof();
inline int getChar();
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();

template <class T> inline void writeInt(T x, char end = 0, int len = -1);
inline void writeChar(int x);
inline void writeWord(const char *s);
inline void writeDouble(double x, int len = 0);
inline void flush();

static struct buffer_flusher_t {
  ~buffer_flusher_t() {
    flush();
  }
} buffer_flusher;

static const int buf_size = 4096;

static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
  if (buf_pos == buf_len) {
    buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
    if (buf_pos == buf_len)
      return 1;
  }
  return 0;
}

inline int getChar() {
  return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() {
  return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() {
  int c;
  while ((c = peekChar()) != -1 && c <= 32)
    buf_pos++;
  return c == -1;
}

inline void skipBlanks() {
  while (!isEof() && buf[buf_pos] <= 32U)
    buf_pos++;
}

inline int readChar() {
  int c = getChar();
  while (c != -1 && c <= 32)
    c = getChar();
  return c;
}

inline int readUInt() {
  int c = readChar(), x = 0;
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return x;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getChar();
  else if (c == '+')
    c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

inline double readDouble() {
  int s = 1, c = readChar();
  double x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  if (c == '.') {
    c = getChar();
    double coef = 1;
    while ('0' <= c && c <= '9')
      x += (c - '0') * (coef *= 1e-1), c = getChar();
  }
  return s == 1 ? x : -x;
}

inline void readWord(char *s) {
  int c = readChar();
  while (c > 32)
    *s++ = c, c = getChar();
  *s = 0;
}

inline bool readLine(char *s) {
  int c = getChar();
  while (c != '\n' && c != -1)
    *s++ = c, c = getChar();
  *s = 0;
  return c != -1;
}

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
  if (write_buf_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
  write_buf[write_buf_pos++] = x;
}

inline void flush() {
  if (write_buf_pos) {
    fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
    fflush(stdout);
  }
}

template <class T>
inline void writeInt(T x, char end, int output_len) {
  if (x < 0)
    writeChar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len)
    s[n++] = '0';
  while (n--)
    writeChar(s[n]);
  if (end)
    writeChar(end);
}

inline void writeWord(const char *s) {
  while (*s)
    writeChar(*s++);
}

inline void writeDouble(double x, int output_len) {
  if (x < 0)
    writeChar('-'), x = -x;
  int t = (int)x;
  writeInt(t), x -= t;
  writeChar('.');
  for (int i = output_len - 1; i > 0; i--) {
    x *= 10;
    t = std::min(9, (int)x);
    writeChar('0' + t), x -= t;
  }
  x *= 10;
  t = std::min(9, (int)(x + 0.5));
  writeChar('0' + t);
}

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

//#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)

using namespace std;

typedef long double ld;
typedef long long ll;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define int ll

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

void source() {
  int n = readInt();
  vector<pair<int, int> > color(n);
  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    color[i].f = readInt(), val[i] = readInt(), color[i].sec = readInt();
    color[i].f--;
    color[i].sec--;
  }
  vector<pair<int, int> > xui;
  for (int i = 0; i < n; i++) {
    if (color[i].f < color[i].sec) {
      swap(color[i].f, color[i].sec);
    }
    xui.pb({color[i].f * 4 + color[i].sec, i});
  }
  sort(all(xui));
  vector<pair<int, int> > color2(n);
  vector<int> val2(n);
  for (int i = 0; i < n; i++) {
    color2[i] = color[xui[i].sec];
    val2[i] = val[xui[i].sec];
  }
  color = color2;
  val = val2;
  vector<vector<vector<vector<vector<int> > > > > dp(n + 1, vector<vector<vector<vector<int> > >>(n + 1, vector<vector<vector<int> > >(16, vector<vector<int> >(4, vector<int>(4, -BINF)))));
  for (int i = 0; i < n; i++) {
    dp[i + 1][i + 1][0][color[i].f][color[i].sec] = dp[i + 1][i + 1][0][color[i].sec][color[i].f] = val[i];
  }
  for (int len = 1; len < n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      for (int mask = 0; mask < 16; mask++) {
        for (int left = 0; left < 4; left++) {
          for (int right = 0; right < 4; right++) {
            int r = l + len - 1;
            if (r < n) {
              pair<int, int> cur = color[r];
              int add = val[r];
              for (int j = 0; j < 2; j++) {
                if (cur.f == right) {
                  dp[l][r + 1][mask | (1 << right)][left][cur.sec] = max(dp[l][r + 1][mask | (1 << right)][left][cur.sec], dp[l][r][mask][left][right] + add);
                }
                if (cur.sec == left) {
                  dp[l][r + 1][mask | (1 << left)][cur.f][right] = max(dp[l][r + 1][mask | (1 << left)][cur.f][right], dp[l][r][mask][left][right] + add);
                }
                swap(cur.f, cur.sec);
              }
              if (cur.f == cur.sec) {
                if ((mask >> cur.f) & 1) {
                  dp[l][r + 1][mask][left][right] = max(dp[l][r + 1][mask][left][right], dp[l][r][mask][left][right] + add);
                }
              }
              dp[l][r + 1][mask][left][right] = max(dp[l][r + 1][mask][left][right], dp[l][r][mask][left][right]);
            }
            if (l > 1) {
              pair<int, int> cur = color[l - 2];
              int add = val[l - 2];
              for (int j = 0; j < 2; j++) {
                if (cur.f == right) {
                  dp[l - 1][r][mask | (1 << right)][left][cur.sec] = max(dp[l - 1][r][mask | (1 << right)][left][cur.sec], dp[l][r][mask][left][right] + add);
                }
                if (cur.sec == left) {
                  dp[l - 1][r][mask | (1 << left)][cur.f][right] = max(dp[l - 1][r][mask | (1 << left)][cur.f][right], dp[l][r][mask][left][right] + add);
                }
                swap(cur.f, cur.sec);
              }
              if (cur.f == cur.sec) {
                if ((mask >> cur.f) & 1) {
                  dp[l - 1][r][mask][left][right] = max(dp[l - 1][r][mask][left][right], dp[l][r][mask][left][right] + add);
                }
              }
              dp[l - 1][r][mask][left][right] = max(dp[l - 1][r][mask][left][right], dp[l][r][mask][left][right]);
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int mask = 0; mask < 16; mask++) {
    for (int left = 0; left < 4; left++) {
      for (int right = 0; right < 4; right++) {
        ans = max(ans, dp[1][n][mask][left][right]);
      }
    }
  }
  writeInt<ll>(ans);
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  writeWord("\n\t");
  writeDouble((double)clock() / (double)CLOCKS_PER_SEC, 10);
  writeWord(" seconds\n\n");
#endif
  return 0;
}