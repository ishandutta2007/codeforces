#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
#define N 300000
#define MOD 1000000007
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

int n;
int a[N+5],candiv[N+5];
LL fac[N+5],facrev[N+5],dp[15][N+5];

LL exp(LL x, LL y){
	if(y==0)return 1;
	LL z=exp(x,y/2);
	z=(z*z)%MOD;
	if(y&1)z=(z*x)%MOD;
	return z;
}
LL C(int a,int b){
	if(b<0||b>a)return 0;
	return fac[a]*(facrev[a-b]*facrev[b]%MOD)%MOD;
}
LL subtr(LL a,LL b){
	LL z=a-b;
	return z>=0?z:z+MOD;
}

int main(){
	scanf("%d",&n);
	fac[0]=1;
	rep(i,1,N)fac[i]=(fac[i-1]*i)%MOD;
	facrev[N]=exp(fac[N],MOD-2);
	for(int i=N;i;--i)facrev[i-1]=(facrev[i]*i)%MOD;
	
	CL(candiv);
	rep(i,1,n){
		scanf("%d",&a[i]);
		candiv[a[i]]=1;
	}
	rep(i,1,N){
		for(int j=i+i;j<=N;j+=i)candiv[i]+=candiv[j];
	}
	CL(dp);
	rep(i,1,10){
		for(int j=N;j;j--){
			dp[i][j]=C(candiv[j],i);
			for(int k=j+j;k<=N;k+=j)dp[i][j]=subtr(dp[i][j],dp[i][k]);
		}
		if(dp[i][1]){cout<<i<<endl;return 0;}
	}
	cout<<-1<<endl;
	return 0;
}