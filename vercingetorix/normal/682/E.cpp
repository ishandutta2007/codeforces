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
struct pt {
    pt(ll x, ll y) : x(x), y(y) {};
    ll x, y;
};

bool cmp (pt a, pt b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
    if (a.size() == 1)  return;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0],  p2 = a.back();
    vector<pt> up, down;
    up.push_back (p1);
    down.push_back (p1);
    for (size_t i=1; i<a.size(); ++i) {
        if (i==a.size()-1 || cw (p1, a[i], p2)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2)) {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }
    a.clear();
    for (size_t i=0; i<up.size(); ++i)
        a.push_back (up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        a.push_back (down[i]);
}

ll area (pt p1, pt p2, pt p3) {
    return abs((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    ll S;
    scanf("%d %lld", &n, &S);
    vector<pt> a;
    forn(i,0,n) {
        int x,y;
        scanf("%d %d", &x, &y);
        a.emplace_back(x,y);
    }
    convex_hull(a);
    int i1,i2,i3;
    ll maxS = 0;
    int l = a.size();
    forn(i,0,l) {
        int j = (i+1)%l;
        int k = (j+1)%l;
//        while((k+1)%l != i && area(a[i], a[j], a[(k+1)%l]) > area(a[i], a[j], a[k])) k = (k+1)%l;
//        if(area(a[i], a[j], a[k]) > maxS) {
//            maxS = area(a[i], a[j], a[k]);
//            i1 = i;
//            i2=j;i3= k;
//        }
//        j= (j+1)%l;
//        if(k==j) k=(k+1)%l;
        while((j+1)%l != i) {
            while((k+1)%l != i && area(a[i], a[j], a[(k+1)%l]) > area(a[i], a[j], a[k])) k = (k+1)%l;
            if(area(a[i], a[j], a[k]) > maxS) {
                maxS = area(a[i], a[j], a[k]);
                i1 = i;
                i2=j;i3= k;
            }
            j= (j+1)%l;
            if(k==j) k=(k+1)%l;
        }
    }
    vi u(3);
    u[0]=i1;
    u[1]=i2;
    u[2]=i3;
     forn(i,0,3) {
        int j = (i+1)%3;
        int k = (i+2)%3;
        cout << a[u[j]].x+a[u[k]].x-a[u[i]].x <<" " << a[u[j]].y+a[u[k]].y-a[u[i]].y<<endl;
    }
}