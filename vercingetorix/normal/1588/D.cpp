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

vi pos[10][52];

int toy(char c) {
    if(c>='a' && c<='z') return c-'a';
    else return int(c-'A')+26;
}

int d[115][512];
pi p[115][512];
int n;
pi getmask(vi & cpos, int nc) {
    vi npos;
    pi ret(-1, 0);
    forn(i,0,n) {
        int f = -1;
        if(pos[i][nc].size() >= 1 && pos[i][nc][0] > cpos[i]) f = 0;
        else if(pos[i][nc].size() >= 2 && pos[i][nc][1] > cpos[i]) f = 1;
        if(f == -1) return mp(-1,-1);
//        npos.pb()
        if(i == 0) ret.first = pos[i][nc][f];
        else ret.second |= (f*(1<<(i-1)));
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char c[10004];
    forn(ifa,0,ta) {
        forn(i,0,10) forn(j,0,52) pos[i][j].clear();
        forn(i,0,115) forn(j,0,512) d[i][j] = 0;
        forn(i,0,115) forn(j,0,512) p[i][j] = mp(-1,-1);
        
        scanf("%d\n", &n);
        vs a;
        forn(at,0,n) {
            scanf("%s", c);
            string s (c);
            a.pb(s);
            forn(i,0,s.size()) pos[at][toy(s[i])].pb(i);
        }
        vi inpos(n,-1);
        forn(nc,0,52) {
            auto to = getmask(inpos, nc);
            if(to.first != -1) {
                d[to.first][to.second] = 1;
            }
        }
        forn(st,0,a[0].size()) {
            forn(mask,0,1<<(n-1)) {
                vi cpos;
                cpos.pb(st);
                int good = 1;
                int curc = toy(a[0][st]);
                forn(i,1,n) {
                    int bit = 0;
                    if(mask & (1<<(i-1))) bit = 1;
                    if(pos[i][curc].size() <= bit) {
                        good = 0;
                        break;
                    }
                    cpos.pb(pos[i][curc][bit]);
                }
                if(good == 0) continue;
                forn(nc,0,52) {
                    auto to = getmask(cpos, nc);
                    if(to.first != -1) {
                        if(d[st][mask] >= d[to.first][to.second]) {
                            d[to.first][to.second] = d[st][mask] + 1;
                            p[to.first][to.second] = mp(st, mask);
                        }
                    }
                }
            }
        }
        pi best(-1,-1);
        int val = 0;
        forn(st,0,a[0].size()) forn(mask,0,(1<<(n-1))){
            if(d[st][mask] > val) {
                best = mp(st, mask);
                val = d[st][mask];
            }
        }
        string ans;
        while(best != mp(-1,-1)) {
            ans.pb(a[0][best.first]);
            best = p[best.first][best.second];
            
        }
        reverse(all(ans));
        printf("%d\n", val);
        printf("%s\n", ans.c_str());
    }
    
    
}