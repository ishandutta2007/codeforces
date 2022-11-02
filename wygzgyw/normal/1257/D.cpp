#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
const int maxn=(2e5)+10;
int T,n,m,lg[maxn],a[maxn];
int mx[maxn][20];
int K[maxn],ans,pos;
struct node { int p,s; } d[maxn];
bool cmp(node a,node b) { return a.p<b.p; }
int p[maxn];
bool solve(int mid) {
	int j=lg[mid-pos+1];
	int tmp=max(mx[pos][j],mx[mid-(1<<j)+1][j]);
	//printf("%d %d %d\n",pos,mid,tmp);
	if (p[m]<tmp) return 0;
	int x=lower_bound(p+1,p+m+1,tmp)-p;
	return K[x]>=mid-pos+1;
}
int main() {
	//freopen("1.txt","r",stdin);
	lg[1]=0;
	for (int i=2;i<maxn;i++) lg[i]=lg[i/2]+1;
	int l,r,mid,res;
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++)
			read(a[i]),mx[i][0]=a[i];
		for (int j=1;j<=19;j++)
		for (int i=1;i<=n;i++)
			if (i+(1<<j)-1<=n) mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
			else mx[i][j]=0;
		read(m);
		for (int i=1;i<=m;i++) read(d[i].p),read(d[i].s);
		sort(d+1,d+m+1,cmp);
		K[m+1]=0;
		for (int i=m;i>=1;i--) {
			p[i]=d[i].p;
			K[i]=max(K[i+1],d[i].s);
		}
		pos=1; ans=0;
		while (pos<=n) {
			l=pos,r=n; res=-1;
			while (l<=r) {
				mid=(l+r)/2;
				if (solve(mid)) l=mid+1,res=mid;
				else r=mid-1;
			}
			if (res==-1) { ans=-1; break; }
			ans++; pos=res+1;
		}
		printf("%d\n",ans);
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