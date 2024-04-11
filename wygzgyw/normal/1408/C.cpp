#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int T,n,a[maxn],L;
double solve1(double mid) {
	double res=0,t=0;
	for (int i=1;i<=n;i++) {
		if (t+(a[i]-res)*1.0/i>mid) return res+(mid-t)*i;
		t+=(a[i]-res)*1.0/i,res=a[i];
	}
	return res+(mid-t)*(n+1);
}
double solve2(double mid) {
	double res=L,t=0;
	for (int i=n;i>=1;i--) {
		if (t+(res-a[i])*1.0/(n-i+1)>mid) return res-(mid-t)*(n-i+1);
		t+=(res-a[i])*1.0/(n-i+1),res=a[i];
	}
	return res-(mid-t)*(n+1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(L);
		for (int i=1;i<=n;i++) read(a[i]);
		double l=0,r=1e18,mid;
		for (int i=1;i<=90;i++) {
			mid=(l+r)*0.5;
			if (solve1(mid)<=solve2(mid)) l=mid;
			else r=mid;
		}
		printf("%.9lf\n",(l+r)*0.5);
	}
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