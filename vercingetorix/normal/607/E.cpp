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
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;
const double pipi = 3.1415926535897932384626433832795;
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
struct pt {
    double x;
    double y;
};

double dist(pt & p1, pt & p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;


typedef tree<pair<double, int>,int,less<pair<double, int>>,rb_tree_tag,tree_order_statistics_node_update> map_t;
/*
 int main() {
 #ifdef NEREVAR_PROJECT
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 #endif
 map_t s;
 s.insert(make_pair(mp(2,1), 5));
 s.insert(make_pair(mp(3,7), 14));
 s.insert(make_pair(mp(10,5), 15));
 s.insert(make_pair(mp(3,5), 14));
 //assert(s.find_by_order(1)->second == 14);
 //assert(s.order_of_key(50) == 2);
 
 for (map_t::iterator it = s.begin(); it != s.end(); it++) {
 cerr << it->first->first << " " << it->first->second << " " << it->second << endl;
 } */

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    /*
     map_t s;
     s.insert(make_pair(mp(2,1), 5));
     s.insert(make_pair(mp(3,7), 14));
     s.insert(make_pair(mp(10,5), 15));
     s.insert(make_pair(mp(3,5), 14));
     // assert(s.find_by_order(1)->second == 14);
     // assert(s.order_of_key(50) == 2);
     
     for (map_t::iterator it = s.begin(); it != s.end(); it++) {
     cout << it->first.first << " " << it->first.second << " " << it->second << endl; }
     auto xxx = s.lower_bound(mp(3,0));
     cout<<xxx->first.first<<"   "<<xxx->first.second<<endl;
     cout<<s.order_of_key(xxx->first);
     
     return 0; */
    int nn,mm,k;
    //string s;
    //ll ans = 0;
    scanf("%d", &nn);
    int xx,yy;
    scanf("%d %d %d", &xx, &yy, &mm);
    ll n=nn;
    ll m=mm;
    ll x=xx;
    ll y=yy;
    pt P;
    P.x = (double)x/1000.;
    P.y = (double)y/1000.;
    vll a;
    vll b;
    forn(i,0,n) {
        int aa,bb;
        scanf("%d %d", &aa, &bb);
        a.pb(aa);
        b.pb(bb);
    }
    vector<pt> h(n);
    forn(i, 0,n) {
        double c = (double) (a[i]*x+b[i]*1000-y*1000) / (1000000 + a[i]*a[i]);
        h[i].x = (double) x/1000 - c*a[i]/1000;
        h[i].y = (double) y/1000 + c;
    }
    long double rr = 5000000000;
    long double rl = 0;
    vector<pair<double, int>> lol;
    int debcnt = 0;
    while (rr-rl > max((long double)0.000000000000000001, rr*0.000000000000000001)) {
        long double r = (rr+rl) / 2;
//r=2.0005;
        ll num = 0;
        vector<pair<pair<double,int>, int>> intersections;
        vd hordend(n);

        for(int i = 0; i<n; i++) {
            double dh = dist(h[i], P);
            if(dh <= r) {
                double h2 = sqrt(r*r - dh*dh);
                double baselen = sqrt(1. + (double) a[i]*a[i] / 1000000.);
                double dx = h2/baselen;
                double dy = h2 * a[i] / (1000. * baselen);
                double x1 = h[i].x - dx - P.x;
                double x2 = h[i].x + dx - P.x;
                double y1 = h[i].y - dy - P.y;
                double y2 = h[i].y + dy - P.y;
                
                double a1, a2;
                if (y1 >= 0) a1 = acos(x1 / r);
                else a1 = pipi + acos(-x1 / r);
                if (y2 >= 0) a2 = acos(x2 / r);
                else a2 = pipi + acos(-x2 / r);
                if(a1>a2) swap(a1,a2);
                hordend[i]=a2;
                intersections.pb(mp(mp(a1,0), i));
                intersections.pb(mp(mp(a2,1), i));
            }
        }
        sort(all(intersections));
        //for(auto deb: intersections) {
        //    cout<<deb.first.first<<endl;
        //}
        //return 0;
        map_t he;
        he.insert(mp(mp(100., 0), 0));
        for(auto cirp : intersections) {
            if (cirp.first.second == 1) {
                he.erase(mp(cirp.first.first, cirp.second));
            }
            else {
                double myend = hordend[cirp.second];
                auto howmuch = he.lower_bound(mp(myend, 999999));
                num+=he.order_of_key(howmuch->first); // add how much open hords end before
                he.insert(mp(mp(myend, cirp.second), 0));
                if(num>=m) break;
            }
        }
        lol.pb(mp(r,num));
        if(num >= m) rr = r;
        else rl = r;
        debcnt ++;
        /*if(debcnt == 1000) cout<<rl<< " "<< rr<< " and mid " << r <<endl;
        if(debcnt == 1000) cout<<rr-rl<<endl;
        if(debcnt == 1000) cout<<r-rl<<endl;
        if(debcnt == 1000) cout<<rr-r<<endl;
        if(debcnt == 1000) cout<<num;
        
        if(debcnt == 1000) return 0; */
    }
    //
   // cout<<rl<<endl;
    //return 0;
      //  cout << lol.back().first<< " num " << lol.back().second<<endl;
    
    long double r = rl;
    double ans = 0;
    ll num = 0;
    vector<pair<pair<double,int>, int>> intersections;
    vd hordend(n);
    
    for(int i = 0; i<n; i++) {
        double dh = dist(h[i], P);
        if(dh <= r) {
            double h2 = sqrt(r*r - dh*dh);
            double baselen = sqrt(1. + (double) a[i]*a[i] / 1000000.);
            double dx = h2/baselen;
            double dy = h2 * a[i] / (1000. * baselen);
            double x1 = h[i].x - dx - P.x;
            double x2 = h[i].x + dx - P.x;
            double y1 = h[i].y - dy - P.y;
            double y2 = h[i].y + dy - P.y;
            double a1, a2;
            if (y1 >= 0) a1 = acos(x1 / r);
            else a1 = pipi + acos(-x1 / r);
            if (y2 >= 0) a2 = acos(x2 / r);
            else a2 = pipi + acos(-x2 / r);
            if(a1>a2) swap(a1,a2);
            hordend[i]=a2;
            intersections.pb(mp(mp(a1,0), i));
            intersections.pb(mp(mp(a2,1), i));
        }
    }
    sort(all(intersections));
    map_t he;
    he.insert(mp(mp(100., 0), 0));
    for(auto cirp : intersections) {
        if (cirp.first.second == 1) {
            he.erase(mp(cirp.first.first, cirp.second));
        }
        else {
            double myend = hordend[cirp.second];
            auto howmuch = he.upper_bound(mp(myend, 999999));
            num+=he.order_of_key(howmuch->first); // add how much open hords end before
            
            for (auto cnt = he.begin(); cnt != howmuch; cnt++) {
                int u = cirp.second;
                int v = cnt->first.second;
               // cout<<u<<" "<<v<<endl;
                pt cross;
                cross.x = (double)(b[v]-b[u])/(a[u]-a[v]);
                cross.y = (cross.x * a[u] +(double) b[u])* 0.001;
                ans += dist(P, cross);
            }
            he.insert(mp(mp(myend, cirp.second), 0));
            if(num>=m) break;
        }
    }
    
    ans += r*(m-num);
    printf("%.10lf", ans);
}