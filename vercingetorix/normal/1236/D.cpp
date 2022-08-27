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
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    vector<set<int>> row(n);
    vector<set<int>> col(m);
    int x = 0;
    int y = 0;
    forn(i,0,n) row[i].insert(m);
    forn(i,0,n) row[i].insert(-1);
    forn(i,0,m) col[i].insert(n);
    forn(i,0,m) col[i].insert(-1);
    ll ans = k+1;
    forn(i,0,k) {
        int px,py;
        scanf("%d %d", &px, &py);
        px--;
        py--;
        row[px].insert(py);
        col[py].insert(px);
    }
    int u = 0, r = m, d = n, l = -1;
    int po = 0;
    while(1) {
        int ny = min(*row[x].upper_bound(y), r);
        if (ny == y+1 and x+y!=0) break;
        ans += ny-y-1;
        r = ny - 1;
        y = ny-1;
//        printf("%d %d\n", x, y);
        int nx = min(*col[y].upper_bound(x), d);
        if (nx == x+1) break;
        ans += nx-x-1;
        d = nx-1;
        x = nx-1;
//        printf("%d %d\n", x, y);
        ny = max(*(--row[x].lower_bound(y)), l);
        if (ny == y-1) break;
        ans += y-ny-1;
        l = ny+1;
        y = ny+1;
//        printf("%d %d\n", x, y);
        nx = max(*(--col[y].lower_bound(x)), u);
        if (nx == x-1) break;
        ans += x-nx-1;
        u = nx+1;
        x = nx+1;
//        printf("%d %d\n", x, y);
//        po++;
//        if(po>100) break;
    }
    if (ans == ll(n)*ll(m)) cout<<"Yes";
    else cout<<"No";
}