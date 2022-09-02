// author: xay5421
// created: Sat May  8 18:26:44 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int n,m,ans,a[35][35],b[35][35];
int get(int x,int y){return b[x][y]?-a[x][y]:a[x][y];}
int calc(int x,int y,int o){
	b[x][y]=o,b[x+m][y]=o^b[m-1][y],b[x][y+m]=o^b[x][m-1],b[x+m][y+m]=o^b[x][m-1]^b[m-1][y+m];
	return get(x,y)+get(x+m,y)+get(x,y+m)+get(x+m,y+m);
}
int sol(int x,int o){
	b[x][m-1]=o;
	b[m+x][m-1]=b[x][m-1]^b[m-1][m-1];
	int res=get(x,m-1)+get(m+x,m-1);
	rep(i,0,m-2)res+=max(calc(x,i,0),calc(x,i,1));
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,0,n-1)rep(j,0,n-1)scanf("%d",&a[i][j]);
	m=(n+1)/2;
	rep(i,0,(1<<m)-1){
		rep(j,0,m-1)b[m-1][j]=i>>j&1;
		rep(j,0,m-1)b[m-1][m+j]=b[m-1][j]^b[m-1][m-1];
		int res=0;
		rep(j,0,n-1)res+=get(m-1,j);
		rep(j,0,m-2)res+=max(sol(j,0),sol(j,1));
		D("i=%d res=%d\n",i,res);
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}