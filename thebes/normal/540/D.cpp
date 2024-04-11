#include <bits/stdc++.h>
using namespace std;

const int MN = 102;
double dp[MN][MN][MN], ans[3];
int x, y, z, i, j, k, tot, p[3];
double f(int x,int y){return(double)x/(double)y;}

int main(){
	scanf("%d%d%d",&x,&y,&z);
	dp[x][y][z] = 1.0;
	for(i=x;i>=0;i--){
		for(j=y;j>=0;j--){
			for(k=z;k>=0;k--){
				p[0]=i*j; p[1]=j*k; p[2]=k*i;
				tot=i*j+j*k+k*i;
				if(!tot) continue;
				if(j) dp[i][j-1][k]+=dp[i][j][k]*f(p[0],tot);
				if(k) dp[i][j][k-1]+=dp[i][j][k]*f(p[1],tot);
				if(i) dp[i-1][j][k]+=dp[i][j][k]*f(p[2],tot);
			}
		}
	}
	for(i=1;i<=x;i++) ans[0]+=dp[i][0][0];
	for(i=1;i<=y;i++) ans[1]+=dp[0][i][0];
	for(i=1;i<=z;i++) ans[2]+=dp[0][0][i];
	for(i=0;i<3;i++) printf("%.12lf ",ans[i]);
	return 0;
}