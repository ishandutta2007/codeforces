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

vi p;
ll mx = 1e5;
ll cur = 1;
ll ans = 0;

void go(int pos) {
    if(pos == p.size()) {
        ans++;
        return;
    }
    ll cwas = cur;
    forn(d,0,100) {
        go(pos+1);
        cur*=p[pos];
        if(cur > mx) {
            cur = cwas;
            return;
        }
    }
}

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ll deg[1000500][12];
ll dp[12][30];
ll ov[1000500];
int cobb[1000500];

int lb[1<<12];
ll xt[1<<12];
const ll INF = 1e18;
ll d[2][13][1<<12];
vi agm[1<<12];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(mask,1,1<<12) {
        int bit = 0;
        while((mask&(1<<bit)) == 0) bit++;
        lb[mask] = bit;
    }
//    p = {2,3,5,7,11,13,17,19,23,29,31,37};
//    cout<<2ll*3*5*7*11*13*17*19*23*29*31;
//
//    go(0);
//    cout<<ans;
//    exit(0);
    ll n,k;
    scanf("%lld %lld", &n, &k);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    readv(e,n);
    vpll ea;
    forn(i,0,n) ea.pb(mp(e[i], a[i]));
    srt(ea);
    forn(i,0,n) {
        a[i] = ea[i].second;
        e[i] = ea[i].first;
    }
    ll gd = 0;
    forn(i,0,n) gd = gcd(a[i], gd);
    vpll q;
    ll m = gd;
    for(ll i = 2; i*i <= m; i++) {
        if(m%i == 0) {
            q.pb(mp(i,1));
            m/=i;
            while(m%i == 0) {
                q.back().second++;
                m/=i;
            }
        }
    }
    if(m!=1) q.pb(mp(m,1));
    forn(i,0,q.size()) {
        dp[i][0] = 1;
        dp[i][1] = q[i].first;
        forn(l,2,30) dp[i][l] = dp[i][l-1]*q[i].first;
    }
    forn(i,0,n) {
        a[i] /= gd;
        ov[i] = 1;
        forn(j,0,q.size()) {
            deg[i][j] = dp[j][q[j].second];
            int cd = 0;
            while(a[i] % q[j].first == 0) {
                cd++;
                deg[i][j] *= q[j].first;
                a[i] /= q[j].first;
            }
            ov[i] *= dp[j][cd];
        }
    }
    vi tk(n, 0);
    ll b = k/gd;
    int l = q.size();
    if(q.size() <= 8) {
        vi taken(1<<l, 0);
        forn(i,0,n) {
            xt[0] = 1;
            forn(mask,1,1<<l) {
                xt[mask] = xt[mask^(1<<lb[mask])]*deg[i][lb[mask]];
                if(xt[mask] <= k) {
                    taken[mask]++;
                    if(taken[mask] <= l) tk[i] = 1;
                }
            }
        }
    }
    else {
//        set<ll> ovs;
//        forn(i,0,n) ovs.insert(ov[i]);
        forn(i,0,n) {
            cobb[ov[i]]++;
            if(cobb[ov[i]] <= q.size()) {
//                for(auto x : )
                tk[i] = 1;
            }
        }
    }
    forn(i,0,13) forn(j,0,1<<12) d[0][i][j] = INF;
    d[0][0][0] = 0;
    int ldi = 0;
    forn(mask, 1, 1<<l) {
        forn(m2, 0, 1<<l) {
            if((mask&m2)==0) agm[mask].pb(m2);
        }
    }
    forn(i,0,n) {
        if(tk[i] == 0) continue;
        int ndi = 1-ldi;
        forn(ik,0,13) forn(j,0,1<<12) d[ndi][ik][j] = d[ldi][ik][j];
        xt[0] = 1;
        forn(mask,1,1<<l) {
            xt[mask] = xt[mask^(1<<lb[mask])]*deg[i][lb[mask]];
            if(xt[mask] <= k) {
                for(auto m2 : agm[mask]) {
                    forn(up,0,l) {
                        if(d[ldi][up][m2] == INF) continue;
                        d[ndi][up+1][m2|mask] = min(d[ndi][up+1][m2|mask], d[ldi][up][m2] + e[i]);
                    }
                }
            }
        }
        ldi = ndi;
    }
    ll ans = INF;
    forn(up,0,l+1) if(d[ldi][up][(1<<l)-1] < INF) ans = min(ans, up*d[ldi][up][(1<<l)-1]);
    if(ans == INF) ans = -1;
    cout<<ans;
}