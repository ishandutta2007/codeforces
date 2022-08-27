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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    while(1) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        if (n==0) break;
        vector<pair<pi, int>> pxu, pxd, pyl, pyr;
        vs a(n);
        vpi lol;
        forn(i,0,m) {
            int x,y;
            scanf("%d %d", &x, &y);
            
            x--;
            y--;
            lol.pb(mp(x,y));
            pxu.pb(mp(mp(x,y), i));
            pxd.pb(mp(mp(x,-y), i));
            pyl.pb(mp(mp(y,x), i));
            pyr.pb(mp(mp(y,-x), i));
        }
        sort(all(pxu));
        sort(all(pxd));
        sort(all(pyl));
        sort(all(pyr));
        vi ban(m,0);
        int miny = 10000000;
        int maxy = -1;
        
        forn(i,0,m) {
            if(pxu[i].first.second <= miny) {
                ban[pxu[i].second] = 1;
                miny = pxu[i].first.second;
            }
        }
        
        miny = 10000000;
        maxy = -1;
        
        for(int i=m-1;i>=0;i--) {
            if(-pxd[i].first.second > maxy) {
                ban[pxd[i].second] = 1;
                maxy = -pxd[i].first.second;
            }
            if(pxu[i].first.second <= miny) {
                ban[pxu[i].second] = 1;
                miny = pxu[i].first.second;
            }
        }
        
        vector<pt> pts;
        forn(i,0,m) {
            if(!ban[i]) {
                pts.pb(pt(lol[i].first+1, lol[i].second));
            }
        }
        
        ban = vi(m,0);
        miny = 10000000;
        maxy = -1;
        forn(i,0,m) {
            if(pxu[i].first.second >= maxy) {
                ban[pxu[i].second] = 1;
                maxy = pxu[i].first.second;
            }
            if(-pxd[i].first.second < miny) {
                ban[pxd[i].second] = 1;
                miny = -pxd[i].first.second;
            }
        }
        miny = 10000000;
        maxy = -1;
        for(int i=m-1; i>=0; i--) {
            if(pxu[i].first.second >= maxy) {
                ban[pxu[i].second] = 1;
                maxy = pxu[i].first.second;
            }
        }
        
        forn(i,0,m) {
            if(!ban[i]) {
                pts.pb(pt(lol[i].first, lol[i].second+1));
            }
        }
//DONE
        ban = vi(m,0);
        miny = 10000000;
        maxy = -1;
        forn(i,0,m) {
            if(-pxd[i].first.second <= miny) {
                ban[pxd[i].second] = 1;
                miny = -pxd[i].first.second;
            }
            if(pxu[i].first.second > maxy) {
                ban[pxu[i].second] = 1;
                maxy = pxu[i].first.second;
            }
        }
        miny = 10000000;
        maxy = -1;
        for(int i=m-1; i>=0; i--) {
            if(-pxd[i].first.second <= miny) {
                ban[pxd[i].second] = 1;
                miny = -pxd[i].first.second;
            }
        }
        
        forn(i,0,m) {
            if(!ban[i]) {
                pts.pb(pt(lol[i].first, lol[i].second));
            }
        }
        
        
        ban = vi(m,0);
        miny = 10000000;
        maxy = -1;
        forn(i,0,m) {
            if(-pxd[i].first.second >= maxy) {
                ban[pxd[i].second] = 1;
                maxy = -pxd[i].first.second;
            }
        }
        miny = 10000000;
        maxy = -1;
        for(int i=m-1; i>=0; i--) {
            if(-pxd[i].first.second >= maxy) {
                ban[pxd[i].second] = 1;
                maxy = -pxd[i].first.second;
            }
            if(pxu[i].first.second < miny) {
                ban[pxu[i].second] = 1;
                miny = pxu[i].first.second;
            }
            
        }
        
        forn(i,0,m) {
            if(!ban[i]) {
                pts.pb(pt(lol[i].first+1, lol[i].second+1));
            }
        }
        
        convex_hull(pts);
//        forn(i,0,n) printf("%s\n", b[i].c_str());
        int ind = 0;
//        reverse(all(pts));
        forn(i,1,pts.size()) {
            if(pts[i].x < pts[ind].x || (pts[i].x == pts[ind].x && pts[i].y < pts[ind].y)) ind = i;
        }
        vector<pt> pts2;
        forn(i,ind, pts.size()) pts2.pb(pts[i]);
        forn(i,0,ind) pts2.pb(pts[i]);
        pts = std::move(pts2);
        pts2.clear();
//        cout<<pts.size()<<endl;
        printf("%d\n", (int)pts.size());
        for(auto u : pts) printf("%d %d\n", (int)u.x, (int)u.y);
//            cout<<u.y << ' ' << u.x << endl;
//        printf("\n");
    
        
    }
    
    
    
    
//    int minx = n;
//    int miny = n;
//    int maxx = -1;
//    int maxy = -1;
//    forn(i,0,n) forn(j,0,n) if(a[i][j] == '4') {
//        minx=min(minx, i);
//        miny=min(miny, j);
//        maxx=max(maxx, i);
//        maxy=max(maxy, j);
//    }
//    if(minx==n) {
//        cout<<"No";
//        return 0;
//    }
//    vs b(n, string(n,'0'));
//    forn(i,minx,maxx+1) forn(j,miny,maxy+1) {
//        b[i][j] = '4';
//    }
//    if(minx>0) {
//        forn(j,miny,maxy+1) {
//            b[minx-1][j] = '2';
//        }
//        if(miny>0) b[minx-1][miny-1] = '1';
//        if(maxy<n-1) b[minx-1][maxy+1] = '1';
//    }
//    if(maxx<n-1) {
//        forn(j,miny,maxy+1) {
//            b[maxx+1][j] = '2';
//        }
//        if(miny>0) b[maxx+1][miny-1] = '1';
//        if(maxy<n-1) b[maxx+1][maxy+1] = '1';
//    }
//    if(miny>0) {
//        forn(i,minx,maxx+1) {
//            b[i][miny-1] = '2';
//        }
//    }
//    if(maxy<n-1) {
//        forn(i,minx,maxx+1) {
//            b[i][maxy+1] = '2';
//        }
//    }
//    //    forn(i,0,n) cout<<b[i] <<endl;
//    forn(i,0,n) forn(j,0,n) {
//        if(a[i][j]!=b[i][j]) {
//            cout<<"No";
//            return 0;
//        }
//    }
//    cout<<"Yes";
    
}