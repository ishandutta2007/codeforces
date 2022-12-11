#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int n,k,a[N][N],ans[N][N],dp[N][N];
void init(){
	for(int i=1;i<=n;i++){
		for(int o=1;o<=n;o++){
			scanf("%1d",&a[i][o]);
			dp[i][o]=0;
			ans[i][o]=1;
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		k=n-k+1;
		init();
		int pd=0;
		for(int i=1;i<=k;i++){
			for(int o=1;o<=k;o++){
				dp[i][o]=max(dp[i-1][o],dp[i][o-1]);
				while(max(dp[i][o]+i,dp[i][o]+o)<=n&&!a[i+dp[i][o]][o+dp[i][o]])dp[i][o]++;
				if(max(dp[i][o]+i,dp[i][o]+o)>n){pd=1;break;}
				ans[i+dp[i][o]][o+dp[i][o]]=0;
			}
		}
		if(pd){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=n;i++){
			for(int o=1;o<=n;o++)putchar(ans[i][o]+'0');
			puts("");
		}
		for(int i=1;i<=n;i++){
			for(int o=1;o<=n;o++){
				dp[i][o]=0;
				ans[i][o]=1;
			}
		}
	}
	return 0;
}