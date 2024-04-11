#include<bits/stdc++.h>
using namespace std;

const int maxn=57;
int dp[maxn][maxn][maxn][maxn];

int main(){
	int n;
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;++i){
		getchar();
		for (int j=1;j<=n;++j){
			char s;
			scanf("%c",&s);
			if (s=='#'){
				dp[i][j][i][j]=1;
			}
			else{
				dp[i][j][i][j]=0;
			}
		}
	}
	for (int r=0;r<n;++r){
		for (int s=0;s<n;++s){
			if (s+r==0) continue;
			for (int a=1;a<=n;++a){
				for (int b=1;b<=n;++b){
					int c=a+r,d=b+s;
					if (c>n||d>n) continue;
					int tmp=10007;
					for (int i=a;i<c;++i){
						tmp=min(tmp,dp[a][b][i][d]+dp[i+1][b][c][d]);
					}
					for (int i=b;i<d;++i){
						tmp=min(tmp,dp[a][b][c][i]+dp[a][i+1][c][d]);
					}
					dp[a][b][c][d]=min(tmp,max(r,s)+1);
//					printf("%d %d %d %d %d\n",a,b,c,d,dp[a][b][c][d]);
				}
			}
		}
	}
	printf("%d\n",dp[1][1][n][n]);
	return 0;
}