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

int d[10][10][10][2000];

int dif(int from, int to, vi & drop) {
    int ret = abs(to-from);
    if(to < from) swap(to, from);
    for(auto x : drop) {
        if(x > to) {
            ret += 2*(x-to);
            to = x;
        }
        else if(x<from) {
            ret += 2*(from-x);
            from = x;
        }
    }
    return ret;
}

int stop(int from, vi & drop) {
    int mx = from;
    int mn = from;
    for(auto x : drop) mx = max(mx, x);
    for(auto x : drop) mn = min(mn, x);
    return mx-mn+min(mx-from, from-mn);
}

const int INF = 1e9;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vi a(n), b(n);
    forn(i,0,n) scanf("%d %d", &a[i], &b[i]);
    forn(x,0,10) forn(y,0,10) forn(z,0,10) {
        if(x > y || y > z) continue;
        forn(u,0,n) d[x][y][z][u] = INF;
        vi drop;
        if(x!=0) drop.pb(x);
        if(y!=0) drop.pb(y);
        if(z!=0) drop.pb(z);
        drop.pb(b[n-1]);
        d[x][y][z][n-1] = stop(a[n-1], drop);
    }
    for(int pick = n-2; pick >= 0; pick --) {
        forn(x,0,10) forn(y,0,10) forn(z,0,10) {
            if(x > y || y > z) continue;
            vi drop;
            if(x!=0) drop.pb(x);
            if(y!=0) drop.pb(y);
            if(z!=0) drop.pb(z);
            drop.pb(b[pick]);
//            d[x][y][z][n-1] = stop(a[n-1], drop);
            
            forn(mask,0,1<<drop.size()) {
                vi kick;
                vi left;
                forn(bit,0,drop.size()) if(mask & (1<<bit)) kick.pb(drop[bit]);
                else left.pb(drop[bit]);
                if(left.size() == 4) continue;
                while(left.size() < 3) left.pb(0);
                srt(left);
                d[x][y][z][pick] = min(d[x][y][z][pick], d[left[0]][left[1]][left[2]][pick + 1] + dif(a[pick], a[pick+1], kick));
            }
        }
    }
    cout<<d[0][0][0][0] + abs(1-a[0]) + 2*n;
    
    
}