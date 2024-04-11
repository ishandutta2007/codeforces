#include <bits/stdc++.h>
using namespace std;

int N, M, K, ans, rem, tmp, tmp2, c, i, j, mat[101][101];


int main(){
	for(scanf("%d%d%d",&N,&M,&K),i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			scanf("%d",&mat[j][i]);
			mat[j][i] += mat[j][i-1];
		}
	}
	for(i=1;i<=M;i++){
		for(tmp=0,tmp2=0,c=0,j=1;j<=N;j++){
			if(mat[i][j]-mat[i][j-1]){
				if(mat[i][min(N,j+K-1)]-mat[i][j-1] > tmp) tmp2 = c;
				tmp = max(mat[i][min(N,j+K-1)]-mat[i][j-1],tmp);
				c++;
			}
		}
		ans += tmp; rem += tmp2;
	}
	printf("%d %d\n",ans,rem);
	return 0;
}