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
int T,n,a[maxn],b[maxn],tot;
vector<int> g[maxn];
int cnt[maxn];
set<int> S;
namespace Seg {
	int tr[maxn*4];
	void change(int x,int l,int r,int root,int delta) {
		if (l==r) { tr[root]=delta; return; }
		int mid=(l+r)>>1;
		if (x<=mid) change(x,l,mid,root<<1,delta);
		else change(x,mid+1,r,root<<1|1,delta);
		tr[root]=max(tr[root<<1],tr[root<<1|1]);
	}
	int query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)>>1,res=0;
		if (L<=mid) res=query(L,R,l,mid,root<<1);
		if (mid<R) res=max(res,query(L,R,mid+1,r,root<<1|1));
		return res;
	}
};
void del(int x) {
	cnt[a[x]]--;
	g[a[x]].pop_back();
	if ((int)g[a[x]].size()) Seg::change(a[x],0,n,1,g[a[x]].back());
	else Seg::change(a[x],0,n,1,0),S.insert(a[x]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); S.clear();
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=0;i<=n;i++) g[i].clear(),cnt[i]=0;
		for (int i=n;i>=1;i--) g[a[i]].push_back(i),cnt[a[i]]++;
		int mex=n+1;
		for (int i=0;i<=n;i++) if (cnt[i]) Seg::change(i,0,n,1,g[i].back()); else Seg::change(i,0,n,1,0),S.insert(i);
		S.insert(n+1); tot=0;
		for (int i=1,j;i<=n;i=j+1) {
			mex=*S.begin();
			if (mex==0) { for (;i<=n;i++) b[++tot]=0; break; }
			b[++tot]=mex;
			j=Seg::query(0,mex-1,0,n,1);
			for (int k=i;k<=j;k++) del(k);
		}
		printf("%d\n",tot);
		for (int i=1;i<=tot;i++) printf("%d ",b[i]); puts("");
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