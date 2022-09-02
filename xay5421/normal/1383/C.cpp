#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005,M=1048580;
int T,n,go[25],dp[M];
bool pd[M];
char A[N],B[N];
void dfs(int k1){
	if(pd[k1])return;
	pd[k1]=1;
	rep(i,0,19)if((go[k1]>>i&1)||(go[i]>>k1&1))dfs(i);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,A+1,B+1);
		memset(go,0,sizeof(go)),memset(pd,0,sizeof(pd));
		rep(i,1,n)if(A[i]!=B[i])go[A[i]-'a']|=1<<(B[i]-'a');
		int cnt=0;
		rep(i,0,19)if(!pd[i])dfs(i),++cnt;
		int ans=0;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		rep(i,0,(1<<20)-1)if(dp[i]){
			ans=max(ans,__builtin_popcount(i));
			rep(j,0,19)if((~i>>j&1)&&(go[j]&i)==0){
				dp[i|(1<<j)]=1;
			}
		}
///		printf(">>> cnt=%d ans=%d\n",cnt,ans);
		printf("%d\n",40-cnt-ans);
	}
	return 0;
}