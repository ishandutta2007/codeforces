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
const int N = 100002;
vi divs[N+1];
int num[N+1];
//ll ans[N+1];
ll kpow(ll a, ll d) {
    if (d==0) return 1;
    ll x = kpow(a,d/2);
    x = x*x%mod;
    if (d%2==1) x*=a;
    return x%mod;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    //int mindiv[N+1];
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    vi sq(N+1,0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    divs[1].pb(1);
    int tot = 1;
    sq[1] = 1;
    forn(i,2,N+1) {
        int m = i;
        int p = mindiv[m];
        int deg =1 ;
        m/=p;
        while(m%p == 0) {
            m/=p;
            deg++;
        }
        sq[i] = sq[m]*p;
        divs[i] = divs[m];
        int dp = p;
        int l = divs[m].size();
        forn(eafk,1,deg+1) {
            forn(j,0,l) divs[i].pb(divs[i][j]*dp);
            dp*=p;
        }
        srt(divs[i]);
//        tot += divs[i].size();
    }
    vi odd(N+1,0);
    forn(i,2,N+1) if(sq[i] == i) odd[i] = 1^odd[i/mindiv[i]];
    
//    cout<<tot;
    int n;
    read(n);
    readv(a,n);
    forn(i,0,n) num[a[i]]++;
//    forn(i,1,N) num[i]+=num[i-1];
    for(int i = N-1; i>=1; i--) num[i-1] += num[i];
    ll ans = 0;
    forn(mx,1,N) {
        divs[mx].pb(N);
        ll res = 1;
        forn(i,1,divs[mx].size()) {
            int k = num[divs[mx][i-1]] - num[divs[mx][i]];
            ll w = kpow(i,k);
            if(i+1==divs[mx].size()) {
                w = (w + mod - kpow(i-1, k))%mod;
            }
            res = res*w%mod;
        }
        ans = (ans+res)%mod;
//        ans[mx] = res;
    }
//    forn(i,0,10) cout<<i<<' '<<ans[i]<<'\n';
    cout<<ans;
    
}