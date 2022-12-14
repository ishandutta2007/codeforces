//*
#include<stdio.h>
#pragma warning(disable:4996)
#define MN 4000
#define MOD 1000000007
using namespace std;
typedef long long ll;

int N;
ll fact[MN+1];
ll p2[MN+1];
ll gn[MN];

ll pow(ll a,ll p){
	ll v=1;
	while(p>0){
		if(p&1)v=v*a%MOD;
		a=a*a%MOD;
		p>>=1;
	}
	return v;
}

ll mi(ll a){
	return pow(a,MOD-2);
}

ll ncr[MN+1][MN+1];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	fact[0]=1;
	for(int i=1;i<=N;i++)fact[i]=fact[i-1]*i%MOD;
	p2[0]=1;
	for(int i=1;i<=N;i++)p2[i]=p2[i-1]*2%MOD;
	gn[2]=1;
	gn[0]=1;
	for(int i=0;i<=N;i++){
		ncr[i][0]=1;
		for(int j=1;j<=i;j++){
			ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%MOD;
		}
	}
	for(int i=3;i<=N;i++){
		for(int j=1;j<i;j++){
			gn[i]=(gn[i]+ncr[i-1][j]*gn[i-j-1])%MOD;
		}
	}
	ll ans=0;
	for(int i=1;i<=N;i++){
		ans=(ans+ncr[N][i]*gn[N-i]%MOD*(p2[i]-1))%MOD;
	}
	printf("%I64d",ans);
	return 0;
}
//*/