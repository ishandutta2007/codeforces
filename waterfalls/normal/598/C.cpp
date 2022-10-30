#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Point {
	ll x,y;
	int i;
	Point(ll a=0, ll b=0): x(a), y(b) {}
};

int n;
Point X[100013];

ll dot(Point a, Point b) { return a.x*b.x+a.y*b.y; }
ll cross(Point a, Point b) { return a.x*b.y-a.y*b.x; }

bool side(Point a) {
	if (a.y!=0) return a.y<0;
	return a.x<0;
}
bool operator<(Point a, Point b) {
	if (side(a)!=side(b)) return side(a)<side(b);
	return cross(a,b)>0;
}

bool comp(Point a, Point b, Point c, Point d) {
	return Point(dot(a,b),cross(a,b))<Point(dot(c,d),cross(c,d));
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%lld%lld",&X[i].x,&X[i].y);
		X[i].i = i;
	}
	sort(X,X+n);
	Point one = X[n-1], two = X[0];
	for (int i=0;i<n-1;i++) {
		if (comp(X[i],X[(i+1)%n],one,two)) {
			one = X[i];
			two = X[(i+1)%n];
		}
	}
	printf("%d %d\n",one.i+1,two.i+1);

	return 0;
}