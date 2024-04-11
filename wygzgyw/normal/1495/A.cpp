#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int T,n;
ll a[maxn],b[maxn];
double ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		int t1=0,t2=0,x,y; ans=0;
		for (int i=1;i<=n*2;i++) {
			read(x),read(y);
			if (!x) a[++t1]=abs(y);
			else b[++t2]=abs(x);
		}
		sort(a+1,a+t1+1),sort(b+1,b+t2+1);
		for (int i=1;i<=n;i++) {
			ans+=sqrt((a[i]*a[i]+b[i]*b[i])*1.0);
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/