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

ll cnt[2][2];

ll c2(ll l) {
    return l*(l-1);
}

ll c3(ll l) {
    if(l < 3) return 0;
    return l*(l-1)%mod*(l-2)%mod;
}

vpi get(int x, int w) {
    int lx = 1 + w/x;
    int bx = 1 + w%x;
    return {mp(lx, bx), mp(lx-1, x-bx)};
}

ll s32(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

ll s32(pi x, pi y, pi z) {
    return s32(x.first, x.second, y.first, y.second, z.first, z.second);
}

int brut(int w, int h) {
    vpi q;
    forn(i,0,w+1) forn(j,0,h+1) q.pb(mp(i,j));
    int ans = 0;
    forn(i,0,q.size()) forn(j,i+1,q.size()) forn(k,j+1,q.size()) {
        ll cur = s32(q[i], q[j], q[k]);
        if(cur %2 ==0 && cur!= 0) ans+=6;
    }
    return ans;
}

const int A = 4010;
ll d[A][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(w,2,A) forn(h,w,A) {
        d[w][h] = (d[w][h-1] + ll(w-1)*(w)*(2*w-1)-3*ll(w)*(w-1))%mod;
        d[h][w] = d[w][h];
    }
    int w,h;
    cin>>w>>h;
    forn(i,0,w+1) forn(j,0,h+1) cnt[i%2][j%2]++;
    ll ans = 0;
    forn(i1,0,2) forn(j1,0,2) forn(i2,0,2) forn(j2,0,2) if(i1!=i2 || j1 != j2) {
        ans += 3*(cnt[i1][j1])*(cnt[i1][j1]-1)%mod*cnt[i2][j2];
        ans%=mod;
    }
    forn(i1,0,2) forn(j1,0,2) {
        ans = (ans + (cnt[i1][j1])*(cnt[i1][j1]-1)%mod*(cnt[i1][j1]-2))%mod;
    }
    ans = (ans + 2*mod - (w+1)*c3(h+1)%mod - (h+1)*c3(w+1)%mod)%mod;
    forn(x,1,w/2+1) {
        auto a = get(x,w);
        forn(y,1,h/2+1) if(gcd(x,y) == 1) {
            auto b = get(y,h);
            for(auto p : a) for(auto q : b) {
                int num = p.second*q.second;
//                int len = min(p.first, q.first);
//                ans = (ans + mod - num*c3(len)%mod)%mod;
//                if(num > 0 && d[p.first][q.first] > 0) {
//                    cout<<x<<' '<<y<<' '<<p.first<<' '<<p.second<<' '<<q.first<<' '<<q.second<<'\n';
//                    cout<<num<<' '<<d[p.first][q.first]<<'\n';
//                }
                ans = (ans + mod - num*d[p.first][q.first]%mod)%mod;
            }
        }
    }
    cout<<ans<<'\n';
//    cout<<brut(w, h);
}