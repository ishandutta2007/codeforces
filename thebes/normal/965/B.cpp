#include <bits/stdc++.h>
using namespace std;
const int MN = 201;
int mat[MN][MN], N, K, i, j, k, cnt[MN][MN],mx,x=1,y=1;
int main(){
	for(scanf("%d%d",&N,&K),i=1;i<=N;i++){
		for(getchar(),j=1;j<=N;j++)
			mat[i][j]=(getchar()=='.')?1:0;
	}
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			bool fnd = true;
			for(k=0;k<K;k++)
				if(!mat[i][j+k]) fnd=0;
			if(fnd){
				for(k=0;k<K;k++)
					cnt[i][j+k] ++;
			}
			fnd = true;
			for(k=0;k<K;k++)
				if(!mat[i+k][j]) fnd=0;
			if(fnd){
				for(k=0;k<K;k++)
					cnt[i+k][j] ++;
			}
		}
	}
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			if(cnt[i][j]>mx){
				mx=cnt[i][j];
				x=i,y=j;
			}
		}
	}
	printf("%d %d\n",x,y);
	return 0;
}