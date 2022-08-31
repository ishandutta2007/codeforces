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
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d", &n, &m);
        readv(a, n);
        readv(b, n);
        vi l(m), r(m);
        vvi ind(n+1);
        forn(i,0,m) {
            scanf("%d %d", &l[i], &r[i]);
            l[i]--;
            r[i]--;
            ind[l[i]].pb(i);
            ind[r[i] + 1].pb(i);
        }
        vi cnt(m,0);
        set<int> nz;
        ll dif = 0;
        vi pp(1,0);
        vi sp;
        forn(i,0,n) {
            dif += a[i] - b[i];
            if(dif == 0) pp.pb(i+1);
            else nz.insert(i+1);
        }
        while(!pp.empty() || !sp.empty()) {
            while(!pp.empty()) {
                int p = pp.back();
                pp.pop_back();
                for(auto i : ind[p]) {
                    cnt[i]++;
                    if(cnt[i] == 2) sp.pb(i);
                }
            }
            while(!sp.empty()) {
                int i = sp.back();
                sp.pop_back();
                auto it = nz.lower_bound(l[i]);
                vi todel;
                while(it != nz.end() && *it < r[i] + 1) {
                    todel.pb(*it);
                    pp.pb(*it);
                    it++;
                }
                for(auto x : todel) nz.erase(x);
            }
        }
        if(nz.empty()) printf("YES\n");
        else printf("NO\n");
    }
    
    
}