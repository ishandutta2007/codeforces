#include <bits/stdc++.h>
using namespace std;
double dp[1<<19], mat[20][20]; 
int N, i, j, k;

int main(){
	for(scanf("%d",&N),i=0;i<N;i++){
		for(j=0;j<N;j++) scanf("%lf",&mat[i][j]);
	}
	dp[(1<<N)-1] = 1;
	for(k=(1<<N)-1;k>0;k--){
		int tot = 0;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				if(i!=j&&((1<<i)&k)&&((1<<j)&k)) tot++;
		}
		tot/=2;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(i==j) continue;
				if(!((1<<i)&k)) continue;
				if(!((1<<j)&k)) continue;
				dp[k&(~(1<<j))]+=dp[k]*mat[i][j]/tot;
			}
		}
	}
	for(i=0;i<N;i++)
		printf("%.7lf ",dp[1<<i]);
	return 0;
}