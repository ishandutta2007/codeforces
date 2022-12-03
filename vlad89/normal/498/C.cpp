#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

//D
string _str(const bool x) {ostringstream str; str << (x ? "true" : "false"); return str.str(); }
string _str(const int x) {ostringstream str; str << x; return str.str(); }
string _str(const long long x) {ostringstream str; str << x; return str.str(); }
string _str(const char x) {ostringstream str; str << "'" << x << "'"; return str.str(); }
string _str(const string x) {ostringstream str; str << '"' << x << '"'; return str.str(); }
string _str(const double x) {ostringstream str; str.precision(6); str.setf(ios::fixed); str << x; return str.str(); }
string _str(const char* x) { return _str((string) x);}
template<class T> string _str(const vector<T> x) {ostringstream str; str << "["; for(int i = 0; i < x.size(); ++i) { if (i) str << ", "; str << x[i]; } str << "] size " << x.size(); return str.str(); }
template<class T> string _str(const set<T> x) {ostringstream str; str << "{"; bool first = true; for(auto it: x) { if (!first) str << ", "; first = false; str << it; } str << "} size " << x.size(); return str.str(); }
template<class K, class V> string _str(const map<K, V> x) {ostringstream str; str << "{"; bool first = true; for(auto it: x) { if (!first) str << ", "; first = false; str << it.X << " -> " << it.Y; } str << "} size " << x.size(); return str.str(); }

#ifdef LocalHost
  #define D(x) cout << #x" = " << _str(x) << endl;
  #define D2(x1, x2) cout << #x1" = " << _str(x1) << " | " << #x2" = " << _str(x2) << endl;
  #define D3(x1, x2, x3) cout << #x1" = " << _str(x1) << " | " << #x2" = " << _str(x2) << " | " << #x3" = " << _str(x3) << endl;
  #define D4(x1, x2, x3, x4) cout << #x1" = " << _str(x1) << " | " << #x2" = " << _str(x2) << " | " << #x3" = " << _str(x3) << " | " << #x4" = " << _str(x4) << endl;
#else
 #define D(x);
 #define D2(x1, x2);
 #define D3(x1, x2, x3);
 #define D4(x1, x2, x3, x4);
#endif
//~D

template <int N, int M>
struct Graph {
    const int INF = -1u/2;
    struct Edge {
        int w, cap, next;
        Edge(int iw=-1, int icap=0, int inext=-1) : w(iw),cap(icap),next(inext) {}
    };
    int first[N], d[N], st[N], cur[N], sz, n, m, s, t;
    Edge E[2*M];
    void init(int in) {
        n = in; m = 0;
        REP (i, n) first[i] = -1;
    }
    inline void add(int q, int w, int cap) {
        E[m] = Edge (w, cap, first[q]); first[q] = m++;
        E[m] = Edge (q, 0, first[w]);  first[w] = m++;
    }
    bool bfs ()
    {
        REP (i, n) d[i] = -1;
        sz = 1; st[0] = t; d[t] = 0;
        for (int cr = 0; cr < sz; ++cr)
        {
            int x = st[cr];
            for (int e = first[x]; e > -1; e = E[e].next)
                if (E[e^1].cap && d[E[e].w] == -1)
                {
                    d[E[e].w] = d[x] + 1;
                    st[sz++] = E[e].w;
                }
        }
        return d[s] > -1;
    }
    int dfs (int x, int flow)
    {
        if (x == t) return flow;
        for (int & e = cur[x]; e > -1; e = E[e].next) {
            if (E[e].cap && d[E[e].w] == d[x] - 1)
            {
                int v = dfs (E[e].w, min (flow, E[e].cap));
                if (v)
                {
                    E[e].cap -= v;
                    E[e^1].cap += v;
                    return v;
                }
            }
        }
        return 0;
    }
    ll max_flow(int is,int it) {
        s = is; t = it;
        ll res = 0;
        while (bfs ()) {
            REP (i, n) cur[i] = first[i];
            while (1)
            {
                int val = dfs (s, INF);
                if (!val) break;
                res += val;
            }
        }
        return res;
    }
};

const int N = 128;
int a[N];
vi b[N];

vi prime_divisors(int x) {
    vi res;
    for (int i = 2; i*i <= x; ++i) if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            res.pb(i);
        }
    if (x != 1) res.pb(x);
    return res;
}

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    Graph<128, 128*128> g;
    int n, m;
    cin >> n >> m;
    vi allprimes;
    vi left, right;
    REP (i, n) {
        cin >> a[i];
        vector<int> primes = prime_divisors(a[i]);
        allprimes.insert(allprimes.end(), all(primes));
        if (i & 1) right.pb(a[i]); else left.pb(a[i]);
    }
    UN(allprimes);
    REP (i, m) {
        int q, w;
        cin >> q >> w;
        --q, --w;
        if (q & 1) swap(q, w);

        q /= 2;
        w /= 2;
        b[q].pb(w);
    }
    int cleft = sz(left);
    int cright = sz(right);
    int res = 0;
    for (auto& prime: allprimes) {
      D(prime);
        int s = cleft + cright;
        int t = cleft + cright + 1;
        g.init(t + 1);
        for (int i = 0; i < cleft; ++i) {
            int divides = 0;
            int x = left[i];
            while (x % prime == 0) {
                x /= prime;
                ++divides;
            }
            g.add(s, i, divides);
        D3(s, i, divides);
        }
        for (int i = 0; i < cright; ++i) {
            int divides = 0;
            int x = right[i];
            while (x % prime == 0) {
                x /= prime;
                ++divides;
            }
            g.add(cleft + i, t, divides);
        D3(cleft + i, t, divides);
        }
        for (int i = 0; i < cleft; ++i) {
            for (auto j : b[i]) {
                g.add(i, cleft + j, -1u/4);
        D3("other", i, cleft+j);
            }
        }
        res += g.max_flow(s, t);
    }
    cout << res << endl;
    return 0;
}