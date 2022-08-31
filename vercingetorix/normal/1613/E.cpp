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
vs a;
int n,m;
bool good(int i, int j) {
    if(i>=0 && i < n && j>=0 && j<m && a[i][j] != '#') return true;
    else return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char c[1000500];
    vpi dir;
    dir.pb(mp(-1,0));
    dir.pb(mp(1,0));
    dir.pb(mp(0, 1));
    dir.pb(mp(0, -1));
    forn(ifa,0,ta) {
        a.clear();
        scanf("%d %d\n", &n, &m);
        
        forn(i,0,n) {
            scanf("%s", c);
            a.pb(string(c));
        }
        int x,y;
        vvi bn(n, vi(m,0));
        vvi gn(n, vi(m,0));
        vvi done(n, vi(m,0));
        forn(i,0,n) forn(j,0,m) {
            for(auto x : dir) {
                int i1 = i + x.first;
                int j1 = j + x.second;
                if(good(i1,j1)) bn[i][j]++;
            }
        }
        forn(i,0,n) forn(j,0,m) if(a[i][j] == 'L') {
            x = i; y = j;
        }
        vpi q;
        q.pb(mp(x,y));
        done[x][y] = 1;
        while(!q.empty()) {
            int i = q.back().first;
            int j = q.back().second;
            q.pop_back();
            for(auto x : dir) {
                int i1 = i + x.first;
                int j1 = j + x.second;
                if(good(i1,j1)) {
                    if(done[i1][j1]) continue;
                    bn[i1][j1]--;
                    if(bn[i1][j1] <= 1) {
                        q.pb(mp(i1,j1));
                        done[i1][j1] = 1;
                    }
                }
            }
        }
        forn(i,0,n) forn(j,0,m) if(a[i][j] == '.' && done[i][j]) a[i][j] ='+';
        forn(i,0,n) printf("%s\n", a[i].c_str());
        
    }
    
    
}