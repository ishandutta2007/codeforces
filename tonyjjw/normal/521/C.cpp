//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 100000
#define MOD 1000000007
using namespace std;

typedef __int64 ll;
char inp[MN+1];

int N,K,A[MN];
ll C1[MN+1],C2[MN+1];
ll ten[MN+1];

ll po(ll a,int p){
	if(p==0)return 1;
	if(p&1){
		return (po((a*a)%MOD,p/2)*a)%MOD;
	}
	else{
		return po((a*a)%MOD,p/2);
	}
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&K);
	C1[K]=1;
	ten[0]=1;
	for(int i=1;i<N;i++){
		ten[i]=10*ten[i-1];
		ten[i]%=MOD;
	}
	for(int i=K+1;i<N;i++){
		C1[i]=((C1[i-1]*i)%MOD*po(i-K,MOD-2))%MOD;
	}
	if(K>0){
		C2[K-1]=1;
		for(int i=K;i<N;i++){
			C2[i]=((C2[i-1]*i)%MOD*po(i-K+1,MOD-2))%MOD;
		}
	}
	scanf("%s",inp);
	for(int i=0;i<N;i++){
		A[i]=inp[i]-'0';
	}
	ll v=0,ans=0;
	for(int i=N-1;i>=0;i--){
		int L=N-i;
		ans+=((C1[N-L]*ten[L-1])%MOD+v)*A[i];
		ans%=MOD;
		v=(v+C2[N-L-1]*ten[L-1])%MOD;
	}
	printf("%I64d",ans);
	return 0;
}
//*/