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

int dist(pi a, pi b) {
    int x = b.first-a.first;
    int y = b.second - a.second;
    if(x < 0) {
        x= -x;
        y= -y;
    }
    if(y>0) return max(x,y);
    else return x-y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[500010];
    int n;
    scanf("%d\n", &n);
    vpi u;
    forn(i,0,n) {
        scanf("%s", c);
        string s(c);
        int k = s.size();
        int a = 0;
        int b = 0;
        forn(i,0,k) {
            if(s[i]=='B') a++;
            else b++;
        }
        u.pb(mp(a,b));
    }
//    vi gi;
    vpi f;
    map<pi, pi> dirlim;
    for(auto dir : {mp(1,0), mp(0,1), mp(1,-1)}) {
        int mni = 0;
        int mxi = 0;
        forn(i,0,n) {
            if(dir.first * u[i].first + dir.second * u[i].second > dir.first * u[mxi].first + dir.second * u[mxi].second) mxi = i;
            if(dir.first * u[i].first + dir.second * u[i].second < dir.first * u[mni].first + dir.second * u[mni].second) mni = i;
        }
        f.pb(u[mni]);
        f.pb(u[mxi]);
        dirlim[dir] = mp(dir.first * u[mni].first + dir.second * u[mni].second, dir.first * u[mxi].first + dir.second * u[mxi].second);
//        gi.pb(mni);
//        gi.pb(mxi);
    }
    int l = -1;
    int r = 1000000;
    int ax,ay;
    while(r-l > 1) {
        int m = (r+l)/2;
        pi x = dirlim[mp(1,0)];
        pi y = dirlim[mp(0,1)];
        pi xy = dirlim[mp(1,-1)];
        if(x.second-x.first>2*m || y.second-y.first>2*m || xy.second-xy.first>2*m) {
            l=m;
            continue;
        }
        pi xlim = mp(x.second-m, x.first+m);
        pi ylim = mp(y.second-m, y.first+m);
        pi xylim = mp(xy.second-m, xy.first+m);
        pi xylim2 = mp(xlim.first-ylim.second, xlim.second-ylim.first);
        if(xylim.first > xylim2.second || xylim.second < xylim2.first) {
            l=m;
            continue;
        }
        int diff = max(xylim.first, xylim2.first);
        ax = xlim.first;
        ay = ylim.second;
        if(ax-ay < diff) {
            ax += min(diff-ax+ay,xlim.second-xlim.first);
        }
        if(ax-ay < diff) {
            ay -= min(diff-ax+ay,ylim.second-ylim.first);
        }
        r=m;
    }
//    pi worst = mp(0,0);
//    forn(i,0,6) forn(j,0,6) {
//        if(dist(f[worst.first], f[worst.second]) < dist(f[i], f[j])) worst = mp(i,j);
//    }
//    int ans = (dist(f[worst.first], f[worst.second]) + 1)/2;
//    int xans = (f[worst.first].first + f[worst.second].first)/2;
//    int yans = (f[worst.first].second + f[worst.second].second+1)/2;
    printf("%d\n", r);
    printf("%s\n", (string(ax,'B')+string(ay,'N')).c_str());
}