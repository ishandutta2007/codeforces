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

const int N = 1010;
int left[N][N], right[N][N], up[N][N], down[N][N], delta_str[N][N], delta_st[N][N];

void source() {
  int n = readInt(), m = readInt();
  vector<vector<char> > arr(n + 2, vector<char>(m + 2));
  vector<vector<int> > was(n + 2, vector<int>(m + 2));
  vector<pair<pair<int, int>, int> > ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      arr[i][j] = readChar();
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j - 1] == '*') {
        left[i][j] = left[i][j - 1] + 1;
      }
      else {
        left[i][j] = 0;
      }
    }
    for (int j = m; j >= 1; j--) {
      if (arr[i][j + 1] == '*') {
        right[i][j] = right[i][j + 1] + 1;
      }
      else {
        right[i][j] = 0;
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (arr[i - 1][j] == '*') {
        up[i][j] = up[i - 1][j] + 1;
      }
      else {
        up[i][j] = 0;
      }
    }
    for (int i = n; i >= 1; i--) {
      if (arr[i + 1][j] == '*') {
        down[i][j] = down[i + 1][j] + 1;
      }
      else {
        down[i][j] = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j] != '*') {
        continue;
      }
      int mn = min(min(left[i][j], right[i][j]), min(up[i][j], down[i][j]));
      if (mn) {
        delta_str[i][j - mn]++;
        delta_str[i][j + mn + 1]--;
        delta_st[i - mn][j]++;
        delta_st[i + mn + 1][j]--;
        ans.pb(mk(mk(i, j), mn));
        for (int k = i - mn; k <= i + mn; k++) {
          was[k][j] = true;
        }
        for (int k = j - mn; k <= j + mn; k++) {
          was[i][k] = true;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (int j = 1; j <= m; j++) {
      cur += delta_str[i][j];
      was[i][j] += cur;
    }
  }
  for (int j = 1; j <= m; j++) {
    int cur = 0;
    for (int i = 1; i <= n; i++) {
      cur += delta_st[i][j];
      was[i][j] += cur;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j] == '*' && !was[i][j]) {
        writeInt(-1);
        exit(0);
      }
    }
  }
  writeInt((int)ans.size(), '\n');
  for (auto it : ans) {
    writeInt(it.f.f, ' ');
    writeInt(it.f.sec, ' ');
    writeInt(it.sec, '\n');
  }
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