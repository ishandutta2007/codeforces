#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
	ll x,y;
	Point(ll a=0, ll b=0) { x = a, y = b; }
	Point(Point a, Point b) { x = b.x-a.x, y = b.y-a.y; }
	void rot() { swap(x,y), x = -x; }
	bool operator<(Point b) const {
		if (x!=b.x) return x<b.x;
		return y>b.y;
	}
	bool operator==(Point b) const { return x==b.x && y==b.y; }
};
bool cw(Point a, Point b, Point c) {
	a = Point(a,b);
	b = Point(b,c);
	b.rot();
	return a.x*b.x+a.y*b.y>=0;
}

vector<Point> makehull(vector<Point>& X) {
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
    vector<Point> res;
    for (Point x: X) {
	    while (res.size()>=2 && !cw(res[res.size()-2],res.back(),x)) res.pop_back();
	    res.push_back(x);
    }
    return res;
}

int n,p,q;
int x[100013], y[100013];
vector<Point> pt;

int main() {
	scanf("%d%d%d",&n,&p,&q);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		pt.push_back({x[i],y[i]});
	}
	pt.push_back({*max_element(x,x+n),0});
	pt.push_back({0,*max_element(y,y+n)});
	pt = makehull(pt);
	for (int i=0;i<pt.size()-1;i++) {
		if (pt[i].y*p>=pt[i].x*q && pt[i+1].y*p<=pt[i+1].x*q) {
			Point s = Point(pt[i],pt[i+1]);
			printf("%1.12f\n",1.*(p*s.y-q*s.x)/(pt[i].x*s.y-pt[i].y*s.x));
			break;
		}
	}

	return 0;
}