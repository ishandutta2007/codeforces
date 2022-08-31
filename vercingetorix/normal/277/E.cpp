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
typedef std::vector<ld> vld;
typedef std::vector<vld> vvld;
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
int sq(int x) {
    return x*x;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi x(n),y(n);
    int my = -10000;
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
        my = max(my, y[i]);
    }
    int cntmy = 0;
    forn(i,0,n) if(y[i] == my) cntmy++;
    if(cntmy>1) {
        cout<<-1;
        return 0;
    }
    int m = 2*n;
    const ld INF = 1e8;
    vvld a(n+1, vld(m+1, INF));
    forn(i,0,n) {
        if(y[i] == my) {
            forn(j,0,m) a[i+1][j+1] = 0;
        }
        else {
            forn(j,0,n) {
                if(y[j] > y[i]) {
                    ld dist = sqrt(ld(sq(x[i]-x[j]) + sq(y[i]-y[j])));
                    a[i+1][2*j+1] = dist;
                    a[i+1][2*j+2] = dist;
                }
            }
        }
    }
    
    vector<int> p (m+1), way (m+1);
    vld u (n+1), v (m+1);
    for (int i=1; i<=n; ++i) {
        p[0] = i;
        int j0 = 0;
        vld minv (m+1, INF*INF);
        vector<char> used (m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0],    j1;
            ld delta = INF;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    ld cur = a[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    if(-v[0] > INF/2) cout<<-1;
    else printf("%.12lf", (double)-v[0]);
    
}