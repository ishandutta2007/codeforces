#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

struct pt {
    double x, y;
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
    int n;
    
    cin>>n;
    vector<pt> ch;
    vpi pl;
    map<pi, int> ans;
    int x,y;
    for(int i=0;i<n; i++) {
        cin>>x>>y;
        pl.pb(mp(x,y));
        pt a;
        a.x=1./(double)(x);
        a.y=1./(double)(y);
        ch.pb(a);
    }
    convex_hull(ch);
    for(int i=0; i<ch.size(); i++) {
        //cout<<ch[i].x<< "    " << ch[i].y<<endl;
    }
    int l=ch.size();
    double minx=10;
    int indx,indy;

    double miny=10;
    for(int i=0; i<l;i++) {
        if(ch[i].x<minx){
            minx=ch[i].x;
            indx=i;
        }
        if(ch[i].y<miny){
            miny=ch[i].y;
            indy=i;
        }
    }
    
    int t=0;
    while ((abs((ch[indy].y)-ch[(indy+1)%l].y)<0.000000001) && (t<2*l)){
        t++;
        indy=(indy+1)%l;
    }
    t=0;
    while ((abs((ch[indx].x)-ch[(indx+l-1)%l].x)<0.000000001) && (t<2*l)){
        t++;
        indx=(indx+l-1)%l;
    }
    int ind=indy;
    ans[mp((int)(1./ch[ind].x+0.2), (int)(1./ch[ind].y+0.2))] = 1;
    while(ind!=indx){
        ind=(ind+1)%l;
        ans[mp((int)(1./ch[ind].x+0.2), (int)(1./ch[ind].y+0.2))] = 1;
    }
    for(int i=0;i<n; i++) {
        if(ans[pl[i]]==1) cout<<(i+1)<< " ";
    }
    
}