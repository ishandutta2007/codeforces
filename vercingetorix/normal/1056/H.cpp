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

const int A = 300500;
const int B = 550;

vpi nx[A];
vi route[A];
const int INF = 1e9;
int pos[A];
pi pbad[A];
int to[A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        forn(i,0,n) pos[i] = -1;
        forn(i,0,n) to[i] = -1;
        int q;
        scanf("%d", &q);
        forn(ti,0,q) {
            int k;
            read(k);
            readv(a,k);
            forn(i,0,k) a[i]--;
            route[ti] = a;
            if(k < B)
                forn(i,0,k-1) forn(j,i+1,k) nx[a[i]].pb(mp(a[j], a[i+1]));
        }
        
        int robot = 1;
        forn(i,0,n) {
            for(auto x : nx[i]) {
                if(to[x.first] != -1 && to[x.first] != x.second) {
                    robot = 0;
                    break;
                }
                to[x.first] = x.second;
            }
            for(auto x : nx[i]) to[x.first] = -1;
            nx[i].clear();
        }
        if(robot)
        forn(v,0,q) {
            if(route[v].size() >= B) {
                forn(i,0,route[v].size()) pos[route[v][i]] = i;
                forn(u,0,q) {
                    if(u==v) continue;
                    int l = 0;
                    forn(i,0,route[u].size()) {
                        if(pos[route[u][i]] != -1) {
                            pbad[l++] = mp(i, pos[route[u][i]]);
                        }
                    }
                    forn(i,1,l) {
                        if(pbad[i].second > pbad[i-1].second) {
                            if(pbad[i].second - 1 != pbad[i-1].second || pbad[i].first - 1 != pbad[i-1].first) {
                                robot = 0;
                                break;
                            }
                        }
                    }
                    if(robot == 0) break;
                }
                forn(i,0,route[v].size()) pos[route[v][i]] = -1;
                if(robot == 0) break;
            }
        }
        if(robot) printf("Robot\n");
        else printf("Human\n");
        forn(i,0,q) route[i].clear();
    }
    
    
}