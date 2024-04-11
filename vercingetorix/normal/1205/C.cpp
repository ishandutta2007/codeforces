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

int req(int x1, int y1, int x2, int y2) {
    printf("? %d %d %d %d\n", x1+1, y1+1,x2+1, y2+1);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
int n,r;
vvi a;
vvi b,c;
void go(vvi & a, int i, int j) {
    if(i>0 && j>0 && a[i-1][j-1] == -1) {
        a[i-1][j-1] = (req(i-1,j-1,i,j) + a[i][j] + 1)%2;
        go(a,i-1, j-1);
    }
    if(i < n-2 && a[i+2][j] == -1) {
        a[i+2][j] = (req(i,j,i+2,j) + a[i][j] + 1)%2;
        go(a,i+2,j);
    }
    if(j < n-2 && a[i][j+2] == -1) {
        a[i][j+2] = (req(i,j,i,j+2) + a[i][j] + 1)%2;
        go(a,i,j+2);
    }
}

void go2(int i, int j) {
    if(i>0 && j>0 && b[i-1][j-1] == -1) {
        int u = req(i-1,j-1,i,j);
        b[i-1][j-1] = (u + b[i][j] + 1)%2;
        c[i-1][j-1] = (u + c[i][j] + 1)%2;
        go2(i-1, j-1);
    }
    if(i < n-2 && b[i+2][j] == -1) {
        int u = req(i,j,i+2,j);
        b[i+2][j] = (u + b[i][j] + 1)%2;
        c[i+2][j] = (u + c[i][j] + 1)%2;
        go2(i+2,j);
    }
    if(j < n-2 && b[i][j+2] == -1) {
        int u = req(i,j,i,j+2);
        b[i][j+2] = (u + b[i][j] + 1)%2;
        c[i][j+2] = (u + c[i][j] + 1)%2;
        go2(i,j+2);
    }
}

bool reqq(vvi & x, int x1, int y1, int x2, int y2) {
    if(x1>x2 || y1>y2) return false;
    if(x[x1][y1] != x[x2][y2]) return false;
    if(x2-x1+y2-y1 <= 2) return true;
    vpi st1,st2;
    vpi et1,et2;
    if(x1<x2) {
        st1.pb(mp(x1+1,y1));
        st2.pb(mp(x2-1,y2));
    }
    if(y1<y2) {
        st1.pb(mp(x1,y1+1));
        st2.pb(mp(x2,y2-1));
    }
    bool ret= false;
    for(auto p1 : st1) for(auto p2 : st2) ret |= reqq(x, p1.first, p1.second, p2.first, p2.second);
    return ret
    ;}



void diff() {
    forn(i,0,n) forn(j,0,n) {
        forn(i2,i,min(i+4,n)) forn(j2,j,min(j+4,n)) {
            if(i2-i + j2-j >= 2)
            if(reqq(b,i,j,i2,j2) != reqq(c, i, j, i2, j2)) {
                if(req(i,j,i2,j2) == reqq(b,i,j,i2,j2)) a=b;
                else a=c;
                return;
            }
        }
    }
}
int main()
{

    scanf("%d", &n);
    a = vvi(n, vi(n, - 1));
    a[0][0] = 1;
    a[n-1][n-1] = -1;
    go(a,0,0);
    b= a;
    c = a;
    b[0][1] = 0;
    c[0][1] = 1;
    go2(0,1);
    diff();
    printf("!\n");
    forn(i,0,n) {
        forn(j,0,n) printf("%d", a[i][j]);
        printf("\n");
    }
//    forn(i,0,n-2) a[i+1][i+1] = (req(i,i,i+1,i+1) + a[i][i] + 1)%2;
//    forn(i,0,n) {
//        for(int j = i-2; j>=0; j-=2) {
//            a[i][j] = (a[i][j+2] + req(i,j,i,j+2) + 1)%2;
//        }
//        for(int j = i+2; j<n; j++) {
//            a[i][j] = (a[i][j-2] + req(i, j-2, i, j) + 1) % 2;
//        }
//    }
}