#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int qpow(int b,int exp){
	if(exp==0) return 1;
	else if(exp%2) return (1LL*b*qpow(b,exp-1))%mod;
	else{int r=qpow(b,exp/2);return (1LL*r*r)%mod;}
}
const int MN = 2002;
int N, M, i, arr[MN], coef[MN], j, res[MN];
int main(){
	for(scanf("%d%d",&N,&M),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	if(M==0){for(i=1;i<=N;i++){printf("%d ",arr[i]);}return 0;}
	coef[0] = 1;
	for(i=1;i<=N;i++)
		coef[i]=((1LL*coef[i-1]*(M+i-1))%mod*qpow(i,mod-2))%mod;
	for(i=1;i<=N;i++){
		for(j=i;j<=N;j++)
			res[j]=(1LL*res[j]+1LL*arr[i]*coef[j-i])%mod;
	}
	for(i=1;i<=N;i++)
		printf("%d ",res[i]);
	getchar(); getchar();
	return 0;
}