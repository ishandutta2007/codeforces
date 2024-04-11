#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const double pi=acos(-1.0);
const double eps=1e-10;
double r;
struct node {
	double x,y;
	friend node operator + (node t1,node t2) {
		return (node){t1.x+t2.x,t1.y+t2.y};
	}
	friend node operator - (node t1,node t2) {
		return (node){t1.x-t2.x,t1.y-t2.y};
	}
	friend double operator * (node t1,node t2) {
		return t1.x*t2.x+t1.y*t2.y;
	}
	friend double operator & (node t1,node t2) {
		return t1.x*t2.y-t1.y*t2.x;
	}
	friend bool operator == (node t1,node t2) {
		return abs(t1.x-t2.x)<eps&&abs(t1.y-t2.y)<eps;
	}
};
double dis(node A) { return sqrt(A.x*A.x+A.y*A.y); }
struct Poly {
	int n;
	node d[1010],p;
	void init() {
		scanf("%lf %lf",&p.x,&p.y);
		read(n);
		for (int i=1;i<=n;i++) scanf("%lf %lf",&d[i].x,&d[i].y);
		d[n+1]=d[1];
	}
} T1,T2;
double Min(node C,node A,node B) {
	if (A==B) return dis(C-A);
	node t1=C-A,t2=C-B,t3=B-A;
	if (t1*t3<0) return dis(t1);
	if (t2*t3>0) return dis(t2);
	return abs((t1&t2)/dis(t3));
}
double Max(node C,node A,node B) {
	return max(dis(C-A),dis(C-B));
}
void solve() {
	node C;
	double L,R;
	for (int i=1;i<=T1.n;i++) {
		C=T2.p+(T1.d[i]-T1.p);
		for (int j=1;j<=T2.n;j++) {
			L=Min(C,T2.d[j],T2.d[j+1]);
			R=Max(C,T2.d[j],T2.d[j+1]);
            //printf("%d %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",j+1,L,r,R,C.x,C.y,T2.d[j+1].x,T2.d[j+1].y);
			if (L<=r&&r<=R) { printf("YES\n"); exit(0); }
		}
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	T1.init();
	T2.init();
	r=dis(T1.p-T2.p);
	solve();
	swap(T1,T2);
	solve();
	printf("NO\n");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/