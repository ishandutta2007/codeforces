#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,m,ans[maxn],dy[maxn];
struct node { int x,y,id; } d[maxn],a[maxn];
bool cmp(node a,node b) { return a.x<b.x; }
bool cmp2(node a,node b) {
	if (a.x==b.x) return a.id<b.id;
	return a.x>b.x;
}
int tr[maxn];
void add(int x) {
	for (;x<=n;x+=x&(-x)) tr[x]++;
}
int query(int x) {
	int res=0;
	for (;x;x-=x&(-x)) res+=tr[x];
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i].x),a[i].id=i,dy[i]=a[i].x;
	sort(a+1,a+n+1,cmp2);
	read(m);
	for (int i=1;i<=m;i++)
		read(d[i].x),read(d[i].y),d[i].id=i;
	sort(d+1,d+m+1,cmp);
	int pos=1,l,r,mid,res;
	add(a[1].id);
	for (int i=1;i<=m;i++) {
		while (pos<=n&&pos<d[i].x) {
			add(a[pos+1].id); pos++;
		}
		l=1,r=n;
		while (l<=r) {
			mid=(l+r)/2;
			if (query(mid)>=d[i].y) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans[d[i].id]=dy[res];
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
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