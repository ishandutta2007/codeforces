#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(5e5)+10;
int n,m,k,c[maxn],fa[maxn*2],sz[maxn*2];
ll ans;
int tot,ok[maxn],now;
int find(int x) {
	if (fa[x]==x) return x;
	return find(fa[x]);
}
struct Change { int x,y,szy,fax; } st[maxn*10];
void merge(int x,int y) {
	x=find(x),y=find(y);
	if (x==y) return;
	if (sz[x]>sz[y]) swap(x,y);
	st[++tot]=(Change){x,y,sz[y],fa[x]};
	sz[y]+=sz[x],fa[x]=y;
}
bool link(int x,int y) {
	if (find(x)==find(y)) return 0;
	merge(x+n,y);
	merge(x,y+n);
	return 1;
}
int N;
struct node { int cx,cy,x,y; } d[maxn];
bool cmp(node A,node B) {
	if (A.cx==B.cx) return A.cy<B.cy;
	return A.cx<B.cx;
}
int main() {
	//freopen("b1.in","r",stdin);
	read(n),read(m),read(k);
	for (int i=1;i<=n;i++) read(c[i]);
	for (int i=1;i<=n*2;i++) fa[i]=i,sz[i]=1;
	for (int i=1;i<=k;i++) ok[i]=1;
	int x,y;
	for (int i=1;i<=m;i++) {
		read(x),read(y);
		if (c[x]>c[y]) swap(x,y);
		if (c[x]==c[y]) {
			if (!link(x,y)) ok[c[x]]=0;
		} else {
			d[++N]=(node){c[x],c[y],x,y};
		}
	}
	int cnt=0;
	for (int i=1;i<=k;i++) if (ok[i]) cnt++;
	ans=(ll)cnt*(cnt-1)/2;
	sort(d+1,d+N+1,cmp);
	int lst=1;
	now=tot;
	for (int i=1;i<=N;i++) if (i==N||make_pair(d[i].cx,d[i].cy)!=make_pair(d[i+1].cx,d[i+1].cy)) {
		
		for (int j=lst;j<=i;j++) if (ok[d[i].cx]&&ok[d[i].cy]) {
			//if (d[i].cx==4&&d[i].cy==57) printf("%d %d\n",d[j].x,d[j].y);
			if (!link(d[j].x,d[j].y)) {
				//printf("%d %d\n",d[i].cx,d[i].cy);
				ans--; break;
			}
		}
		lst=i+1;
		while (tot>now) {
			sz[st[tot].y]=st[tot].szy;
			fa[st[tot].x]=st[tot].fax;
			tot--;
		}
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