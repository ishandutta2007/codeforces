#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=5010;
const ll INF=1e18;
int n,s,t,nxt[maxn];
ll x[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
ll mn,tmp,ans;
int pos;
ll dis(int i,int j) {
	if (j<i) return abs(x[i]-x[j])+c[i]+b[j];
	return abs(x[i]-x[j])+d[i]+a[j];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(s),read(t); nxt[s]=t;
	for (int i=1;i<=n;i++) read(x[i]);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	for (int i=1;i<=n;i++) read(c[i]);
	for (int i=1;i<=n;i++) read(d[i]);
	ans=dis(s,t);
	for (int i=1;i<=n;i++) if (i!=s&&i!=t) {
		mn=INF;
		for (int j=s;j!=t;j=nxt[j]) {
			tmp=dis(j,i)+dis(i,nxt[j])-dis(j,nxt[j]);
			if (tmp<mn) mn=tmp,pos=j;
		}
		ans+=mn;
		nxt[i]=nxt[pos],nxt[pos]=i;
	}
    printf("%lld\n",ans);
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