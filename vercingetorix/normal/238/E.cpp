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

const int A = 100;
int d[A][A];
int dc[A][A];
int win[A];
int on[A];
int fon[A];
int cnt[A];
vi g[A];
const int INF = 1e5;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,a,b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    a--;
    b--;
    forn(i,0,n) forn(j,0,n) if(i!=j) d[i][j] = INF;
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        d[u][v] = 1;
    }
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    int l;
    scanf("%d", &l);
    vi s(l), t(l);
    forn(i,0,l) {
        scanf("%d %d", &s[i], &t[i]);
        s[i]--;
        t[i]--;
    }
    forn(i,0,l) {
        if(d[s[i]][t[i]] >= INF) {
            swap(s[i], s.back());
            swap(t[i], t.back());
            s.pop_back();
            t.pop_back();
            l--;
            i--;
        }
    }
    win[b] = 1;
    int pt = 0;
    while(1) {
        pt++;
        vi bad;
        forn(i,0,n) if(win[i] == 0) bad.pb(i);
        forn(x,0,n) forn(y,0,n) dc[x][y] = INF;
        for(auto x : bad) dc[x][x] = 0;
        for(auto x : bad) for(auto y : g[x]) if(win[y] == 0) dc[x][y] = 1;
        for(auto k : bad) for(auto i : bad) for(auto j : bad)
            dc[i][j] = min (dc[i][j], dc[i][k] + dc[k][j]);
        int upd = 0;
        forn(it,0,l) {
            forn(i,0,n) on[i] = 0;
            forn(i,0,n) fon[i] = 0;
            forn(i,0,n) cnt[i] = 0;
            forn(i,0,n) if(d[s[it]][i] + d[i][t[it]] == d[s[it]][t[it]]) {
                on[i] = 1;
                cnt[d[s[it]][i]]++;
            }
            forn(i,0,n) if(on[i] && cnt[d[s[it]][i]] == 1) fon[i] = 1;
            for(auto i : bad) if(fon[i]) if(win[i] == 0 && (d[i][t[it]] != dc[i][t[it]])) {
                win[i] = 1;
                upd = 1;
            }
        }
        if(win[a]) {
            printf("%d\n", pt);
            exit(0);
        }
        else if(upd == 0) {
            printf("-1\n");
            exit(0);
        }
    }
    
    
}