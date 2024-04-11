#include<cstdio>
#define N 100005

int n,a[N],q;

int dp[2][N<<1][20];

int lg[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[0][i][0]=a[i];
	}
	for(int i=1;i<=16;i++)
		for(int j=1;j<=n;j++){
			dp[0][j][i]=dp[0][j][i-1]+dp[0][j+(1<<(i-1))][i-1];
			dp[1][j][i]=dp[1][j][i-1]+dp[1][j+(1<<(i-1))][i-1];
			if(dp[0][j][i]>=10){
				dp[0][j][i]-=10;
				dp[1][j][i]++;
			}
		}
	lg[1]=0,lg[2]=1,lg[4]=2,lg[8]=3,lg[16]=4,lg[32]=5,lg[64]=6,lg[128]=7,lg[256]=8,lg[512]=9,lg[1024]=10,lg[2048]=11,lg[4096]=12,lg[8192]=13,lg[16384]=14,lg[32768]=15,lg[65536]=16;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",dp[1][l][lg[r-l+1]]);
	}
}