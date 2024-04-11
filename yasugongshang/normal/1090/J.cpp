#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
using std::cin; using std::cout;
using std::endl;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::stringstream; using std::vector;
using std::pair; using std::make_pair;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
#ifdef DEBUG
using std::cerr;
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)                                                     \
  {                                                                            \
    cerr << #a << " = {";                                                      \
    for (int qwq = (st); qwq <= (n); ++qwq)                                    \
      if (qwq == (st))                                                         \
        cerr << a[qwq];                                                        \
      else                                                                     \
        cerr << ", " << a[qwq];                                                \
    cerr << "}" << endl;                                                       \
  }
#define displayv(a) displaya(a, 0, (int)(a.size() - 1))
#include <ctime>
class MyTimer {
    clock_t st;
public:
    MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
    ~MyTimer() { report(); }
    void reset() { st = clock_t(); }
    void report() {  cerr << "Time consumed: " << (clock() - st) * 1e3 / CLOCKS_PER_SEC << "ms" << endl; }
} myTimer;
#else
#define cerr if(false) std::cout
#define pass ;
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(a) ;
class MyTimer {
public: void reset() {} void report() {}
} myTimer;
#endif

template<typename A, typename B>
std::ostream& operator << (std::ostream &cout, const pair<A, B> &x) {
    return cout << "(" << x.first << ", " << x.second << ")";
}
template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }

const int maxN = 100000 + 233;
int n, m;
char s[maxN], t[maxN], str[maxN * 2];
int z[maxN * 2], f[maxN];
int c[maxN];

void AlgoZ(char *s, int *z, int n) {
    z[1] = n;
    int L = 1, R = 1;
    for(int i = 2; i <= n; ++i) {
        int &len = z[i];
        if(i > R) len = 0;
        else len = std::min(R - i + 1, z[i - L + 1]);
        while(len + 1 <= n && s[i + len] == s[len + 1]) ++len;
        if(chmax(R, i + len - 1)) L = i, R = i + len - 1;
    }
}

void KMP(char *s, int *f, int n) {
    int j = 0;
    for(int i = 2; i <= n; ++i) {
        while(j && s[i] != s[j + 1]) j = f[j];
        if(s[i] == s[j + 1]) j++;
        f[i] = j;
    }
}

int main() {
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1); m = strlen(t + 1);
    for(int i = 1; i <= m; ++i) str[i] = t[i];
    for(int i = 1; i <= n; ++i) str[m + i] = s[i];
    AlgoZ(str, z, n + m);
    KMP(t, f, m);
    // displaya(z, 1, n + m);
    // displaya(f, 1, m);
    memset(c, 0, sizeof(c));
    for(int i = m + 2; i <= n + m; ++i) c[z[i]]++;
    for(int i = n; i >= 1; --i) c[i] += c[i + 1];
    LL ans = n * (LL)m;
    for(int i = 2; i <= m; ++i) if(f[i]) {
//        printf("i = %d, i - f[i] = %d, i - 1 = %d, c = %d\n", i, i - f[i], i - 1, c[i - f[i]]);
        ans -= c[i - f[i]];
    }
    cout << ans << endl;
    return 0;
}