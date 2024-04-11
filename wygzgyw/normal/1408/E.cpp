#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,m,a[maxn],b[maxn],fa[maxn*2],tot;
struct edge { int x,y; ll z; } d[maxn*2];
ll ans;
bool cmp(edge A,edge B) { return A.z>B.z; }
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(m); read(n);
	for (int i=1;i<=m;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	int x,y;
	for (int i=1;i<=m;i++) {
		read(x);
		while (x--) {
			read(y);
			d[++tot]=(edge){y+m,i,a[i]+b[y]};
		}
	}
	sort(d+1,d+tot+1,cmp);
	for (int i=1;i<=n+m;i++) fa[i]=i;
	for (int i=1;i<=tot;i++) {
		x=find(d[i].x),y=find(d[i].y);
		if (x==y) ans+=d[i].z;
		else fa[x]=y;
	}
	printf("%lld\n",ans);
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