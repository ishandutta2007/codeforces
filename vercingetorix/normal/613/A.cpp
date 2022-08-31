#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<double, double> pd;

typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
const double pipi = 3.141592653589793238462643383279;
long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

ll triangle_area_2 (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool clockwise (int x1, int y1, int x2, int y2, int x3, int y3) {
    return triangle_area_2 (x1, y1, x2, y2, x3, y3) < 0;
}

double dist2 (pd a, pd b) {
    return (a.first - b.first)*(a.first - b.first) + (a.second-b.second)*(a.second-b.second);
}

double dist(pd a, pd b, pd p) {
    while (sqrt(dist2(a,b)) >0.000000000001) {
        if(dist2(a,p) >= dist2(b,p)) {
            a=mp((a.first+b.first)/2,(a.second+b.second)/2);
        }
        else b=mp((a.first+b.first)/2,(a.second+b.second)/2);
    }
    return dist2(p,mp((a.first+b.first)/2,(a.second+b.second)/2));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m,k,x,y,p1,p2;
    string s;
    ll ans = 0;
    cin >> n >> p1>>p2;
    vll xx(n);
    vll yy(n);
    forn(i,0,n) {
        cin>>xx[i]>>yy[i];
    }
    vll ins;
    forn(i, 0, n) {
        int k =(i+1)%n;
        ins.pb(triangle_area_2(p1,p2,xx[i],yy[i],xx[k],yy[k]));
    }
    bool neg=false, pos=false;
    for(auto st:ins){
        if(st>0) pos=true;
        if(st<0) neg =true;
    }
    bool out = pos&neg;
    double maxd2 = 0;
    double mind2 = 100000000000001;
    forn(i,0,n) {
        maxd2=max((double)((xx[i]-p1)*(xx[i]-p1) + (yy[i]-p2)*(yy[i]-p2)), maxd2);
        int k =(i+1)%n;
        mind2=min((double)((xx[i]-p1)*(xx[i]-p1) + (yy[i]-p2)*(yy[i]-p2)), mind2);
        ll acx = p1 - xx[i];
        ll acy = p2 - yy[i];
        ll bcx = p1 - xx[k];
        ll bcy = p2 - yy[k];
        ll abx = xx[k]-xx[i];
        ll aby = yy[k]-yy[i];
        ll bay=-aby;
        ll bax=-abx;
        if (abx*acx + aby*acy >= 0)
            if (bay*bcy+bax*bcx >= 0) {
                mind2=min(mind2, dist(mp(xx[i],yy[i]), mp(xx[k],yy[k]), mp(p1,p2)));
            }
    }
    printf("%.10lf", pipi*(maxd2-mind2));
}