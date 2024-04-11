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
int n,m;
vs a;
const int INF = 1e9;
pi best;
int num[21];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char c[10500];
    forn(ifa,0,ta) {
        a.clear();
        scanf("%d %d", &n, &m);
        readv(x,n);
        forn(i,0,n) {
            scanf("\n%s", c);
            a.pb(string(c));
        }
        best = mp(-INF, 0);
        forn(mask,0,1<<n) {
            int cand = 0;
            vi sg;
            int mm = mask;
            forn(i,0,n) {
                sg.pb((mm%2)*2-1);
                mm/=2;
            }
            forn(i,0,n) cand -= sg[i]*x[i];
            forn(j,0,m) {
                int cur = 0;
                forn(i,0,n) {
                    if(a[i][j] == '1') cur+=sg[i];
                }
                num[cur+10]++;
            }
            int val = 1;
            for(int it = -n; it<=n; it++) {
                forn(affa,0,num[it+10]) cand += it*(val++);
                num[it+10] = 0;
                    
            }
            best = max(best, mp(cand, mask));
        }
        
        vi sg;
        int mm = best.second;
        forn(i,0,n) {
            sg.pb((mm%2)*2-1);
            mm/=2;
        }
        vpi lol;
        forn(j,0,m) {
            int cur = 0;
            forn(i,0,n) {
                if(a[i][j] == '1') cur+=sg[i];
            }
            lol.pb(mp(cur, j));
        }
        srt(lol);
        vi ans(m);
        forn(i,1,m+1) {
            ans[lol[i-1].second] = i;
        }
        for(auto x : ans) printf("%d ", x);
        printf("\n");
    }
    
    
}