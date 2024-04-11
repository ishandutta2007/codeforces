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
    int ta;
    read(ta);
    char c[1000500];
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        vs a;
        forn(i,0,n) {
            scanf("%s", c);
            a.pb(string(c));
        }
        vvi d(n, vi(m,-1));
        int best = 0;
        pi ans(1,1);
        forn(i,0,n) forn(j,0,m) {
            if(d[i][j] != -1) continue;
            int x = i;
            int y = j;
            vpi ord;
            ord.pb(mp(x,y));
            d[x][y] = 0;
            while(1) {
                if(a[x][y] == 'U') x--;
                else if(a[x][y] == 'D') x++;
                else if(a[x][y] == 'L') y--;
                else if(a[x][y] == 'R') y++;
                if(x<0||x>=n||y<0||y>=m) {
                    int last = 0;
                    while(!ord.empty()) {
                        d[ord.back().first][ord.back().second] = ++last;
                        ord.pop_back();
                    }
                    break;
                }
                else if(d[x][y] != -1) {
                    if(d[x][y] == 0) {
                        int pt = 0;
                        while(ord[pt] != mp(x,y)) pt++;
                        int k = ord.size() - pt;
                        forn(ia,pt,ord.size()) d[ord[ia].first][ord[ia].second] = k;
                        int last = k;
                        ord.resize(pt);
                        while(!ord.empty()) {
                            d[ord.back().first][ord.back().second] = ++last;
                            ord.pop_back();
                        }
                        break;
                    }
                    else {
                        int last = d[x][y];
                        while(!ord.empty()) {
                            d[ord.back().first][ord.back().second] = ++last;
                            ord.pop_back();
                        }
                        break;
                    }
                }
                else {
                    d[x][y] = 0;
                    ord.pb(mp(x,y));
                }
            }
        }
        forn(i,0,n) {
            
        forn(j,0,m) {
//            printf("%d ", d[i][j]);
            if(d[i][j] > best) {
                best = d[i][j];
                ans = mp(i+1, j+1);
            }
        }
//            printf("\n");
        }
        printf("%d %d %d\n", ans.first, ans.second, best);
    }
    
    
}