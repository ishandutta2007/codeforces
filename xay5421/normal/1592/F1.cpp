// author: xay5421
// created: Mon Oct  4 15:05:16 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=505;
int n,m,a[N][N];
char s[N][N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m)a[i][j]=s[i][j]=='B';
	rep(i,1,n)rep(j,1,m)a[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1];
	int ans=0;
	rep(i,1,n)rep(j,1,m)ans+=a[i][j];
	rep(i,1,n-1)rep(j,1,m-1){
		if(a[i][j]&&a[i][m]&&a[n][j]&&a[n][m]){
			printf("%d\n",ans-1),exit(0);
		}
	}
	printf("%d\n",ans);
	return 0;
}