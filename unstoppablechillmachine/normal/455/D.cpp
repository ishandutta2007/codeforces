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

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-reorder-functions")
#pragma GCC optimize("profile-values")
#pragma GCC optimize("tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("ssse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")

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
//#define int ll

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int R = 1050;
const int N = 1e5 + 10;
const int SZ = (int)sqrt(N);
int a[N], n, cur[SZ + 10][5 * SZ + 10], sz[SZ + 10], cnt_blocks;
short calc[SZ + 10][N];

inline void build() {
  cnt_blocks = 0;
  for (int i = 0; i < n; i += SZ) {
    int to = min(i + SZ, n) - 1;
    for (int j = i; j <= to; j++) {
      calc[cnt_blocks][a[j]]++;
      cur[cnt_blocks][sz[cnt_blocks]++] = a[j];
    }
    cnt_blocks++;
  }
}

inline void rebuild() {
  int ind = 0;
  for (int i = 0; i < cnt_blocks; i++) {
    for (int j = 0; j < sz[i]; j++) {
      a[ind++] = cur[i][j];
      calc[i][cur[i][j]] = 0;
    }
    sz[i] = 0;
  }
  build();
}

inline int erase(int ind) {
  int sum = 0;
  for (int i = 0; i < cnt_blocks; i++) {
    if (sum + sz[i] > ind) {
      int ps = ind - sum, res = cur[i][ps];
      calc[i][res]--;
      for (int j = ps; j + 1 < sz[i]; j++) {
        cur[i][j] = cur[i][j + 1];
      }
      sz[i]--;
      return res;
    }
    sum += sz[i];
  }
  return 0;
}

inline void insert(int ind, int vl) {
  int sum = 0;
  for (int i = 0; i < cnt_blocks; i++) {
    if (sum + sz[i] > ind) {
      int ps = ind - sum + 1;
      calc[i][vl]++;
      sz[i]++;
      for (int j = sz[i] - 1; j > ps; j--) {
        cur[i][j] = cur[i][j - 1];
      }
      cur[i][ps] = vl;
      return;
    }
    sum += sz[i];
  }
  return;
}

inline void shift(int l, int r) {
  insert(l - 1, erase(r));
}

inline int get(int r, int vl) {
  int res = 0, sum = 0;
  for (int i = 0; i < cnt_blocks; i++) {
    if (sum + sz[i] > r) {
      int ps = r - sum;
      for (int j = 0; j <= ps; j++) {
        res += (cur[i][j] == vl);
      }
      break;
    }
    res += calc[i][vl];
    sum += sz[i];
  }
  return res;
}

void source() {
  n = readInt();
  for (int i = 0; i < n; i++) {
    a[i] = readInt();
  }
  int m = readInt();
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (i % R == 0) {
      rebuild();
    }
    int type = readInt();
    if (type == 1) {
      int cur_l = readInt(), cur_r = readInt(), l = (cur_l + ans - 1) % n, r = (cur_r + ans - 1) % n;
      if (l > r) {
        swap(l, r);
      }
      shift(l, r);
    }
    else {
      int cur_l = readInt(), cur_r = readInt(), cur_k = readInt(), l = (cur_l + ans - 1) % n, r = (cur_r + ans - 1) % n, k = (cur_k + ans - 1) % n + 1;
      if (l > r) {
        swap(l, r);
      }
      ans = get(r, k) - get(l - 1, k);
      writeInt(ans, '\n');
    }
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
  //freopen(TASK".in", "r", stdin);
  //freopen(TASK".out", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}