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
int best[101];
vector<pair<int, pi>> p[101];
const int INF = 1e9+1e5;
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
        readv(a,n);
        vector<vector<pair<pi, int>>> s(n);
        vi ft;
        forn(i,0,m) {
            int e,t,p;
            scanf("%d %d %d", &e, &t, &p);
            s[e-1].pb(mp(mp(t,p), i));
            ft.pb(t);
        }
        vi need;
        vi ans;
        int can = 1;
        int tot = 0;
        forn(it,0,n) {
            forn(j,1,101) best[j] = INF;
            forn(j,1,101) p[j].clear();
            for(auto x : s[it]) {
                int t= x.first.first;
                int ind = x.second;
                int add = x.first.second;
                for(int was = 99; was>=0; was--) {
                    int now = min(100, was+add);
                    if(best[now] > best[was] + t) {
                        best[now] = best[was] +t;
                        p[now].pb(mp(best[now], mp(was, ind)));
                    }
                }
            }
            tot += best[100];
            if(tot > a[it]) {
                can = 0;
                break;
            }
            int cur = 100;
            int tneed = best[100];
            while(cur != 0) {
                while(p[cur].back().first != tneed) p[cur].pop_back();
                int ind = p[cur].back().second.second;
                ans.pb(ind+1);
                tneed -= ft[ind];
                cur = p[cur].back().second.first;
            }
        }
//        cout<<can<<'\n';
        if(can) {
            printf("%d\n", ans.size());
            for(auto x : ans) printf("%d ", x); printf("\n");
        }
        else printf("-1\n");
    }
    
    
}