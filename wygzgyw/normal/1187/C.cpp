#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
const int INF=(1e8);
int n,m,a,b,t;
pair<int,int> d[maxn],e[maxn];
pair<int,int> c[maxn];
int ans[maxn],cnt;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); int op,x,y;
	for (int i=1;i<=m;i++) {
		read(op); read(x); read(y);
		if (op) d[++a]=make_pair(x,y);
		else e[++b]=make_pair(x,y);
	}
	sort(d+1,d+a+1);
	int l=0,r=0;
	for (int i=1;i<=a;i++) {
		if (r<d[i].first) {
			if (l) c[++t]=make_pair(l,r);
			l=d[i].first;
		}
		r=max(r,d[i].second);
	}
	c[++t]=make_pair(l,r);
	for (int i=1;i<=b;i++)
	for (int j=1;j<=t;j++)
		if (c[j].first<=e[i].first&&e[i].second<=c[j].second) {
			printf("NO\n"); return 0;
		}
	printf("YES\n");
	for (int i=1;i<=n;i++) ans[i]=n-i+1;
	for (int i=1;i<=t;i++)
		reverse(ans+c[i].first,ans+c[i].second+1);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}