// author: xay5421
// created: Sun Sep 12 22:43:24 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005,INF=0X3F3F3F3F;
int T,n,f[N][4];
char s[2][N];
int mex(int s){
	if(~s&1)return 0;
	if(~s>>1&1)return 1;
	return 2;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s%s",s[0]+1,s[1]+1);
		rep(j,0,3)f[0][j]=~INF;
		f[0][0]=0;
		rep(i,1,n){
			int st=(1<<(s[0][i]-'0'))|(1<<(s[1][i]-'0'));
			rep(j,0,3)f[i][j]=~INF;
			rep(j,0,3){
				f[i][0]=max(f[i][0],f[i-1][j]+mex(j|st));
				f[i][j|st]=max(f[i][j|st],f[i-1][j]);
			}
		}
		printf("%d\n",f[n][0]);
	}
	return 0;
}