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
const int maxn=(2e5)+10;
const int maxm=(2e6)+10;
int T,n,k,a[maxn],b[maxn];
int lsh[maxn],N;
set<int> tr[maxn*4];
int sz[maxn*4];
void Add(int L,int R,int l,int r,int root,int x) {
	if (L<=l&&r<=R) { tr[root].insert(x); return; }
	int mid=(l+r)>>1;
	if (L<=mid) Add(L,R,l,mid,root<<1,x);
	if (mid<R) Add(L,R,mid+1,r,root<<1|1,x);
}
void Del(int L,int R,int l,int r,int root,int x) {
	if (L<=l&&r<=R) { tr[root].erase(x); return; }
	int mid=(l+r)>>1;
	if (L<=mid) Del(L,R,l,mid,root<<1,x);
	if (mid<R) Del(L,R,mid+1,r,root<<1|1,x);
}
int res,FLAG;
void dfs(int x,int l,int r,int root) {
	if (FLAG) return;
	for (int y : tr[root]) {
		if (!res) res=y; else if (res) { FLAG=1; break; }
	}
	if (l==r) {
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) dfs(x,l,mid,root<<1);
	else dfs(x,mid+1,r,root<<1|1);
}
int F(int x) { return lower_bound(lsh+1,lsh+N+1,x)-lsh; }
multiset<int> S; int B[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T); while (T--) {
		read(n),read(k);
		for (int i=1;i<=n;i++) read(a[i]),read(b[i]),B[i]=b[i],b[i]+=a[i];
		if (a[1]>=k) { puts("YES"); continue; }
		if (k>b[1]) { puts("NO"); continue; }
		k-=B[1]; bool flag=0;
		for (int i=2;i<=n;i++) if (a[i]>=k) { flag=1; break; }
		if (flag) { puts("YES"); continue; }
		N=0; lsh[++N]=0;
		for (int i=1;i<=n;i++) lsh[++N]=a[i],lsh[++N]=b[i]+1;
		sort(lsh+1,lsh+N+1),N=unique(lsh+1,lsh+N+1)-lsh-1;
		for (int i=1;i<=N*4;i++) tr[i].clear();
		S.clear();
		for (int i=2;i<=n;i++) Add(F(a[i]),F(b[i]+1)-1,1,N,1,i),S.insert(a[i]);
		while (k>=0) {
			int x=upper_bound(lsh+1,lsh+N+1,k)-lsh-1;
			res=0; FLAG=0;
			dfs(x,1,N,1);
			if (FLAG) { flag=1; break; }
			if (!res) { flag=0; break; }
			S.erase(S.find(a[res]));
			if ((int)S.size()&&(*--S.end())>=k-B[res]) { flag=1; break; }
			Del(F(a[res]),F(b[res]+1)-1,1,N,1,res);
			k-=B[res];
		}
		if (flag) puts("YES"); else puts("NO");
	}
	return 0;
}