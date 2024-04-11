#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
#define N 2010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

LL dp[N][N],a[N];
int n,k,x;

int main(){
	CL(dp);
	scanf("%d%d%d",&n,&k,&x); 
	/*if(k*(x+1)-1<n){
		cout<<-1<<endl;return 0;
	}*/
	rep(i,1,n)scanf("%d",&a[i]);
	a[n+1]=0;
	rep(i,1,n+1){
		rep(j,1,min(i,x+1)){
			LL tmp=0;
			rep(l,1,k){
				if(i-l>=1&&dp[i-l][j-1]>=tmp)
					tmp=dp[i-l][j-1];
			}
			if((j>=2||(j==1&&i>k))&&tmp==0)continue;
			dp[i][j]=tmp+a[i];
			//printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	LL ans=dp[n+1][x+1];
	if(ans==0)cout<<-1<<endl;else cout<<ans<<endl;
	return 0;
}