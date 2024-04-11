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
vvi a;
vvi ans;

int to(int i, int j) {
    return i*m + j + 1;
}

int to(pi p) {
    return p.first * m + p.second + 1;
}

int nextrow(int i) {
    if(i == n-1) return n-2;
    else return i+1;
}
int nextcol(int j) {
    if(j == m-1) return m-2;
    else return j+1;
}

void rot(const vpi & x) {
    ans.pb(vi());
    for(auto pp : x) ans.back().pb(a[pp.first][pp.second]);
    int mem = a[x.back().first][x.back().second];
    forn(i,0,x.size()) {
        swap(mem, a[x[i].first][x[i].second]);
    }
    
}

void mv(int x, int y, int k, int l) {
    if(y == m-1) {
        rot({mp(x,y), mp(x,y-1), mp(nextrow(x),y-1), mp(nextrow(x), y)});
        y--;
    }
    if(x == n-1) {
        rot({mp(x,y), mp(x-1,y), mp(x-1,nextcol(y)), mp(x,nextcol(y))});
        x--;
    }
    while(x<k) {
        rot({mp(x,y), mp(x+1,y), mp(x+1,y+1), mp(x,y+1)});
        x++;
    }
    while(y < l) {
        rot({mp(x,y), mp(x,y+1), mp(x+1,y+1), mp(x+1,y)});
        y++;
    }
    while(x > k) {
        rot({mp(x,y), mp(x-1,y), mp(x-1,y+1), mp(x,y+1)});
        x--;
    }
    while(y > l) {
        rot({mp(x,y), mp(x,y-1), mp(x+1,y-1), mp(x+1,y)});
        y--;
    }
}

void mv(pi xy, int k, int l) {
    mv(xy.first, xy.second, k, l);
}

pi locate(int num) {
    forn(i,0,n) {
        forn(j,0,m) {
            if(a[i][j] == num) {
                return mp(i,j);
            }
        }
    }
    return mp(-1,-1);
}

void place(int k, int l) {
    int num = to(k,l);
    auto xy = locate(num);
    int x = xy.first;
    int y = xy.second;
    mv(x,y,k,l);
}

void placerow(int k) {
    auto xy = locate(to(k,m-1));
    mv(xy, k, m-2);
    xy = locate(to(k,m-2));
    if(xy.first == k) {
        auto p1 = mp(k,m-2);
        auto p2 = mp(k,m-1);
        auto p3 = mp(k+1,m-2);
        auto p4 = mp(k+1,m-1);
        auto p5 = mp(k+2,m-2);
        auto p6 = mp(k+2,m-1);
        rot({p1,p2,p4,p3});
        rot({p4,p6,p5,p3});
        rot({p6,p4,p2,p1,p3,p5});
        rot({p4,p3,p5,p6});
        rot({p1,p2,p4,p3});
    }
    else {
        mv(xy,k+1,m-2);
        rot({mp(k,m-2), mp(k,m-1),mp(k+1,m-1),mp(k+1,m-2)});
    }
}

void placecol(int l) {
    auto xy = locate(to(n-1,l));
    mv(xy, n-2, l);
    xy = locate(to(n-2,l));
    if(xy.second == l) {
        auto p1 = mp(n-2, l);
        auto p2 = mp(n-1, l);
        auto p3 = mp(n-2, l+1);
        auto p4 = mp(n-1, l+1);
        auto p5 = mp(n-2, l+2);
        auto p6 = mp(n-1, l+2);
        rot({p1,p2,p4,p3});
        rot({p4,p6,p5,p3});
        rot({p6,p4,p2,p1,p3,p5});
        rot({p4,p3,p5,p6});
        rot({p1,p2,p4,p3});
    }
    else {
        mv(xy,n-2,l+1);
        rot({mp(n-2,l), mp(n-1,l),mp(n-1,l+1),mp(n-2,l+1)});
    }
}

void flip() {
    auto p1 = mp(n-3,m-2);
    auto p2 = mp(n-3,m-1);
    auto p3 = mp(n-2,m-2);
    auto p4 = mp(n-2,m-1);
    auto p5 = mp(n-1,m-2);
    auto p6 = mp(n-1,m-1);
    rot({p1,p2,p4,p3});
    rot({p1,p3,p5,p6,p4,p2});
    rot({p3,p4,p6,p5});
}

void fix() {
    auto p1 = mp(n-3,m-2);
    auto p2 = mp(n-3,m-1);
    auto p3 = mp(n-2,m-2);
    auto p4 = mp(n-2,m-1);
    auto p5 = mp(n-1,m-2);
    auto p6 = mp(n-1,m-1);
    while(a[n-2][m-2] != to(n-2,m-2)) rot({p3,p4,p6,p5});
    if(a[n-1][m-2] == to(n-2,m-1)) {
        rot({p3,p4,p6,p5});
        flip();
    }
    else if(a[n-1][m-1] == to(n-2,m-1)) {
        flip();
        rot({p5,p6,p4,p3});
    }
    if(a[n-1][m-1] != to(n-1,m-1)) {
        rot({p3,p4,p6,p5});
        rot({p3,p4,p6,p5});
        flip();
        rot({p3,p4,p6,p5});
        rot({p3,p4,p6,p5});
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    a = vvi(n, vi(m, 0));
    forn(i,0,n) forn(j,0,m) scanf("%d", &a[i][j]);
    forn(k,0,n-2) forn(l,0,m-2) place(k, l);
    forn(k,0,n-2) placerow(k);
    forn(l,0,m-2) placecol(l);
    fix();
    
//    forn(i,0,n) {
//        forn(j,0,m) cout<<a[i][j] <<' ';
//        cout<<endl;
//    }
    printf("%d\n", ans.size());
    for(auto y : ans) {
        printf("%d", y.size());
        for(auto x : y) printf(" %d", x);
        printf("\n");
    }
    
}