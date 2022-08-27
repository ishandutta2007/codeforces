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

void un(vi & a) {
    vi na = a;
    srt(na);
    a.clear();
    forn(i,0,na.size()) {
        if(i==0 || na[i] != na[i-1]) a.pb(na[i]);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vvi a(n, vi(m,0));
    forn(i,0,n) forn(j,0,m) scanf("%d", &a[i][j]);
    vvi r(n,vi(m));
    vvi c(m, vi(n));
    forn(i,0,n) forn(j,0,m) {
        c[j][i] = a[i][j];
        r[i][j] = a[i][j];
    }
    forn(i,0,n) un(r[i]);
    forn(i,0,m) un(c[i]);
    forn(i,0,n) forn(j,0,m) {
        int ir = lower_bound(all(r[i]), a[i][j]) - r[i].begin();
        int ic = lower_bound(all(c[j]), a[i][j]) - c[j].begin();
        int d = max(ir, ic);
        int u = max(r[i].size() - ir, c[j].size() - ic);
        printf("%d ", d+u);
        if(j==m-1) printf("\n");
    }
    
}