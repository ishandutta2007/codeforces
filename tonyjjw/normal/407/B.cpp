#include<stdio.h>
#define MN 1001
#define MOD (1000000007)
#pragma warning(disable:4996)

int N;
int A[MN];
int D[MN][MN];
int C[MN];

int main(){
	int i,j;
//	freopen("input.txt","r",stdin);
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&A[i]),A[i]--;
	D[0][0]=1;
	for(j=1;j<N;j++){
		if(A[j]==j)
			D[j][j]=1;
		else
			D[j][j]=(D[A[j]][j-1]+2)%MOD;
		for(i=0;i<j;i++){
			if(A[j]==j){
				D[i][j]=(D[i][j-1]+2)%MOD;
			}
			else
				D[i][j]=(D[i][j-1]+D[A[j]][j-1]+3)%MOD;
		}
	}
	printf("%d",(D[0][N-1]+1)%MOD);
	return 0;
}