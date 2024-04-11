#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,H,mn;
ll tmp,x[maxn],y[maxn];
double ans,theta,alpha,len;
ll cross(int i,int j) {
	return (x[i]-x[n-1])*(y[j]-y[n-1]-H)-(x[j]-x[n-1])*(y[i]-y[n-1]-H);
}
double dis(ll x,ll y) {
	return sqrt((x*x+y*y)*1.0);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(H);
	for (int i=0;i<n;i++) read(x[i]),read(y[i]);
	mn=n-1;
	for (int i=n-2;i>=0;i--) {
		tmp=cross(mn,i);
		if (tmp==0) {
			if (mn==i+1) {
				ans+=dis(x[i]-x[i+1],y[i]-y[i+1]);
			}
			mn=i;
		} else if (tmp<0) {
			theta=atan2(y[n-1]+H-y[mn],x[n-1]-x[mn])-atan2(y[n-1]+H-y[i],x[n-1]-x[i]);
			len=dis(y[n-1]+H-y[i],x[n-1]-x[i]);
			alpha=atan2(y[n-1]+H-y[i],x[n-1]-x[i])-atan2(y[i+1]-y[i],x[i+1]-x[i]);
			ans+=len*sin(theta)/sin(theta+alpha);
			mn=i;
		}
	}
	printf("%.16lf\n",ans);
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