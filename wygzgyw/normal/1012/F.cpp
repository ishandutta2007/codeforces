#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=0x7f7f7f7f;
int n,P,tmp;
struct node {
	int l,r,t,id;
} d[25];
int dp[1<<22],from[1<<22];
int a[25],b[25];
bool cmp(node x,node y) {
	return x.l<y.l;
}
inline void dfs(int p,int t) {
	if (!t) return;
	int x=d[from[t]].id;
	a[x]=p;
	b[x]=dp[t]-d[from[t]].t;
	dfs(p,t-(1<<(from[t]-1)));
}
int main() {
	read(n); read(P); int x;
	for (int i=1;i<=n;i++) {
		read(d[i].l); read(x);
		d[i].r=d[i].l+x-1;
		read(d[i].t); d[i].id=i;
	}
	sort(d+1,d+n+1,cmp);
	memset(dp,0x7f7f7f7f,sizeof(dp));
	dp[0]=1;
	for (register int t=1;t<(1<<n);++t) {
		for (register int i=1;i<=n;++i)
		if (t&(1<<(i-1))) {
			tmp=dp[t-(1<<(i-1))];
			if (tmp==INF) continue;
			for (register int j=1;j<=n;++j) {
				if (d[j].l<=tmp&&tmp<=d[j].r) tmp=d[j].r+1;
				if (tmp<d[j].l&&d[j].l<=tmp+d[i].t&&(t&(1<<(j-1))))
					tmp=d[j].r+1;
			}
			if (tmp+d[i].t<d[i].l&&tmp+d[i].t<dp[t])
				dp[t]=tmp+d[i].t,from[t]=i;
		}
	}
	if (P==1) {
		if (dp[(1<<n)-1]<INF) {
			dfs(1,(1<<n)-1);
			printf("YES\n");
			for (int i=1;i<=n;i++)
				printf("%d %d\n",a[i],b[i]);
		} else printf("NO\n");
	} else {
		for (int t=0;t<(1<<n);t++)
			if (dp[t]<INF&&dp[(1<<n)-1-t]<INF) {
				dfs(1,t); dfs(2,(1<<n)-1-t);
				printf("YES\n");
				for (int i=1;i<=n;i++)
					printf("%d %d\n",a[i],b[i]);
				return 0;
			}
		printf("NO\n");
	}
	return 0;
}