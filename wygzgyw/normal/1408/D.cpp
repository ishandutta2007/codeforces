#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
const int maxn=(1e6)+10;
int n,m,a[2010],b[2010],c[2010],d[2010];
int suf[maxn],ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) read(a[i]),read(b[i]);
	for (int i=1;i<=m;i++) read(c[i]),read(d[i]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		if (a[i]<=c[j]&&b[i]<=d[j]) {
			suf[c[j]-a[i]+1]=max(suf[c[j]-a[i]+1],d[j]-b[i]+1);
		}
	for (int i=maxn-2;i>=0;i--) suf[i]=max(suf[i+1],suf[i]);
	ans=INF;
	for (int i=0;i<maxn;i++)
		ans=min(ans,i+suf[i+1]);
	printf("%d\n",ans);
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