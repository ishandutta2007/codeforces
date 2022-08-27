#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

vd mult(const vd & a, const vd & b) {
    vd c(a.size() + b.size() - 1, 0);
    forn(i,0,a.size()) forn(j,0,b.size()) c[i+j] += a[i]*b[j];
    return c;
}

class streefft {
public:
    vector<vd> t;
    int s;
    void build (const vd & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr) {
            t[v] = vd({1 - a[tl], a[tl]});
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = mult(t[v*2], t[v*2+1]);
        }
    }
};

vd imp[300];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vvi p(n, vi(m));
    forn(i,0,n) {
        forn(j,0,m) scanf("%d", &p[i][j]);
    }
    streefft st;
    forn(j,0,m) {
        vd pp;
        forn(i,0,n) pp.pb(double(p[i][j]) / 1000);
        st.build(pp, 1, 0, n-1);
        imp[j] = st.t[1];
        for(int i = n-1;i>=0; i--) imp[j][i] += imp[j][i+1];
    }
    set<pair<double, int>> greed;
    forn(j,0,m) greed.insert(mp(-imp[j][1], j));
    vi pt(m, 1);
    double ans = 0;
    forn(i,0,n) {
        auto x = *greed.begin();
        greed.erase(greed.begin());
        pt[x.second]++;
        ans -= x.first;
        greed.insert(mp(-imp[x.second][pt[x.second]], x.second));
    }
    printf("%.12lf", ans);
    
    
    
}