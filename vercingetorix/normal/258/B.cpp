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
int nfac[10];
ll cnk(int u, int k) {
    if(k<0 || k>u) return 0;
    return nfac[u]/nfac[k]/nfac[u-k];
}

vi d;
int cur = 0;
int n;
vi cnt(10, 0);
void go(int k) {
    if(k == n) {
        cnt[cur]++;
        return;
    }
    forn(f,0,d[k]) {
        int l = n - k -1;
        int add = 0;
        if(f == 4 || f==7) add++;
        forn(num,0,l+1) {
            cnt[cur+add+num] += cnk(l, num)*(1<<(num + 3*(l-num)));
        }
    }
    if(d[k] == 4 || d[k] == 7) cur++;
    go(k+1);
}

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

ll scnk(int u, int k) {
    if(k>u) return 0;
    ll ret = 1;
    forn(i,1,k+1) {
        ret = ret*(u+1-i)%mod*invmod(i,mod)%mod;
    }
    return ret;
}

ll a[7][10];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    nfac[0] = 1;
    forn(i,1,10) nfac[i] = nfac[i-1]*i;
    int m;
    cin>>m;
    
    
    while(m > 0) {
        d.pb(m%10);
        m/=10;
    }
    reverse(all(d));
    n = d.size();
    go(0);
    cnt[0]--;
//    forn(i,0,10) cout<<cnt[i]<<'\n';
    ll ans = 0;
    a[0][0] = 1;
    forn(num,0,10) {
        forn(s,0,num) ans += cnt[num]*a[6][s] % mod;
        for(int was = 5; was >= 0; was--) {
            forn(s,0,10) {
                forn(tk,1,7-was) {
                    if(tk*num + s > 9) break;
                    ll w = scnk(cnt[num], tk);
                    a[was + tk][s + tk*num] = (a[was + tk][s + tk*num] + a[was][s]*w)%mod;
                }
            }
        }
    }
    cout<<ans*720%mod;
}