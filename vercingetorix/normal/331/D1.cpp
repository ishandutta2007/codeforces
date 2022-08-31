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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

vi to;
int b;
int A;
int encode(int x, int y, int d) {
    return d*A*A+x*A+y;
}
vi dx,dy;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    dx.pb(1); dx.pb(0); dx.pb(-1); dx.pb(0);
    dy.pb(0); dy.pb(1); dy.pb(0); dy.pb(-1);
    int n;
    scanf("%d %d", &n, &b);
    A=b+1;
    to.resize(4*(b+1)*(b+1));
    vvi f(b+1, vi(b+1, -1));
    forn(i,0,n) {
        int x0,y0,x1,y1;
        scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
        int dir = 0;
        if(x1>x0) dir = 0;
        else if(y1>y0) dir = 1;
        else if(x1<x0) dir = 2;
        else if(y1<y0) dir = 3;
        if(x0>x1) swap(x0,x1);
        if(y0>y1) swap(y0,y1);
        forn(x,x0,x1+1) forn(y,y0,y1+1) f[x][y] = dir;
    }
    
    int q;
    scanf("%d", &q);
    vi pos(q);
    vll len(q);
    forn(i,0,q) {
        int x,y;
        char c;
        scanf("%d %d %c %lld", &x, &y, &c, &len[i]);
        int dir = 0;
        if(c=='U') dir = 1;
        else if(c == 'L') dir = 2;
        else if(c == 'D') dir = 3;
        pos[i] = encode(x, y, dir);
    }
    forn(x,0,b+1) forn(y,0,b+1) forn(dir,0,4) {
        int top = dir;
        if(f[x][y] != -1) top = f[x][y];
        int nx = x + dx[top];
        int ny = y + dy[top];
        int cur = encode(x, y, dir);
        if(nx <0 || nx>b || ny<0 ||ny>b) to[cur] = cur;
        else to[cur] = encode(nx, ny, top);
    }
    forn(it,0,60) {
        forn(i,0,q) {
            if(len[i] % 2) pos[i] = to[pos[i]];
            len[i] /= 2;
        }
        vi nto(4*A*A);
        forn(i,0,4*A*A) nto[i] = to[to[i]];
        to = std::move(nto);
        nto.clear();
    }
    forn(i,0,q) {
        printf("%d %d\n", (pos[i] / A) % A, pos[i]%A);
    }
    
    
}