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

struct segment_tree {
  struct Node {
    int mn, mx;
  };
  vector<Node> t;
  vector<int> arr;
  int n;
  segment_tree(vector<int> _arr, int _n) {
    arr = _arr;
    n = _n;
    t.rsz(4 * n + 10);
    build(1, 0, n);
  }
  void build(int v, int l, int r) {
    if (l == r) {
      t[v].mn = t[v].mx = arr[l];
      return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    t[v].mn = min(t[2 * v].mn, t[2 * v + 1].mn);
    t[v].mx = max(t[2 * v].mx, t[2 * v + 1].mx);
  }
  void upd(int v, int l, int r, int pos, int new_val) {
    if (l == r) {
      t[v].mn = t[v].mx = new_val;
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
      upd(2 * v, l, mid, pos, new_val);
    }
    else {
      upd(2 * v + 1, mid + 1, r, pos, new_val);
    }
    t[v].mn = min(t[2 * v].mn, t[2 * v + 1].mn);
    t[v].mx = max(t[2 * v].mx, t[2 * v + 1].mx);
  }
  int get_min(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
      return INF;
    }
    if (l >= a && r <= b) {
      return t[v].mn;
    }
    int mid = (l + r) / 2;
    return min(get_min(2 * v, l, mid, a, b), get_min(2 * v + 1, mid + 1, r, a, b));
  }
  int go_down(int v, int l, int r, int a, int b, int mx_can, int &cur_max, int &cur_min) {
    if (l > b || r < a || cur_max - cur_min > mx_can) {
      return INF;
    }
    if (l >= a && r <= b) {
      if (l == r) {
        cur_max = max(cur_max, t[v].mx);
        cur_min = min(cur_min, t[v].mn);
        return cur_max - cur_min <= mx_can ? l : INF;
      }
      int mid = (l + r) / 2;
      int nmx = max(cur_max, t[2 * v + 1].mx), nmn = min(cur_min, t[2 * v + 1].mn);
      if (nmx - nmn <= mx_can) {
        cur_max = nmx;
        cur_min = nmn;
        int res = min(mid + 1, go_down(2 * v, l, mid, a, b, mx_can, cur_max, cur_min));
        cur_max = max(cur_max, t[v].mx);
        cur_min = min(cur_min, t[v].mn);
        return res;
      }
      int res = go_down(2 * v + 1, mid + 1, r, a, b, mx_can, cur_max, cur_min);
      cur_max = max(cur_max, t[v].mx);
      cur_min = min(cur_min, t[v].mn);
      return res;
    }
    int mid = (l + r) / 2;
    int res = go_down(2 * v + 1, mid + 1, r, a, b, mx_can, cur_max, cur_min);
    res = min(res, go_down(2 * v, l, mid, a, b, mx_can, cur_max, cur_min));
    return res;
  }
};

void source() {
  int n = readInt(), mx = readInt(), mn_len = readInt();
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    arr[i] = readInt();
  }
  arr[0] = -INF;
  segment_tree t1(arr, n);
  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  segment_tree t2(dp, n);
  for (int i = 1; i <= n; i++) {
    int kek1 = -INF, kek2 = INF;
    int cur_pos = t1.go_down(1, 0, n, 0, i, mx, kek1, kek2);
    if (cur_pos > i - mn_len + 1) {
      dp[i] = INF;
    }
    else {
      dp[i] = t2.get_min(1, 0, n, cur_pos - 1, i - mn_len) + 1;
    }
    t2.upd(1, 0, n, i, dp[i]);
  }
  if (dp[n] >= INF) {
    writeInt(-1);
  }  
  else {
    writeInt(dp[n]);
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