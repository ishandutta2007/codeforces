#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,q,d[maxn],mx,ans;
struct node { int l,r,cnt; } a[maxn];
bool cmp(node a,node b) { return a.l<b.l; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(q);
	for (int i=1;i<maxn;i++) a[i].l=n+1;
	for (int i=1;i<=n;i++) {
		read(d[i]);
		a[d[i]].l=min(a[d[i]].l,i);
		a[d[i]].r=max(a[d[i]].r,i);
		a[d[i]].cnt++; mx=max(mx,d[i]);
	}
	sort(a+1,a+mx+1,cmp);
	int L=1,R=0,s=0;
	for (int i=1;i<=mx;i++) {
		if (!a[i].cnt) continue;
		if (R<a[i].l) ans+=R-L+1-s,L=a[i].l,R=a[i].r,s=0;
		s=max(s,a[i].cnt);
		R=max(R,a[i].r);
	}
	//printf("%d %d %d\n",L,R,s);
	ans+=R-L+1-s;
	printf("%d\n",ans);
	return 0;
}