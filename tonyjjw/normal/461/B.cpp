//*
#include<stdio.h>
//#pragma warning(disable:4996)
#define MOD 1000000007
#define MN 100000

int N;
int son[MN],bro[MN],col[MN];
long long D1[MN],D2[MN];

long long pp(long long a,int b){
	if(b==1)return a;
	long long v=1;
	if(b&1){
		return (pp((a*a)%MOD,b/2)*a)%MOD;
	}
	else{
		return pp((a*a)%MOD,b/2);
	}
}

void dfs(int n){
	if(son[n]==-1){
		D1[n]=col[n];
		D2[n]=1-col[n];
		return;
	}
	int p;
	long long v=1;
	for(p=son[n];p!=-1;p=bro[p]){
		dfs(p);
		v*=(D1[p]+D2[p]);
		v%=MOD;
	}
	if(col[n]){
		D1[n]=v;
		D2[n]=0;
	}
	else{
		for(p=son[n];p!=-1;p=bro[p]){
			D1[n]+=(((v*D1[p])%MOD)*pp((D1[p]+D2[p])%MOD,MOD-2))%MOD;
			D1[n]%=MOD;
		}
		D2[n]=v;
	}
}

int main(){
	int i,a;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(i=0;i<N;i++)son[i]=bro[i]=-1;
	for(i=0;i<N-1;i++){
		scanf("%d",&a);
		bro[i+1]=son[a];
		son[a]=i+1;
	}
	for(i=0;i<N;i++)scanf("%d",&col[i]);
	dfs(0);
	printf("%lld",D1[0]);
	return 0;
}

//*/