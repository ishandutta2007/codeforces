#include <cstdio>
using namespace std;
#define eps 0.000000001
#define max_p 1000
#define max_k 1000
#define frc 2000
double dp[max_k+1];
int ans[max_p+1];
int main(){
	int k,q,p;
	scanf("%d%d",&k,&q);
	dp[0]=1;
	for(int i=1,num=0; num<max_p; ++i,dp[0]=0){
		for(int j=k+1; --j; dp[j]=((k-j+1)*dp[j-1]+dp[j]*j)/k);
		for(; num<max_p&&dp[k]*frc>=num+1-eps; ans[++num]=i);
	}
	for(++q; --q; printf("%d\n",ans[p]))
		scanf("%d",&p);
	return 0;
}