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
typedef std::vector<ld> vld;
typedef std::vector<vld> vvld;
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
    int n,t;
    scanf("%d %d", &n, &t);
    vi f(n), s(n), P(n);
    forn(i,0,n) scanf("%d %d %d", &f[i], &s[i], &P[i]);
    vld p;
    forn(i,0,n) p.pb(ld(P[i])/100);
    int ff = 0;
    forn(i,0,n) ff += f[i];
    ff = t - ff;
    ld l = 0;
    ld r = 1e18;
    forn(it,0,240) {
        ld m = (l+r)/2;
        vvld d(n+1, vld(ff+1,0));
        for(int i = n-1; i>=0; i--) {
            forn(miss, 0, ff+1) {
                ld tr = 0;
                tr += (d[i+1][miss]+f[i]) * p[i];
                if(miss + s[i]-f[i] > ff) tr += (m+s[i]) * (1-p[i]);
                else tr += (d[i+1][miss+s[i]-f[i]]+s[i]) * (1-p[i]);
                d[i][miss] = min(tr, m);
            }
        }
        ld cur = d[0][0];
        if (cur < m) r = m;
        else l = m;
        if(it>120) {
//            cout<<' ';
        }
    }
    printf("%.12lf", (double)l);
    
}