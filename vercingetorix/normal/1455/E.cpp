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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    vvi ords;
    vi qq = {0,1,2,3};
    do {
        ords.pb(qq);
    } while(next_permutation(all(qq)));
    forn(ifa,0,ta) {
        vi x(4), y(4);
        forn(i,0,4) scanf("%d %d", &x[i], &y[i]);
        ll ans = 0;
        auto upd = [&] (pi a, pi b) {
            vpi ord;
            for(auto p : {a.first, b.first}) for(auto q : {a.second, b.second}) ord.pb(mp(p,q));
//            srt(ord);
            for(auto & ind : ords) {
                ll cand = 0;
                forn(i,0,4) cand += ll(abs(ord[i].first-x[ind[i]])) + abs(ord[i].second - y[ind[i]]);
                ans = min(ans, cand);
            }
            
//            do {
//                ll cand = 0;
//                forn(i,0,4) cand += ll(abs(ord[i].first-x[i])) + abs(ord[i].second - y[i]);
//                ans = min(ans, cand);
//            } while(next_permutation(all(ord)));
        };
        vi x2 = x;
        vi y2 = x;
        srt(x2);
        srt(y2);
        forn(i,0,4) {
            ans += ll(abs(x[i] - x2[1]) + abs(y[i] - y2[1]));
        }
        forn(i,0,4) forn(j1,0,4) forn(j2,j1+1,4) {
            int l = abs(y[j1]-y[j2]);
            upd(mp(x[i], y[j1]), mp(x[i]+l, y[j2]));
            upd(mp(x[i], y[j1]), mp(x[i]-l, y[j2]));
        }
        forn(i,0,4) swap(x[i],y[i]);
        forn(i,0,4) forn(j1,0,4) forn(j2,j1+1,4) {
            int l = abs(y[j1]-y[j2]);
            upd(mp(x[i], y[j1]), mp(x[i]+l, y[j2]));
            upd(mp(x[i], y[j1]), mp(x[i]-l, y[j2]));
        }
//        forn(i,0,4) forn(j,0,4) {
//            int a = x[i];
//            int b = y[j];
//            vi sd;
//            forn(i1,0,4) if(i1!=i) sd.pb(abs(x[i1]-x[i]));
//            forn(i1,0,4) if(i1!=j) sd.pb(abs(y[i1]-y[j]));
//            srt(sd);
//            forn(i,0,sd.size()) if(i==0 || sd[i] != sd[i-1]){
//                int l = sd[i];
//                upd(mp(a,b), mp(a+l, b+l));
//                if(l!=0) {
//                    upd(mp(a,b), mp(a+l, b-l));
//                    upd(mp(a,b), mp(a-l, b+l));
//                    upd(mp(a,b), mp(a-l, b-l));
//                }
//            }
//        }
        printf("%lld\n", ans);
    }
    
    
}