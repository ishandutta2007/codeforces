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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    char cc[100500];
    vi nd(100500,0);
    string chickens;
    forn(i,0,10) chickens.pb(char('0'+i));
    forn(i,0,26) chickens.pb(char('a'+i));
    forn(i,0,26) chickens.pb(char('A'+i));
    forn(ifa,0,t) {
        int r,c,k;
        scanf("%d %d %d", &r, &c, &k);
        vs a;
        int cnt = 0;
        forn(i,0,r) {
            scanf("%s", cc);
            a.pb(string(cc));
            forn(j,0,c) {
                if(a[i][j] == 'R') cnt++;
            }
        }
        nd[cnt/k + 1] = cnt%k;
        nd[cnt/k] = k - cnt%k;
        vpi ord;
        forn(i,0,r) {
            if(i%2==0) forn(j,0,c) ord.pb(mp(i,j));
            else for(int j = c-1; j>=0; j--) ord.pb(mp(i,j));
        }
        vs ans(r, string(c, chickens[k-1]));
        int pt = 0;
        int cur = 0;
        for(auto x: ord) {
            if(a[x.first][x.second] == 'R') cur++;
            ans[x.first][x.second] = chickens[pt];
            if(nd[cur] > 0) {
                
                nd[cur]--;
                cur = 0;
                pt++;
                if(pt==k) break;
            }
        }
        nd[cnt/k] = 0;
        nd[cnt/k+1] = 0;
        forn(i,0,r)printf("%s\n", ans[i].c_str());
        
    }
    
    
}