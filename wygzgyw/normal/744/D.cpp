// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=2010;
const double eps=1e-10;
const double PIE=acos(-1.0);
struct node {
	double x,y;
} p[maxn];
int n,m;
double dis(node A,node B) { return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y); }
vector<pair<double,int> > vec;
void add(double l,double r,int x) {
	vec.push_back(MP(l,x));
	vec.push_back(MP(r,-x));
}
bool check(int i,double mid) {
	vec.clear();
	if (i<=n) add(0,PIE*2,1);
	for (int j=1;j<=n+m;j++) if (i!=j) {
		double d=sqrt(dis(p[i],p[j]))*0.5;
		if (d>mid-eps) continue;
		double M=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
		double theta=acos(d/mid);
		double l=M-theta,r=M+theta;
		if (l<0) l+=PIE*2; if (l>PIE*2) l-=PIE*2;
		if (r<0) r+=PIE*2; if (r>PIE*2) r-=PIE*2;
		int delta=(j<=n?1:-(n+m)-1);
		if (l<r) {
			add(l,r,delta);
		} else {
			add(l,PIE*2,delta),add(0,r,delta);
		}
	}
	//printf("%.5lf %d %d\n",mid,i,(int)vec.size());
	sort(vec.begin(),vec.end());
	int now=0;
	for (int j=0;j<vec.size();j++) {
		if (now>0&&j!=0&&vec[j].first>vec[j-1].first+eps) return 1;
		now+=vec[j].second;
	}
	return 0;
}
int main() {
	read(n),read(m);
	for (int i=1;i<=n;i++) read(p[i].x),read(p[i].y);
	for (int i=1;i<=m;i++) read(p[i+n].x),read(p[i+n].y);
	double ans=0;
	double l=0,r=1e9;
	for (int i=1;i<=n+m;i++) if (i==1||check(i,l)) {
		r=1e9;
		while (r-l>1e-5) {
			double mid=(l+r)*0.5;
			if (check(i,mid)) l=mid; else r=mid;
		}
		ans=max(ans,r);
	}
	if (ans>(9e8)) puts("-1");
	else printf("%.10lf\n",ans);
	return 0;
}