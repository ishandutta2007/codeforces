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
const int A = 201;
int lcnt[A][A];
int rcnt[A][A];
int ptl[A];
int ptr[A];

int e[5100];
int taken[5100];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    vvi gl(n), gr(m);
    vi u(k), v(k);
    forn(i,0,k) {
        cin>>u[i]>>v[i];
        --u[i]; --v[i];
        gl[u[i]].pb(i);
        gr[v[i]].pb(i);
    }
    vi col(k);
    forn(i,0,n) forn(j,0,gl[i].size()) col[gl[i][j]] = j%t;
    forn(i,0,n) for(auto x : gl[i]) lcnt[i][col[x]] ++;
    forn(i,0,m) for(auto x : gr[i]) rcnt[i][col[x]] ++;
    vi ord;
    forn(i,0,m) ord.pb(i);
    shuffle(all(ord), gen);
    for(auto r : ord) {
        while(1) {
            int cx = 0, cn = 0;
            forn(i,0,t) {
                if(rcnt[r][i] > rcnt[r][cx]) cx= i;
                if(rcnt[r][i] < rcnt[r][cn]) cn= i;
            }
            if(rcnt[r][cx] - rcnt[r][cn] <= 1) break;
            int sd = 1;
            int cur = r;
            int pt = 0;
            forn(i,0,n) ptl[i] = 0;
            forn(i,0,m) ptr[i] = 0;
            while(1) {
                if(sd == 1) {
                    if(rcnt[cur][cn] > rcnt[cur][cx]) break;
                    while(col[gr[cur][ptr[cur]]] != cx || taken[gr[cur][ptr[cur]]]) ptr[cur]++;
                    int eind = gr[cur][ptr[cur]++];
                    e[pt++] = eind;
                    sd = 0;
                    cur = u[eind];
                    taken[eind] = 1;
                }
                else {
                    if(lcnt[cur][cx] > lcnt[cur][cn]) break;
                    while(col[gl[cur][ptl[cur]]] != cn || taken[gl[cur][ptl[cur]]]) ptl[cur]++;
                    int eind = gl[cur][ptl[cur]++];
                    e[pt++] = eind;
                    sd = 1;
                    cur = v[eind];
                    taken[eind] = 1;
                }
            }
            rcnt[r][cx]--;
            rcnt[r][cn]++;
            if(sd == 0) {
                lcnt[cur][cx]--;
                lcnt[cur][cn]++;
            }
            else {
                rcnt[cur][cx]++;
                rcnt[cur][cn]--;
            }
            forn(i,0,pt) {
                taken[e[i]] = 0;
                col[e[i]] = cn+cx-col[e[i]];
            }
        }
    }
    int ans = 0;
    forn(i,0,n) ans += (gl[i].size()%t > 0);
    forn(i,0,m) ans += (gr[i].size()%t > 0);
    cout<<ans<<'\n';
    forn(i,0,k) cout<<col[i]+1<<' ';
    cout<<'\n';
}