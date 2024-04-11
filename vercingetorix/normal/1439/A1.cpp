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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    char c[2010];
    while(t--) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        vs a;
        forn(i,0,n) {
            scanf("%s", c);
            a.pb(string(c));
        }
        vvi ans;
        while(m > 2) {
            forn(i,0,n) {
                if(a[i][m-1] == '1') {
                    if(i<n-1) ans.pb(vi({i+1,m-1,i+1,m,i+2,m-1}));
                    else ans.pb(vi({i+1,m-1,i+1,m,i,m-1}));
                    forn(j,0,6) {
                        if(j%2==0) {
                            int x = ans.back()[j]-1;
                            int y = ans.back()[j+1]-1;
                            if(a[x][y] == '1' ) a[x][y] = '0';
                            else a[x][y] = '1';
                        }
                    }
                }
            }
            m--;
        }
        while(n > 2) {
            forn(j,0,m) {
                if(a[n-1][j] == '1') {
                    if(j<m-1) ans.pb(vi({n-1,j+1,n,j+1,n-1,j+2}));
                    else ans.pb(vi({n-1,j+1,n,j+1,n-1,j}));
                    forn(i,0,6) {
                        if(i%2==0) {
                            int x = ans.back()[i]-1;
                            int y = ans.back()[i+1]-1;
                            if(a[x][y] == '1' ) a[x][y] = '0';
                            else a[x][y] = '1';
                        }
                    }
                }
            }
            n--;
        }
        vpi z, o;
        forn(i,0,2) forn(j,0,2)  {
            if(a[i][j] =='1') o.pb(mp(i,j));
            else z.pb(mp(i,j));
        }
        if(o.size() == 3) {
            vi to;
            for(auto x:o ) {
                to.pb(x.first+1);
                to.pb(x.second+1);
            }
            ans.pb(to);
        }
        else if(o.size() == 4) {
            forn(i,0,4) {
                vi to;
                forn(j,0,4) {
                    if(j==i) continue;
                    auto x = o[j];
                    to.pb(x.first+1);
                    to.pb(x.second+1);
                }
                ans.pb(to);
            }
        }
        else if(o.size() == 1) {
            forn(i,0,3) {
                vi to;
                to.pb(o[0].first+1);
                to.pb(o[0].second+1);
                forn(j,0,3) {
                    if(j==i) continue;
                    auto x = z[j];
                    to.pb(x.first+1);
                    to.pb(x.second+1);
                }
                ans.pb(to);
            }
        }
        else if(o.size() == 2) {
            forn(i,0,2) {
                vi to;
                to.pb(z[0].first+1);
                to.pb(z[0].second+1);
                to.pb(z[1].first+1);
                to.pb(z[1].second+1);
                to.pb(o[i].first+1);
                to.pb(o[i].second+1);
                ans.pb(to);
            }
        }
        printf("%d\n", ans.size());
        for(auto x : ans) {
            forn(i,0,5) printf("%d ", x[i]);
            printf("%d\n", x[5]);
        }
    }
    
}