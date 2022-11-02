#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
const ll INF=1e18;
int T,cnt;
int n,m,k,now;
struct node { int x,y,z; } d[maxn];
int fa[maxn];
ll tmp,ans;
bool cmp(node A,node B) { return A.z<B.z; }
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main() {
	//freopen("1.txt","r",stdin);
	int x,y;
	read(T);
	while (T--) {
		read(n),read(m),read(k);
		cnt=n;
		for (int i=1;i<=n;i++) fa[i]=i;
		tmp=INF;
		for (int i=1;i<=m;i++) {
			read(d[i].x),read(d[i].y),read(d[i].z);
			tmp=min(tmp,(ll)abs(k-d[i].z));
		}
		sort(d+1,d+m+1,cmp);
		ans=0;
		for (int i=1;i<=m;i++) {
			x=find(d[i].x),y=find(d[i].y);
			if (x!=y) {
				cnt--,fa[x]=y;
				if (d[i].z>k) ans+=d[i].z-k;
			}
			if (cnt==1) { ans=max(ans,tmp); break; }
		}
		printf("%lld\n",ans);
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