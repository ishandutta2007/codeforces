//*

#include<stdio.h>
#include<algorithm>
#define MN 5000
#define MK 5000
#define MOD 1000000007

using namespace std;

int N,K;
int D[MK+1][MN+2];

void upt(int i){
	for(int j=1;j<=N;j++){
		D[i][j]=(D[i][j-1]+D[i][j])%MOD;
	}
}

int m(int v){
	if(v<0)return v+MOD;
	if(v>=MOD)return v-MOD;
	return v;
}

int main(){
//	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	int a,b;
	scanf("%d%d%d%d",&N,&a,&b,&K);
	if(a>b){
		N-=b;
		a-=b;
	}
	else{
		N=b-1;
		a=b-a;
	}

	D[0][a]=1;
	for(int i=0;i<K;i++){
		for(int j=1;j<=N;j++){
			int j2=min(2*j-1,N);
			D[i+1][1]=m(D[i+1][1]+D[i][j]);
			D[i+1][j2+1]=m(D[i+1][j2+1]-D[i][j]);
		}
		upt(i+1);
		for(int j=1;j<=N;j++){
			D[i+1][j]=m(D[i+1][j]-D[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=N;i++)ans=(D[K][i]+ans)%MOD;
	printf("%d",ans);
	return 0;
}

//*/