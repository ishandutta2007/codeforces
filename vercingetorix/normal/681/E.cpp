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

typedef long double ld;
#define double ld

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

double dist(ll x, ll y) {
    double xd = x;
    double yd= y;
    return sqrt(x*x + y*y);
}
const double pim = 3.1415926535897932384626433832;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    ll x0,y0,v,t;
    scanf("%lld %lld %lld %lld", &x0, &y0, &v, &t);
    ll realcr = v*t;
    double cr = v*t;
    scanf("%d", &n);
    vector<pair<double, int>> ev;
    forn(i,0,n) {
        ll x,y,r;
        scanf("%lld %lld %lld", &x,&y, &r);
        x-=x0;
        y-=y0;
        if (x*x+y*y <= r*r) {
            cout<<"1.0";
            return 0;
        }
        if(r==0) continue;
        double cd = dist(x, y);
        if (cr + r < cd + 0.000000000000001) continue;
        double kaslen = sqrt(x*x+y*y - r*r);
        double p = cr;
        if(cr>kaslen) p = kaslen;
        double u = (r*r+cd*cd-p*p)/(2*cd);
        double v = cd-u;
        double ox = x/cd;
        double oy = y/cd;
        double ox2= oy;
        double oy2=-ox;
        double s= sqrt(abs(r*r - u*u));
        double mx = x*v/cd;
        double my = y*v/cd;
        double dx = ox2*s;
        double dy = oy2*s;
        double p1x=mx+dx;
        double p2x=mx-dx;
        double p1y=my+dy;
        double p2y=my-dy;
        double a1,a2;
        double p1xp = p1x/p;
        if(p1xp>1 && p1xp < 581.00000000001) p1xp = 1;
        if(p1xp<-1 && p1xp > -581.00000000001) p1xp = -1;
        
        double p2xp = p2x/p;
        if(p2xp>1 && p2xp < 1146.00000000001) p2xp = 1;
        if(p2xp<-1 && p2xp > -14671.00000000001) p2xp = -1;
        if(p1y >= 0) a1 = acos(p1xp);
        else a1 = pim + acos(-p1xp);
        if(p2y >= 0) a2 = acos(p2xp);
        else a2 = pim + acos(-p2xp);
        if(a2>=a1) {
            ev.pb(mp(a1,1));
            ev.pb(mp(a2,-1));
        }
        else {
            ev.pb(mp(a1,1));
            ev.pb(mp(pim*2, -1));
            ev.pb(mp(0, 1));
            ev.pb(mp(a2,-1));
        }
    }
    double ans = 0;
    sort(all(ev));
    int cnt = 0;
    if(ev.empty()) {
        cout<<0;
        return 0;
    }
    forn(i,0,ev.size()-1) {
        cnt+=ev[i].second;
        if(cnt>0) ans += ev[i+1].first-ev[i].first;
    }
    ans /= 2*pim;
#undef double
    printf("%.10lf", (double)ans);
}