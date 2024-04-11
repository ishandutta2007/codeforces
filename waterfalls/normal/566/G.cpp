#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct Point {
	ll x,y;
	Point(ll a=0, ll b=0) { x = a, y = b; }
	Point(Point a, Point b) { x = b.x-a.x, y = b.y-a.y; }
	void rot() { swap(x,y), x = -x; }
	bool operator<(Point b) const {
		if (x!=b.x) return x<b.x;
		return y<b.y;
	}
	bool operator==(Point b) const { return x==b.x && y==b.y; }
};
bool cw(Point a, Point b, Point c, int w) {
	a = Point(a,b);
	b = Point(b,c);
	b.rot();
	return (a.x*b.x+a.y*b.y)*w>=0;
}

vector<Point> envelope(vector<Point>& X, int w) {
    vector<Point> res;
    for (Point x: X) {
	    while (res.size()>=2 && !cw(res[res.size()-2],res.back(),x,w)) res.pop_back();
	    res.push_back(x);
    }
    return res;
}

vector<Point> makehull(vector<Point> X) {
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	vector<Point> a = envelope(X,1);
	return a;
}

pair<ll,ll> fix(vector<Point>& X) {
	ll top = 0;
	for (Point x: X) top = max(top,x.y);
	X.push_back({0,top});
	ll right = 0;
	for (Point x: X) right = max(right,x.x);
	X.push_back({right,0});
	return make_pair(top,right);
}

bool hasnone(vector<Point> A, vector<Point> B) {
	A.insert(A.end(),B.begin(),B.end());
	int one = A.size();
	sort(A.begin(),A.end());
	A.erase(unique(A.begin(),A.end()),A.end());
	int two = A.size();
	return one==two;
}

int n,m;
vector<Point> maxs;
vector<Point> both;

int main() {
	scanf("%d%d%*d%*d",&n,&m);
	for (int i=0;i<n;i++) {
		Point p;
		scanf("%lld%lld",&p.x,&p.y);
		maxs.push_back(p);
	}
	for (int i=0;i<m;i++) {
		Point p;
		scanf("%lld%lld",&p.x,&p.y);
		both.push_back(p);
	}
	pair<ll,ll> one = fix(both);
	pair<ll,ll> two = fix(maxs);
	if (two.first>=one.first || two.second>=one.second) return printf("Max\n"), 0;
	for (int i=0;i<maxs.size();i++) if (maxs[i].x==0) maxs.erase(maxs.begin()+i);
	both.insert(both.end(),maxs.begin(),maxs.end());
	maxs = makehull(maxs);
	both = makehull(both);
	printf("%s\n",((hasnone(maxs,both)) ? "Min" : "Max"));

	return 0;
}