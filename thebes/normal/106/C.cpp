#include <bits/stdc++.h>
using namespace std;

const int MN = 1005;
int dp[MN], N, M, i, A, B, j, a, b, c, d;
void upd(int c,int v){
	for(int i=N;i>=c;i--)
		dp[i]=max(dp[i],dp[i-c]+v);
}

int main(){
	scanf("%d%d%d%d",&N,&M,&A,&B);
	for(i=1;i<=M;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int tot = 0;
		for(j=0;(tot+(1<<j))*b<=a&&(tot+(1<<j))*c<=N;j++)
			upd((1<<j)*c,(1<<j)*d),tot+=1<<j;
		int tmp=min(a/b-tot,N/c-tot);
		upd(tmp*c,tmp*d);
	}
	for(i=0;(1<<(i+1))-1<=N;i++) upd((1<<i)*A,(1<<i)*B);
	upd((N-(1<<i)+1)*A,(N-(1<<i)+1)*B);
	printf("%d\n",dp[N]);
	return 0;
}