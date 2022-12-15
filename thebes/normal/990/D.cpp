#include <bits/stdc++.h>
using namespace std;

const int MN = 1005;
int N, A, B, f, lol, i, j, mat[MN][MN];

int main(){
	scanf("%d%d%d",&N,&A,&B);
	if(A>1&&B>1) printf("NO\n");
	else if((N==2||N==3)&&A==1&&B==1) printf("NO\n");
	else{
		lol=min(N-A+1,N-B+1);
		for(i=1;i<=lol;i++){
			for(j=1;j<=lol;j++)
				if(abs(i-j)==1) mat[i][j]=1;
		}
		if(B>1) f = 1;
		printf("YES\n");
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				if(i==j) printf("0");
				else printf("%d",mat[i][j]^f);
			}
			printf("\n");
		}
	}
	getchar(); getchar();
	return 0;
}