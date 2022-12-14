//*
#include<stdio.h>
#include<string.h>
#define ML 1000000
#define MOD 1000000007

int fail[ML],x[ML];
int possible[ML+1];
int chk[ML+1];
char ps[ML];

typedef long long ll;

int main(){

//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	scanf("%s",ps);
	int L=strlen(ps);
	//failure func
	{
		fail[0]=-1;
		int k=-1;
		for(int i=1;i<L;i++){
			while(k!=-1 && ps[i]!=ps[k+1])k=fail[k];
			if(ps[i]==ps[k+1])++k;
			fail[i]=k;
		}
	}

	//add
	for(int i=L-1;i>=0;i=fail[i]){
		possible[i+1]=1;
	}

	for(int i=0;i<M;i++){
		scanf("%d",&x[i]),x[i]--;
		chk[x[i]]++;
		chk[x[i]+L]--;
	}
	for(int i=1;i<M;i++){
		if(x[i]-x[i-1]>=L)continue;
		if(!possible[L-(x[i]-x[i-1])]){
			puts("0");
			return 0;
		}
	}
	int v=0;
	ll ans=1;
	for(int i=0;i<N;i++){
		v+=chk[i];
		if(v==0){
			ans=ans*26%MOD;
		}
	}
	printf("%lld",ans);
	return 0;
}
//*/