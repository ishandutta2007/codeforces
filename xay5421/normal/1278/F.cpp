#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=5005,P=998244353;
int n,m,K,S[N][N];
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
int main(){
	cin>>n>>m>>K;
	S[0][0]=1;
	rep(i,1,K)rep(j,1,i)S[i][j]=(1LL*S[i-1][j]*j+S[i-1][j-1])%P;
	int dwn=1,invm=fpow(m,P-2),fm=1;
	int ans=0;
	rep(i,1,K){
		dwn=1LL*dwn*(n-i+1)%P;
		fm=1LL*fm*invm%P;
		ans=(ans+1LL*dwn*fm%P*S[K][i])%P;
	}
	printf("%d\n",ans);
	return 0;
}