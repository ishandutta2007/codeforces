#include<stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
//#pragma warning(disable:4996)

#define MN 100000

int N,C[MN+1];
long long D[MN+1][2],ANS;

int main(){
	int i,a;
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&a),C[a]++;
	D[1][0]=0,D[1][1]=C[1];
	for(i=2;i<=1e5;i++){
		D[i][0]=MAX(D[i-1][0],D[i-1][1]);
		D[i][1]=D[i-1][0]+(long long)C[i]*i;
	}
	printf("%lld",MAX(D[100000][0],D[100000][1]));
	return 0;
}