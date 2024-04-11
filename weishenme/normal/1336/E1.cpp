#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
int n,m,x,a[40],dp[2][40][1<<16],ans[40],num[1<<20],cnt,p[40],v[40];
void dfs(int x,int y){
	if (x==m){
		int s=0;
		while (y)s+=y&1,y>>=1;
		ans[s]++;
		return;
	}
	dfs(x+1,y);
	if (a[x])dfs(x+1,y^a[x]);
}
void insert(int x){
	for (int i=m-1;i>=0;i--)
		if ((1ll<<i)&x){
			if (a[i])x^=a[i];
			else {
				a[i]=x;
				return;
			}
		}
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&x);
		insert(x);
	}
	for (int i=0;i<m;i++)
		if (a[i]){
			cnt++;
			for (int j=i+1;j<m;j++)
				if (a[j]&(1ll<<i))a[j]^=a[i];
		}
	for (int i=0;i<1<<20;i++){
		int j=i;
		while (j)num[i]+=j&1,j>>=1;
	}
	if (cnt<=20)dfs(0,0);
	else {
		int tot=0;
		for (int i=0;i<m;i++)
			if (!a[i])p[i]=1<<tot,tot++;
		for (int i=0;i<m;i++)
			for (int j=0;j<i;j++)
				if ((1ll<<j)&a[i])assert(p[j]),v[i]+=p[j];
		dp[0][0][0]=1;
		for (int i=0;i<m;i++){
			int t=i&1;t^=1;
			memset(dp[t],0,sizeof dp[t]);
			for (int j=0;j<=i;j++)
				for (int k=0;k<1<<tot;k++)if (dp[t^1][j][k]){
					(dp[t][j][k]+=dp[t^1][j][k])%=M;
					if (a[i])(dp[t][j+1][k^v[i]]+=dp[t^1][j][k])%=M;
				}
		}
		for (int i=0;i<=m;i++)
			for (int j=0;j<1<<tot;j++)
				if (dp[m&1][i][j])(ans[i+num[j]]+=dp[m&1][i][j])%=M;
	}
	int v=1;
	for (int i=1;i<=n-cnt;i++)(v*=2)%=M;
	for (int i=0;i<=m;i++)printf("%lld ",ans[i]*v%M);
}