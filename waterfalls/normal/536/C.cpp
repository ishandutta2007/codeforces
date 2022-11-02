#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

struct Point { long long x,y; };
bool comp(Point a, Point b) {
    if (a.x*b.y==a.y*b.x) return a.x>b.x;
    return a.x*b.y>a.y*b.x;
}

bool bad(Point a, Point b, Point c) {
    if (a.y==0) return b.x<c.x || (b.x==c.x && b.y<c.y);
    if (c.x==0) return b.y<a.y || (b.y==a.y && b.x<a.x);
    return a.x*c.y*(b.y-a.y)*(b.x-c.x)+a.y*c.x*(a.x-b.x)*(b.y-c.y)<0;
}

int N;
map<pair<long long,long long>,vector<int> > has;
long long x[200013];
long long y[200013];
vector<Point> points;
vector<Point> hull;
vector<int> win;

int main() {
    scanf("%d",&N);
    for (int i=0;i<N;i++) {
        int s,r;
        scanf("%d%d",&s,&r);
        has[make_pair(s,r)].push_back(i+1);
    }
    N = 0;
    for (map<pair<long long,long long>,vector<int> >::iterator it=has.begin();it!=has.end();it++) {
        x[N] = it->first.first;
        y[N] = it->first.second;
        N+=1;
    }
    x[N] = 1000000000; y[N] = 0; N+=1;
    x[N] = 0; y[N] = 1000000000; N+=1;
    for (int i=0;i<N;i++) {
        Point next;
        next.x = x[i], next.y = y[i];
        points.push_back(next);
    }
    sort(points.begin(),points.end(),comp);
    hull.push_back(points[0]);
    for (int i=1;i<N;i++) {
        while (hull.size()>1 && bad(hull[hull.size()-2],hull[hull.size()-1],points[i])) hull.pop_back();
        hull.push_back(points[i]);
    }
    for (int i=0;i<hull.size();i++) if (hull[i].x*hull[i].y!=0) {
        for (int j=0;j<has[make_pair(hull[i].x,hull[i].y)].size();j++) {
            win.push_back(has[make_pair(hull[i].x,hull[i].y)][j]);
        }
    }
    sort(win.begin(),win.end());
    for (int i=0;i<win.size();i++) printf("%d ",win[i]);
    printf("\n");

    return 0;
}