#include <cstdio> 
#include <algorithm>
#define mod 1000000007
#define max_t 100
#define max_k 1000
#define max_num (max_t*max_k*2+200)
using namespace std;
int a[2][max_num+1<<1];
int*dp[2]={a[0]+max_num,a[1]+max_num};
int m(int x){
	return x>=mod?x-mod:x;
}
int main(){
	int k,l,t,a,b,ans,now,mxnum;
    scanf("%d%d%d%d",&a,&b,&k,&t);
    dp[0][a-b]=1,dp[0][a-b+1]=mod-1;
    mxnum=abs(a-b),l=0,now=0;
    for(t=t<<1|1; --t; mxnum+=k,now^=1,l=0)
        for(int j=-mxnum-1; ++j<=mxnum+1; dp[now][j]=0){
        	l=m(l+dp[now][j]);
        	dp[now^1][j-k]=m(dp[now^1][j-k]+l),
        	dp[now^1][j+k+1]=m(dp[now^1][j+k+1]-l+mod);
		}
    l=0,ans=0;
    for(int j=-mxnum-1; ++j<=0; l=m(l+dp[now][j]));
    for(int j=0; ++j<=mxnum+1; ans=m(ans+(l=m(l+dp[now][j]))));
    printf("%d\n",ans);
}