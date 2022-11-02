#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int T,n,d[maxn];
int pre[maxn],nxt[maxn];
set<int> s;
int tot,ans[maxn];
int gcd(int x,int y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
set<int>::iterator it;
int mk[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(d[i]),mk[i]=0;
		s.clear();
		for (int i=2;i<n;i++) pre[i]=i-1,nxt[i]=i+1;
		pre[1]=n,nxt[1]=2,pre[n]=n-1,nxt[n]=1;
		int now=1,x,a,b; tot=0;
		for (int i=1;i<=n;i++) if (gcd(d[i],d[pre[i]])==1) s.insert(i);
		while (s.size()&&n-tot>1) {
			it=s.upper_bound(now);
			if (it==s.end()) it=s.begin();
			x=*it; s.erase(it); mk[x]=1;
			a=pre[x],b=nxt[x];
			if (s.count(b)) s.erase(s.find(b));
			pre[b]=a,nxt[a]=b;
			ans[++tot]=x;
			now=b;
			if (n-tot==1) break;
			if (gcd(d[a],d[b])==1) s.insert(b);
		}
		if (n-tot==1) {
			int pos=0;
			for (int i=1;i<=n;i++) if (!mk[i]) pos=i;
			if (d[pos]==1) ans[++tot]=pos;
		}
		printf("%d ",tot);
		for (int i=1;i<=tot;i++) printf("%d ",ans[i]); puts("");
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