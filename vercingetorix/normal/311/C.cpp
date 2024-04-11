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
typedef vector<vpll> vvpll;

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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll h;
    int n,m,k;
    scanf("%lld %d %d %d", &h, &n, &m, &k);
    vvpll tr(k);
    vll xc(n);
    vi c(n);
    forn(i,0,n) {
        scanf("%lld %d", &xc[i], &c[i]);
        xc[i]--;
        tr[xc[i]%k].pb(mp(xc[i], i));
    }
    forn(i,0,k) srt(tr[i]);
    vi pt(k);
    forn(i,0,k) pt[i] = ((int)tr[i].size()) - 1;
    vll mn(k, h+1);
    mn[0] = 0;
    set<pll> reach;
    for(auto x : tr[0]) reach.insert(mp(c[x.second], -x.second));
    pt[0] = -1;
    auto can = [&](int ind) {
        return mn[xc[ind]%k] <= xc[ind];
    };
    vi vis(k,0);
    while(m--) {
        int tp;
        scanf("%d", &tp);
        if(tp == 3) {
            if(reach.empty()) printf("0\n");
            else {
                auto it = prev(reach.end());
                printf("%d\n", c[-it->second]);
                reach.erase(it);
            }
        }
        else if(tp == 2) {
            int i, y;
            scanf("%d %d", &i, &y);
            i--;
            if(can(i)) {
                reach.erase(mp(c[i], -i));
                c[i] -= y;
                reach.insert(mp(c[i], -i));
            }
            else c[i] -= y;
        }
        else {
            ll step;
            scanf("%lld", &step);
            int d = step%k;
            forn(i,0,k) vis[i] = 0;
            forn(s,0,k) if(vis[s] == 0) {
                int cur = s;
                int cntvis = 0;
                while(cntvis < 2) {
                    int nx = cur+d;
                    if(nx >= k) nx-=k;
                    if(mn[nx] > mn[cur] + step) {
                        mn[nx] = mn[cur] + step;
                        while(pt[nx] >= 0 && tr[nx][pt[nx]].first >= mn[nx]) {
                            int ind = tr[nx][pt[nx]--].second;
                            reach.insert(mp(c[ind], -ind));
                        }
                    }
                    cur = nx;
                    vis[cur] = 1;
                    if(cur == s) cntvis++;
                }
            }
        }
    }
    
    
}