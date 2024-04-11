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

const long long mod = 998244353;
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

set<vi> spl[17];
ll cnk[1<<16][20];
ll nfac[20];
ll ifac[20];
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

ll ways(int n, const vi & sub) {
    int pt = 0;
    vpi q;
    if(sub.size() > n) return 0;
    ll ret = 1;
    int was = 0;
    forn(i,0,sub.size()) {
        ret = ret*(n-i)%mod*cnk[was+sub[i]][was]%mod;
        was += sub[i];
    }
    while(pt < sub.size()) {
        int pr = pt+1;
        while(pr < sub.size() && sub[pr] == sub[pt]) pr++;
        ret = ret*ifac[pr-pt]%mod;
        pt = pr;
    }
    return ret;
}

vpi d[200][17];
ll cur[17][1<<16];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    nfac[0] = 1;
    forn(i,1,20) nfac[i] = nfac[i-1]*i%mod;
    forn(i,0,20) ifac[i] = invmod(nfac[i], mod);
    forn(i,0,1<<16) cnk[i][0] = 1;
    forn(i,1,1<<16) forn(k,1,20) {
        cnk[i][k] = cnk[i-1][k] + cnk[i-1][k-1];
        if(cnk[i][k] >= mod) cnk[i][k] -= mod;
    }
    spl[0].insert(vi());
    forn(i,0,16) {
        for(auto y : spl[i]) {
            forn(j,0,y.size()) {
                vi z = y;
                z[j]++;
                srtrev(z);
                spl[i+1].insert(z);
            }
            y.pb(1);
            spl[i+1].insert(y);
        }
    }
//    cout<<spl[16].size();
    int n,k,c;
    scanf("%d %d %d", &n, &k, &c);
    readv(a,n);
    vi cnt(1<<c, 0);
    vi killbit(1<<c, 0);
    forn(i,1,1<<c) {
        int bit = 0;
        while((i&(1<<bit)) == 0) bit++;
        killbit[i] = bit - 1;
    }
    int ans = 0;
    forn(i,0,n) {
        int d2 = 1;
        while(((d2 - 1)&a[i]) < min(a[i],k)) d2*=2;
        cnt[((d2 - 1)&a[i])] ++;
//        ans ^= ((d2 - 1)&a[i])^a[i];
        ans ^= a[i];
//        ans ^= (a[i]&1);
    }
    forn(i,0,k) ans ^= 1;
    int pos = 0;
    d[0][0].pb(mp(0, 1));
    forn(i,0,1<<c) {
        if(cnt[i] > 0) {
            forn(j,0,k+1) forn(f,0,1<<(c-1)) cur[j][f] = 0;
            forn(up, 0, k+1) {
                map<int, ll> op;
                for(auto & y : spl[up]) {
                    ll w = ways(cnt[i], y);
                    if(w == 0) continue;
                    int blink = 0;
                    for(auto x : y) {
                        int m = i;
                        forn(it,0,x) {
                            if(killbit[m]!=-1) blink ^= 1<<killbit[m];
                            m--;
                        }
                    }
                    op[blink] += w;
                }
//                cout<<op.size();
                for(auto y : op) {
                    y.second %= mod;
                    forn(was,0,k+1-up) {
                        for(auto x : d[pos][was]) cur[was + up][x.first^y.first] = (cur[was + up][x.first^y.first] + y.second*x.second%mod*cnk[was+up][was])%mod;
                    }
                }
            }
            forn(now,0,k+1) forn(nv,0,1<<(c-1)) if(cur[now][nv] > 0) d[pos+1][now].pb(mp(nv, cur[now][nv]));
            pos++;
        }
    }
    vll ret(1<<c);
    for(auto x : d[pos][k]) {
        int val = ans;
        forn(bit,0,c-1) if(x.first & (1<<bit)) val ^= ((1<<(bit+2)) - 2);
        ret[val] = x.second;
    }
    ll dn = 1;
//    ll tot = 0;
//    forn(i,0,1<<c) tot+=ret[i];
//    forn(i,0,k) tot  = tot%mod*invmod(n,mod)%mod;
//    cout<<tot<<endl;
    forn(i,0,k) dn = dn*invmod(n, mod)%mod;
    forn(i,0,1<<c) printf("%lld ", ret[i]*dn%mod);
    
    
}