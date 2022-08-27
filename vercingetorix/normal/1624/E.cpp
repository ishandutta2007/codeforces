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

pi loc2[101];
pi loc3[1001];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char c[1005];
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        forn(i,0,101) loc2[i] = mp(-1, -1);
        forn(i,0,1001) loc3[i] = mp(-1, -1);
        forn(i,0,n) {
            scanf("%s", c);
            forn(j,1,m) {
                loc2[(c[j-1] - '0')*10+(c[j] - '0')] = mp(i, j);
                
            }
            forn(j,2,m) loc3[(c[j-2] - '0')*100 + (c[j-1] - '0')*10+(c[j] - '0')] = mp(i, j);
        }
        scanf("%s", c);
        
        int r = 0;
        const int INF = 1e9;
        vi p(m+1, -1);
        p[0] = 0;
        forn(i,0,m) if(p[i] != -1) {
            int c2 = 100;
            int c3 = 1000;
            if(i < m-1) c2 = (c[i]-'0')*10+(c[i+1]-'0');
            if(i < m-2) c3 = (c[i]-'0')*100+(c[i+1]-'0')*10+(c[i+2]-'0');
            if(loc2[c2].first != -1) p[i+2] = 2;
            if(loc3[c3].first != -1) p[i+3] = 3;
        }

        if(p[m] == -1) printf("-1\n");
        else {
            vi ansi;
            vpi anslr;
            int r = m;
            while(r > 0) {
                if(p[r] == 2) {
                    r -= 2;
                    int c2 = (c[r]-'0')*10+(c[r+1]-'0');
                    ansi.pb(loc2[c2].first);
                    anslr.pb(mp(loc2[c2].second , loc2[c2].second+1));
                }
                else {
                    r -= 3;
                    int c3 = (c[r]-'0')*100+(c[r+1]-'0')*10+(c[r+2]-'0');
                    ansi.pb(loc3[c3].first);
                    anslr.pb(mp(loc3[c3].second-1, loc3[c3].second+1));
                }
            }
            reverse(all(ansi));
            reverse(all(anslr));
            printf("%d\n", ansi.size());
            forn(i,0,ansi.size()) {
                printf("%d %d %d\n", anslr[i].first, anslr[i].second, ansi[i]+1);
            }
        }
    }
    
    
}