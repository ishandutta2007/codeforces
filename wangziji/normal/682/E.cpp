#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
const long long eps = 1e-8;
const long long maxn = 200005;

struct point {
	long long x, y;
	point(long long x = 0, long long y = 0):x(x),y(y) {};
};
struct segment { //
	point a, b;
};

long long dis(point p1, point p2) {
	return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));   //
}
long long cross(point A,point B) {
	return A.x*B.y-A.y*B.x;   //
}
//p2p0p10()
long long cross(point p0,point p1,point p2) {
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
long long min(long long a, long long b, long long c) {
	return min(a, min(b, c));
}
long long max(long long a, long long b, long long c) {
	return max(a, max(b, c));
}
long long dcmp(ll x) { //x=0(0), >0(1), <0(-1);
	if(x==0) return 0;
	return x<0?-1:1;
}
point operator + (point A,point B) {
	return point(A.x+B.x,A.y+B.y);
}
point operator - (point A,point B) {
	return point(A.x-B.x,A.y-B.y);
}
point operator * (point A,long long p) {
	return point(A.x*p,A.y*p);
}
point operator / (point A,long long p) {
	return point(A.x/p,A.y/p);
}
bool operator == (point A,point B) {
	return dcmp(A.x - B.x)==0&&dcmp(A.y-B.y)==0;
}

bool Exclusion(segment p,segment q) { //
	if(min(p.a.x,p.b.x)-max(q.a.x,q.b.x)>eps||min(p.a.y,p.b.y)-max(q.a.y,q.b.y)>eps||min(q.a.x,q.b.x)-max(p.a.x,p.b.x)>eps||min(q.a.y,q.b.y)-max(p.a.y,p.b.y)>eps)
		return 0;
	return 1;
}
bool Straddling(segment p,segment q) { //
	if(dcmp(cross(p.b-p.a,q.a-p.a))*dcmp(cross(p.b-p.a,q.b-p.a))<=0&&dcmp(cross(q.b-q.a,p.a-q.a))*dcmp(cross(q.b-q.a,p.b-q.a))<=0)
		return 1;
	return 0;
}
bool check(segment p,segment q) { //
	if(Exclusion(p, q) && Straddling(p,q))
		return 1;
	return 0;
}
/*------------------------------------------------------------------------------------*/

point plist[maxn], pstack[maxn],X,Y,Z;
bool cmp(const point &p1, const point &p2) {
	long long tmp = cross(plist[0], p1, p2);
	if (tmp > 0.0)return true;
	else if (tmp == 0.0 && dis(plist[0], p1) < dis(plist[0], p2))return true;
	else return false;
}

void init(long long n) {
	long long k = 0;
	scanf("%lld%lld", &plist[0].x, &plist[0].y);
	for (long long i = 1; i < n; i++) {
		scanf("%lld%lld", &plist[i].x, &plist[i].y);
		if ((plist[k].y > plist[i].y) || ((plist[k].y == plist[i].y) && (plist[k].x > plist[i].x)))
			k = i;
	}
	swap(plist[0], plist[k]);
	sort(plist+1,plist+n,cmp);
}

long long Graham(long long n) {
	if(n == 1)
		return 1;
	long long top = 1;
	pstack[0] = plist[0];
	pstack[1] = plist[1];
	for (long long i = 2; i < n; i++) {
		while (top>0 && cross(pstack[top - 1], pstack[top], plist[i]) <= 0)top--;
		pstack[++top] = plist[i];
	}
	return top + 1;
}

long long convex_minlen(long long n) {
	if(n == 1)
		return 0;
	if(n == 2)
		return dis(pstack[0], pstack[1]);
	long long ans = 0;
	long long k = 0;
	pstack[n] = pstack[0];
	for (long long i = 0; i < n; i++) {
		while(cross(pstack[i], pstack[i + 1], pstack[k]) < cross(pstack[i], pstack[i + 1], pstack[k + 1])) {
			k = (k + 1) % n;
		}
		long long t1 = dis(pstack[i], pstack[k]);
		long long t2 = dis(pstack[i + 1], pstack[k]);
		ans = max(ans, t1, t2);
	}
	return ans;
}
long long convex_maxlen(long long n) {
	if(n == 1)
		return 0;
	if(n == 2)
		return dis(pstack[0], pstack[1]);
	long long ans = 0;

	for (long long i = 0; i < n - 1; i++) {
		long long k = 0;
		for (long long j = i + 1; j < n; j++) {
			while (cross(pstack[i], pstack[j], pstack[k]) < cross(pstack[i], pstack[j], pstack[k + 1])) {
				k = (k + 1) % n;
			}
			if(cross(pstack[i], pstack[j], pstack[k])>ans) ans=cross(pstack[i], pstack[j], pstack[k]),X=pstack[i],Y=pstack[j],Z=pstack[k];
		}
	}
	return ans;
}
signed main() {
	long long n,s;
	scanf("%lld%lld",&n,&s);
	init(n);
	n = Graham(n);
	long long ans = convex_maxlen(n);
	point a[10]={X+Y-Z,X-Y+Z,Y+Z-X};
//	cout << X.x << " " << X.y << "*\n";
//	cout << Y.x << " " << Y.y << "*\n";
//	cout << Z.x << " " << Z.y << "*\n";
	for(int i=0;i<=2;i++)
	{
	//	cout << a[i].x << " " << a[i].y << "\n";
		cout << a[i].x << " " << a[i].y << "\n";
	}
	return 0;
}