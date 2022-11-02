#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=110;
const int INF=(1e9);
int n,r,dp[maxn][60010],ans;
struct node {
	int a,b;
} d[maxn],e[maxn];
int t1,t2;
bool cmp1(node x,node y) {
	return x.a<y.a;
}
bool cmp2(node x,node y) {
	return x.a+x.b>y.a+y.b;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(r); int a,b;
	for (int i=1;i<=n;i++) {
		read(a); read(b);
		if (b>=0) d[++t1]=(node){a,b};
		else e[++t2]=(node){max(a,-b),b};
	}
	sort(d+1,d+t1+1,cmp1);
	sort(e+1,e+t2+1,cmp2);
	int pos=1;
	while (r>=d[pos].a&&pos<=t1) {
		r+=d[pos].b;
		pos++;
	}
	//printf("%d %d\n",pos,r);
	for (int i=0;i<=t2;i++)
	for (int t=0;t<=r;t++)
		dp[i][t]=-INF;
	dp[0][r]=ans=pos-1;
	for (int i=0;i<t2;i++) {
		for (int t=0;t<=r;t++) {
			dp[i+1][t]=dp[i][t];
			//printf("%d %d %d\n",i,t,dp[i][t]);
			if (t>=e[i+1].a&&t+e[i+1].b>=0)
				dp[i+1][t+e[i+1].b]=max(dp[i+1][t+e[i+1].b],dp[i][t]+1);
		}
	}
	for (int t=0;t<=r;t++)
		ans=max(ans,dp[t2][t]);
	printf("%d\n",ans);
	return 0;
}