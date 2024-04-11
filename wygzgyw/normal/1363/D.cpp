#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int T,n,mx,m,ans[maxn];
vector<int> S[maxn],A;
char R[maxn];
bool vis[maxn];
int query(vector<int> a) {
	printf("? %d ",a.size());
	for (int i=0;i<a.size();i++) printf("%d ",a[i]);
	printf("\n");
	fflush(stdout);
	int x; scanf("%d",&x); return x;
}
int main() {
	int x,y,l,r,mid,res,tmp;
	scanf("%d",&T);
	while (T--) {
		scanf("%d %d",&n,&m);
		for (int i=1;i<=m;i++) {
			S[i].clear();
			scanf("%d",&x);
			while (x--) {
				scanf("%d",&y);
				S[i].push_back(y);
			}
		}
		A.clear(); for (int i=1;i<=n;i++) A.push_back(i);
		mx=query(A);
		l=1,r=m,res=m;
		while (l<=r) {
			mid=(l+r)/2;
			A.clear();
			for (int i=1;i<=mid;i++)
			for (int j=0;j<S[i].size();j++) A.push_back(S[i][j]);
			if (A.size()==n) tmp=mx;
			else tmp=query(A);
			if (tmp==mx) res=mid,r=mid-1;
			else l=mid+1;
		}
		A.clear();
		for (int i=1;i<=n;i++) vis[i]=0;
		for (int i=0;i<S[res].size();i++) vis[S[res][i]]=1;
		for (int i=1;i<=n;i++) if (!vis[i]) A.push_back(i);
		ans[res]=query(A);
		for (int i=1;i<=m;i++)
			if (i!=res) ans[i]=mx;
		printf("! ");
		for (int i=1;i<=m;i++) printf("%d ",ans[i]); printf("\n");
		fflush(stdout);
		scanf("%s",R+1);
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