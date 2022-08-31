#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
typedef std::vector<vpll> vvpll;

const long long mod = 1000000007;
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

vi lens;
int ls;
vi mdeg;
ll m;
vvpll g;
vll ans;
vvi vdegs;
vi compsize;
vi chunksze;
vi vcount;

vi getdeg(int v) {
    vi ret;
    for(int i = ls - 1; i>=0; i--) {
        ret.pb(v%(mdeg[i]+1));
        v/=(mdeg[i]+1);
    }
    reverse(all(ret));
    return ret;
}

ll temp[1000000];
ll dp[50][50];
ll fm[50][50][50];
ll cnk[50][50];

void solve(int n) {
    int num = compsize[n];
    ans[n] = 0;
    for(auto st : g[n]) {
        if(st.first != 0) {
            int s = compsize[st.first];
            ll val = ans[n-st.first] * fm[num-1][num-1][s] % mod * fm[num][s][num-s] % mod * st.second %mod;
            if(chunksze[st.first] % 2 == 1) ans[n] = (ans[n] + val) % mod;
            else ans[n] = (ans[n] + mod - val)%mod;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,50) {
        cnk[i][0] = 1;
        cnk[0][i] = 0;
    }
    cnk[0][0] = 1;
    forn(i,1,50) forn(j,1,50) {
        cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1]) % mod;
    }
    forn(i,0,50) {
        dp[i][0] = 1;
        dp[i][1] = i;
        forn(j,2,50) dp[i][j] = dp[i][j-1]*i%mod;
        fm[i][0][1] = 1;
        fm[i][1][1] = i;
        forn(j,0,50) {
            fm[i][j][0] = 1;
            if(j>1) fm[i][j][1] = fm[i][j-1][1] * (i-j+1) % mod;
            forn(k,2,50) fm[i][j][k] = fm[i][j][k-1] * fm[i][j][1] % mod;
        }
    }
    forn(i,0,50) dp[0][i] = 1;
    int n;
    read(n);
    readv(a,n);
    forn(i,0,n) a[i]--;
    vi vis(n, 0);
    map<int, int> len;
    forn(i,0,n) {
        if(vis[i] == 0) {
            int curl = 1;
            vis[i] = 1;
            int m = a[i];
            while(vis[m] == 0) {
                curl ++;
                vis[m] = 1;
                m = a[m];
            }
            len[curl]++;
        }
    }
    int m = 1;
    for(auto x : len) {
        m *= x.second + 1;
        lens.pb(x.first);
        mdeg.pb(x.second);
        ls ++ ;
    }
    g.resize(m);
    ans.resize(m);
    ans[0] = 1;
    forn(i,0,m) vdegs.pb(getdeg(i));
    compsize = vi(m,0);
    chunksze = vi(m,0);
    vcount = vi(m,1);
    forn(i,0,m) {
        forn(j,0,ls) compsize[i] += vdegs[i][j] * lens[j];
        forn(j,0,ls) chunksze[i] += vdegs[i][j];
        forn(j,0,ls) vcount[i] *= (vdegs[i][j] + 1);
    }
    forn(i,0,m) forn(j,i,m) {
        int less = 1;
        ll fat = 1;
//        int dif = 0;
        forn(k,0,ls) {
            if(vdegs[j][k] < vdegs[i][k]) {
                less = 0;
                break;
            }
            else fat = fat * cnk[vdegs[j][k]][vdegs[i][k]];
        }
        if(less) g[j].pb(mp(i,fat));
    }
    forn(i,1,m) solve(i);
    cout<<ans[m-1];
}