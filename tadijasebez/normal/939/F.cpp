#include <bits/stdc++.h>
using namespace std;
void ckmn(int &x,int y){x=min(x,y);}
const int N=100050;
const int K=105;
const int inf=1e9+7;
int dp[2][2][N],n,k,l[K],r[K],tmp[2][N];
void mn(int a[],int ans[],int sz){
	deque<int> dq;
	for(int i=0;i<=n;i++){
		while(dq.size() && a[dq.back()]>a[i])dq.pop_back();
		dq.push_back(i);
		while(dq.size() && dq.front()<=i-sz)dq.pop_front();
		ans[i]=a[dq.front()];
	}
}
int main(){
	scanf("%i %i",&n,&k);
	for(int i=1;i<=k;i++)scanf("%i %i",&l[i],&r[i]);
	l[k+1]=n*2;
	int now=1,las=0;
	for(int i=0;i<=n;i++)dp[now][0][i]=dp[now][1][i]=inf;
	dp[now][0][0]=0;
	if(l[1]<=n)dp[now][1][l[1]]=0;
	//for(int j=0;j<=n;j++)printf("%i ",dp[now][0][j]);printf("\n");
	//for(int j=0;j<=n;j++)printf("%i ",dp[now][1][j]);printf("\n");
	for(int i=1;i<=k;i++){
		swap(now,las);
		int L=l[i+1]-r[i],R=l[i+1]-l[i];
		mn(dp[las][0],tmp[0],R-L+1);
		mn(dp[las][1],tmp[1],R-L+1);
		for(int j=0;j<=n;j++){
			dp[now][1][j]=inf;
			if(j>=R)ckmn(dp[now][1][j],dp[las][1][j-R]);
			if(j>=L)ckmn(dp[now][1][j],tmp[0][j-L]+1);
			//for(int z=L;z<=R;z++)if(j-z>=0)ckmn(dp[now][1][j],dp[las][0][j-z]+1);
			ckmn(dp[now][1][j],tmp[1][j]+2);
			//for(int z=0;z<=R-L;z++)if(j-z>=0)ckmn(dp[now][1][j],dp[las][1][j-z]+2);
			dp[now][0][j]=inf;
			ckmn(dp[now][0][j],dp[las][0][j]);
			ckmn(dp[now][0][j],tmp[1][j]+1);
			//for(int z=0;z<=R-L;z++)if(j-z>=0)ckmn(dp[now][0][j],dp[las][1][j-z]+1);
			ckmn(dp[now][0][j],tmp[0][j]+2);
			//for(int z=0;z<=R-L;z++)if(j-z>=0)ckmn(dp[now][0][j],dp[las][0][j-z]+2);
		}
		//for(int j=0;j<=n;j++)printf("%i ",dp[now][0][j]);printf("\n");
		//for(int j=0;j<=n;j++)printf("%i ",dp[now][1][j]);printf("\n");
	}
	int ans=min(dp[now][0][n],dp[now][1][n]);
	if(ans==inf)printf("Hungry\n");
	else printf("Full\n%i\n",ans);
	return 0;
}