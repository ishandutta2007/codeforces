#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const ld PI = acos((ld)-1);
vll x, y, r;

bool isin(int i, int j) {
    return r[i]<r[j] && (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) < r[j]*r[j];
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    x.resize(n);
    y.resize(n);
    r.resize(n);
    forn(i,0,n) scanf("%lld %lld %lld", &x[i], &y[i], &r[i]);
    vi par(n, -1);
    forn(i,0,n) forn(j,0,n) {
        if(isin(i,j)) {
            if(par[i] == -1) par[i] = j;
            else {
                if(r[par[i]] > r[j]) par[i] = j;
            }
        }
    }
    vector<ld> s(n);
    forn(i,0,n) s[i] = PI*r[i]*r[i];
    forn(i,0,n) if(par[i]!=-1) s[par[i]] -= PI*r[i]*r[i];
    ld ans = 0;
    forn(i,0,n) {
        int lev = 1;
        int cur = i;
        while(par[cur] != -1) {
            lev++;
            cur = par[cur];
        }
        ans += s[i];
        if(lev%2==0) ans += s[i];
    }
    printf("%.10lf", (double) ans);
    
}