#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
const int maxn=(4e5)+10;
int n,l,r,c1,c2,w1,w2,ans,p1,p2;
int mk[maxn],R[maxn],pre[maxn],suf[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(l),read(r);
		if (l>r) swap(l,r),mk[l]=1;
		if (l>n) { puts("-1"); return 0; }
		R[l]=r;
	}
	for (int i=n;i>=1;i--) suf[i]=max(suf[i+1],R[i]);
	pre[0]=INF; for (int i=1;i<=n;i++) pre[i]=min(pre[i-1],R[i]);
	for (int i=1;i<=n;i++) {
		if (!c1||R[i]<p1) p1=R[i],c1++,w1+=(mk[i]^1);
		else if (!c2||R[i]<p2) p2=R[i],c2++,w2+=mk[i];
		else { puts("-1"); return 0; }
		if (pre[i]>suf[i+1]) {
			ans+=min(c1+c2-w1-w2,w1+w2);
			p1=p2=c1=c2=w1=w2=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/