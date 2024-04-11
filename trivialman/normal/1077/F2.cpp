#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<deque>
using namespace std;
#define N 5010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

LL dp[N][N],a[N];
int max0[N];
int n,k,x;
deque<LL>que;

int main(){
	CL(dp);CL(max0);
	scanf("%d%d%d",&n,&k,&x); 
	
	rep(i,1,n)scanf("%d",&a[i]);
	a[n+1]=0;
	rep(j,1,x+1){
		que.clear();
		rep(i,j,n+1){
			while(!que.empty()&&i-que.front()>k)que.pop_front();
			while(!que.empty()&&dp[i-1][j-1]>=dp[que.back()][j-1])que.pop_back();
			que.push_back(i-1);
			LL tmp=dp[que.front()][j-1];
			
			if((j>=2||(j==1&&i>k))&&tmp==0)continue;
			dp[i][j]=tmp+a[i];
			
			//printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	LL ans=dp[n+1][x+1];
	cout<<(ans==0?-1:ans)<<endl;
	return 0;
}