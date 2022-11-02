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
int n,a[maxn];
int st[maxn][20],lg[maxn];
struct node { int l,r,val; } d[maxn];
int tot,ans,mx;
int query(int l,int r) {
	int j=lg[r-l+1];
	return __gcd(st[l][j],st[r-(1<<j)+1][j]);
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),st[i][0]=a[i];
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=19;i++) for (int j=1;j+(1<<i)-1<=n;j++)
		st[j][i]=__gcd(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for (int i=1;i<=n;i++) {
		d[tot=1]=(node){i,i,a[i]};
		while (1) {
			int l=1,r=d[tot].l-1,mid,res=-1;
			if (l>r) break;
			d[++tot].val=query(r,i);
			while (l<=r) {
				mid=(l+r)>>1;
				if (query(mid,i)==d[tot].val) res=mid,r=mid-1; else l=mid+1;	
			}
			d[tot].r=d[tot-1].l-1;
			d[tot].l=res;
		}
		//for (int j=tot;j>=1;j--) printf("(%d,%d,%d)",d[j].l,d[j].r,d[j].val);
		//puts("");
		for (int j=tot;j>=1;j--) {
			if (d[j].val>=i-d[j].r+1&&d[j].val<=i-d[j].l+1) {
				int l=i-d[j].val+1,r=i;
				//printf("fd %d %d\n",l,r);
				if (l>mx) mx=r,ans++;
			}
		}
		printf("%d ",ans);
	}
	puts("");
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