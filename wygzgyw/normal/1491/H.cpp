#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,q,block;
ll a[maxn],lazy[maxn];
int tot,L[maxn],R[maxn],bel[maxn];
int A(int x) {
	if (x==1) return 0;
	return max(1LL,a[x]-lazy[bel[x]]);
}
int cnt[maxn],f[maxn];
void update(int x,int delta) {
	cnt[x]+=delta;
	if (cnt[x]>block+5) return;
	int tmp;
	for (int i=L[x];i<=R[x];i++) {
		tmp=A(i);
		if (tmp<L[x]) f[i]=i;
		else f[i]=f[tmp];
	}
}
int lca(int x,int y) {
	while (f[x]!=f[y]) {
		if (A(f[x])<A(f[y])) swap(x,y);
		x=A(f[x]);
	}
	while (x!=y) {
		if (x<y) swap(x,y);
		x=A(x);
	}
	return x;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q); int op,l,r,x,y;
	for (int i=2;i<=n;i++) read(a[i]);
	block=sqrt(1.0*n);
	for (int l=1,r;l<=n;l=r+1) {
		r=min(n,l+block-1);
		L[++tot]=l,R[tot]=r;
		for (int i=l;i<=r;i++) bel[i]=tot;
		update(tot,0);
	}
	while (q--) {
		read(op);
		if (op==1) {
			read(l),read(r),read(x);
			if (bel[l]==bel[r]) {
				for (int i=l;i<=r;i++) a[i]-=x;
				update(bel[l],0);
			} else {
				for (int i=l;i<=R[bel[l]];i++) a[i]-=x;
				for (int i=L[bel[r]];i<=r;i++) a[i]-=x;
				update(bel[l],0), update(bel[r],0);
				for (int i=bel[l]+1;i<bel[r];i++) {
					lazy[i]+=x;
					update(i,1);
				}
			}
		} else {
			read(x),read(y);
			printf("%d\n",lca(x,y));
		}
	}
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