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
#include <unordered_map>
#include <stdio.h>

using namespace std;

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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    int ax1,ay1,bx1,by1,tx1,ty1;
    ll ax,ay,bx,by,tx,ty;
    scanf("%d %d %d %d %d %d", &ax1, &ay1, &bx1, &by1, &tx1, &ty1);
    ax=ax1; bx=bx1; ay=ay1; by=by1; tx=tx1; ty=ty1;
    scanf("%d", &n);
    vpll p;
    int x,y;
    vector<pair<double, int>> ad, bd;
    double ans=0;
    forn(i,0,n) {
        scanf("%d %d", &x,&y);
        p.pb(mp(x,y));
        double dax = ax - x;
        double day = ay - y;
        double dbx = bx - x;
        double dby = by - y;
        double dtx = tx - x;
        double dty = ty - y;
        ad.pb(mp(sqrt(dax*dax+day*day)-sqrt(dtx*dtx+dty*dty), i));
        bd.pb(mp(sqrt(dbx*dbx+dby*dby)-sqrt(dtx*dtx+dty*dty), i));
        ans += 2*sqrt(dtx*dtx+dty*dty);
    }
    sort(all(ad));
    sort(all(bd));
    if(n == 1) ans += min(ad[0].first, bd[0].first);
    else if(ad[0].second != bd[0].second) {
        double amax = max(ad[0].first, bd[0].first);
        double amin = min(ad[0].first, bd[0].first);
        ans += amin;
        if(amax<0) ans+=amax;
    }
    else {
        double amax1 = max(ad[0].first, bd[1].first);
        double amin1 = min(ad[0].first, bd[1].first);
        double d1 = amin1;
        if(amax1<0) d1+=amax1;
        
        double amax2 = max(ad[1].first, bd[0].first);
        double amin2 = min(ad[1].first, bd[0].first);
        double d2 = amin2;
        if(amax1<0) d2+=amax2;
        
        ans += min(d1,d2);
    }
    printf("%.10lf", ans);
}