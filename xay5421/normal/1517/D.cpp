// author: xay5421
// created: Fri Apr 23 22:59:31 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=505;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
int n,m,K,ri[N][N],dw[N][N],dis[N][N][22];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	rep(i,1,n)rep(j,1,m-1)scanf("%d",&ri[i][j]);
	rep(i,1,n-1)rep(j,1,m)scanf("%d",&dw[i][j]);
	if(K&1){
		rep(i,1,n)rep(j,1,m)printf("-1%c",j==m?'\n':' ');
		return 0;
	}
	K>>=1;
	memset(dis,63,sizeof(dis));
	rep(i,1,n)rep(j,1,m)dis[i][j][0]=0;
	rep(k,1,K){
		rep(i,1,n)rep(j,1,m){
			if(i>1)umin(dis[i][j][k],dis[i-1][j][k-1]+dw[i-1][j]);
			if(i<n)umin(dis[i][j][k],dis[i+1][j][k-1]+dw[i][j]);
			if(j>1)umin(dis[i][j][k],dis[i][j-1][k-1]+ri[i][j-1]);
			if(j<m)umin(dis[i][j][k],dis[i][j+1][k-1]+ri[i][j]);
		}
	}
	rep(i,1,n)rep(j,1,m)printf("%d%c",dis[i][j][K]*2,j==m?'\n':' ');
	return 0;
}