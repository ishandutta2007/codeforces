#include<bits/stdc++.h>
using namespace std;
const int max_R=200+5;
const int max_G=200+5;
const int max_B=200+5;
int dp[max_R][max_G][max_B],r[max_R],g[max_G],b[max_B];
int main()
{
	int R,G,B;
	scanf("%d%d%d",&R,&G,&B);
	for(int i=1;i<=R;++i)
		scanf("%d",r+i);
	for(int i=1;i<=G;++i)
		scanf("%d",g+i);
	for(int i=1;i<=B;++i)
		scanf("%d",b+i);
	sort(r+1,r+R+1,greater<int>());
	sort(g+1,g+G+1,greater<int>());
	sort(b+1,b+B+1,greater<int>());
	memset(dp,128,sizeof(dp));
	dp[0][0][0]=0;
	int ans=0;
	for(int i=0;i<=R;++i)
		for(int j=0;j<=G;++j)
			for(int k=0;k<=B;++k)
			{
				int v=dp[i][j][k];
				if(v>=0)
				{
					ans=max(ans,v);
					if(i<R&&j<G)
						dp[i+1][j+1][k]=max(dp[i+1][j+1][k],v+r[i+1]*g[j+1]);
					if(i<R&&k<B)
						dp[i+1][j][k+1]=max(dp[i+1][j][k+1],v+r[i+1]*b[k+1]);
					if(j<G&&k<B)
						dp[i][j+1][k+1]=max(dp[i][j+1][k+1],v+g[j+1]*b[k+1]);
				}
			}
	printf("%d\n",ans);
	return 0;
}