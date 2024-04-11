#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
vvi a,b;

int n, s, days;
vi imp;
int lead[30];
int vc[30];
void gauss() {
    forn(i,0,s) {
        forn(j,0,n) if(a[i][j]) {
            lead[i] = j;
            imp.pb(i);
            forn(i1,0,s) if(i!=i1) if(a[i1][j]) {
                forn(k,0,n) a[i1][k] ^= a[i][k];
                vc[i1] ^= vc[i];
            }
            break;
        }
    }
}
const int N = 1000;
int d[N];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d %d", &n, &s, &days);
    forn(i,0,s) vc[i] = 1<<i;
    forn(i,0,s) {
        lead[i] = -1;
        int k;
        scanf("%d", &k);
        a.pb(vi(n,0));
        int x;
        forn(j,0,k) {
            scanf("%d", &x);
            x--;
            a.back()[x] = 1;
        }
    }
//    b = a;
    gauss();
    if((int)imp.size() < 15) {
        int N = 1<<imp.size();
        vi e;
        forn(i,0,s) {
            if(lead[i] == -1) {
                int mask = 0;
                forn(j,0,imp.size()) if(vc[i] & (1<<imp[j])) mask |= 1<<j;
                e.pb(mask);
            }
        }
        forn(i,0,imp.size()) e.pb(1<<i);
        vector<int> dist (N, 100);
        dist[0] = 0;
        priority_queue < pair<int,int> > q;
        q.push (make_pair (0, 0));
        while (!q.empty()) {
            int v = q.top().second,  cur_d = -q.top().first;
            q.pop();
            if (cur_d > dist[v])  continue;
            
            for(auto st : e) {
                int to = v ^ st;
                if (dist[v] + 1 < dist[to]) {
                    dist[to] = dist[v] + 1;
                    q.push (make_pair (-dist[to], to));
                }
            }
        }
        forn(afj,0,days) {
            forn(i,0,n) d[i] = 0;
            int k;
            scanf("%d", &k);
            int x;
            forn(i,0,k) {
                scanf("%d", &x);
                x--;
                d[x] = 1;
            }
//            int mask = 0;
//            forn(i,0,imp.size()) if(d[lead[imp[i]]]) {
//                mask |= 1<<i;
//                forn(j,0,n) d[j] ^= a[imp[i]][j];
//            }
            int cur = 0;
            forn(i,0,s) if(lead[i] != -1) if(d[lead[i]] == 1) {
                cur ^= vc[i];
                forn(j,0,n) d[j] ^= a[i][j];
            }
            int mask = 0;
            forn(j,0,imp.size()) if(cur & (1<<imp[j])) {
                mask|=1<<j;
            }
            int can = 1;
            forn(i,0,n) if(d[i] != 0) can = 0;
            if(can == 0) printf("-1\n");
            else {
                printf("%d\n", dist[mask]);
            }
        }
    }
    else {
        vi v;
        forn(i,0,s) if(lead[i] == -1) {
//            int cur = 1<<i;
//            forn(j,0,s) if(lead[j] != -1 && a[i][lead[j]]) cur ^= (1<<i);
//            v.pb(cur);
            v.pb(vc[i]);
        }
        vi f;
        forn(mask,0,1<<v.size()) {
            int val=0;
            forn(bit,0,v.size()) if(mask & (1<<bit)) val ^= v[bit];
            f.pb(val);
        }
        forn(afj,0,days) {
            forn(i,0,n) d[i] = 0;
            int k;
            scanf("%d", &k);
            int x;
            forn(i,0,k) {
                scanf("%d", &x);
                x--;
                d[x] = 1;
            }
            int cur = 0;
            forn(i,0,s) if(lead[i] != -1) if(d[lead[i]] == 1) {
                cur ^= vc[i];
                forn(j,0,n) d[j] ^= a[i][j];
            }
            int can = 1;
            forn(i,0,n) if(d[i] != 0) can = 0;
            if(can == 0) printf("-1\n");
            else {
                int ans = 30;
                for(auto cand : f) ans = min(ans, __builtin_popcount(cand^cur));
                printf("%d\n", ans);
            }
        }
    }
    
    
}