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
    int n,m;
    scanf("%d %d", &n, &m);
    vvi a(n, vi(m));
    vvi b(n, vi(m));
    forn(i,0,n) forn(j,0,m) scanf("%d", &a[i][j]);
//    forn(i,0,n) forn(j,0,m) scanf("%d", &b[i][j]);
    vpi ro, co;
    forn(i,0,n) {
        int mx = 0;
        forn(j,0,m) mx=max(mx,a[i][j]);
        ro.pb(mp(mx, i));
    }
    forn(j,0,m) {
        int mx = 0;
        forn(i,0,n) mx=max(mx,a[i][j]);
        co.pb(mp(mx, j));
    }
    sort(all(ro));
    sort(all(co));
    forn(i,0,n) forn(j,0,m) {
//        b[i][j] = a[ro[i].second][co[j].second];
        b[i][j] = -1;
    }
    vi isr(n*m+1,0);
    vi isc(n*m+1,0);
    forn(i,0,n) {
        isr[ro[i].first] = 1;
    }
    vpi q;
    forn(j,0,m) {
        isc[co[j].first] = 1;
    }
    int rt = 0;
    int ct = 0;
    int pt = 0;
    for(int x = n*m; x>=1; x--) {
        if(!isr[x] && !isc[x]) {
            b[q[pt].first][q[pt].second] = x;
            pt++;
        }
        else if(isr[x] && isc[x]) {
            b[rt][ct] = x;
            for(int i = ct-1; i >= 0; i--) q.pb(mp(rt, i));
            for(int i = rt-1; i >= 0; i--) q.pb(mp(i, ct));
            ct++;
            rt++;
        }
        else if(isr[x]) {
            b[rt][ct-1] = x;
            for(int i = ct-2; i >= 0; i--) q.pb(mp(rt, i));
            
            rt++;
        }
        else if(isc[x]) {
            b[rt-1][ct] = x;
            for(int i = rt-2; i >= 0; i--) q.pb(mp(i, ct));
            ct++;
        }
    }
    forn(i,0,n) {
        forn(j,0,m) printf("%d ", b[i][j]);
        printf("\n");
    }
    
}