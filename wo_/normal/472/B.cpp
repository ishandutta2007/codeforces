#include<cstdio>
#include<algorithm>

using namespace std;

int N,K;
int f[2020];

int dp[2020];

int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) scanf("%d",f+i);
	int ans=0;
	sort(f,f+N);
	dp[0]=0;
	for(int i=1;i<=N;i++){
		int tmp=-1;
		for(int j=max(0,i-K);j<i;j++){
			int cur=dp[j]+(f[i-1]-1);
			if(tmp==-1||tmp>cur) tmp=cur;
		}
		dp[i]=tmp;
	}
	printf("%d\n",dp[N]*2);
	return 0;
}