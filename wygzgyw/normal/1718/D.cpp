// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(3e5)+10;
int T,n,st[maxn][20],lg[maxn];
int p[maxn],a[maxn],q;
int MX(int x,int y) { if (p[x]>p[y]) return x; return y; }
int query(int x,int y) {
	int j=lg[y-x+1];
	return MX(st[x][j],st[y-(1<<j)+1][j]);
}
int ls[maxn],rs[maxn];
int dfs(int l,int r) {
	if (l>r) return 0;
	if (l==r) return l;
	int mid=query(l,r);
	ls[mid]=dfs(l,mid-1);
	rs[mid]=dfs(mid+1,r);
	return mid;
}
struct node {
	int l,r;
} d[maxn];
int S[maxn];
set<int> s;
int L[maxn],R[maxn];
int INF=1e9;
void DFS(int x) {
	if (!x) return;
	if (ls[x]) R[ls[x]]=min(R[x],a[x]?a[x]:INF);
	if (rs[x]) R[rs[x]]=min(R[x],a[x]?a[x]:INF);
	DFS(ls[x]),DFS(rs[x]);
	L[x]=max(ls[x]==0?-INF:L[ls[x]],rs[x]==0?-INF:L[rs[x]]);
	if (a[x]) L[x]=max(L[x],a[x]);
}
bool cmp1(node A,node B) {
	if (A.r!=B.r) return A.r<B.r; return A.l>B.l;
}
bool cmp2(node A,node B) {
	if (A.l!=B.l) return A.l>B.l; return A.r<B.r;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(q);
		for (int i=1;i<=n;i++) read(p[i]),ls[i]=rs[i]=0;
		for (int i=1;i<=n;i++) st[i][0]=i;
		for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
		for (int i=1;i<=19;i++) for (int j=1;j+(1<<i)-1<=n;j++)
			st[j][i]=MX(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		int rt=dfs(1,n),cnt=0;
		for (int i=1;i<=n;i++) read(a[i]),cnt+=(a[i]==0);
		for (int i=1;i<cnt;i++) read(S[i]);
		R[rt]=INF;
		DFS(rt);
		int flag=1,x; cnt=0;
		//for (int i=1;i<=n;i++) printf("%d %d\n",L[i],R[i]);
		for (int i=1;i<=n;i++) {
			if (a[i]) {
				if (L[i]<=a[i]&&a[i]<=R[i]); else flag=0;
			} else d[++cnt]=(node){L[i],R[i]};//,printf("%d %d\n",L[i],R[i]);
		}
		//printf("%d %d\n",n,q);
		if (!flag) { while (q--) read(x),puts("NO"); continue; }
		int r1,r2,F=0;
		set<int>::iterator it;
		sort(d+1,d+cnt+1,cmp1);
		s.clear();
		for (int i=1;i<cnt;i++) s.insert(S[i]);
		for (int i=1;i<=cnt&&flag;i++) {
			it=s.lower_bound(d[i].l);
			if (it==s.end()||(*it)>d[i].r) {
				if (F) { flag=0; break; }
				r2=d[i].r,F=1;
			} else s.erase(it);
		}
		if (!flag) { while (q--) read(x),puts("NO"); continue; }
		sort(d+1,d+cnt+1,cmp2);
		s.clear();
		for (int i=1;i<cnt;i++) s.insert(S[i]);
		F=0;
		for (int i=1;i<=cnt&&flag;i++) {
			it=s.upper_bound(d[i].r);
			if (it==s.begin()||(*--it)<d[i].l) {
				if (F) { flag=0; break; }
				r1=d[i].l,F=1;
			} else s.erase(it);
		}
		if (!flag) { while (q--) read(x),puts("NO"); continue; }
		while (q--) {
			read(x);
			if (r1<=x&&x<=r2) puts("YES"); else puts("NO");
		}
		//exit(0);
	}
	return 0;
}