// author: xay5421
// created: Mon Oct 18 15:25:47 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=2005;
int n,col[N][N],tag[N][N],val[N];
char s[N][N];
int main(){
	scanf("%d",&n);
	if(n&1)puts("NONE"),exit(0);
	rep(i,1,n)scanf("%s",s[i]+1);
	for(int i=1,cur=1;i<=n;i+=2,++cur){
		int x=i,y=1,z=0;
		while(1){
			col[x][y]=cur;
			tag[x][y]=z;
			if(x==1)break;
			--x,++y,z^=1;
		}
		++y;
		while(1){
			col[x][y]=cur;
			tag[x][y]=z;
			if(y==n)break;
			++x,++y,z^=1;
		}
		++x;
		while(1){
			col[x][y]=cur;
			tag[x][y]=z;
			if(x==n)break;
			++x,--y,z^=1;
		}
		--y;
		while(1){
			col[x][y]=cur;
			tag[x][y]=z;
			if(y==1)break;
			--x,--y,z^=1;
		}
	}
	//rep(i,1,n)rep(j,1,n)printf("%d%c",col[i][j],j==n?'\n':' ');
	memset(val,-1,sizeof(val));
	rep(i,1,n){
		rep(j,1,n)if(s[i][j]!='.'){
			int cur=tag[i][j]^(s[i][j]=='S');
			if(val[col[i][j]]==(cur^1)){
				puts("NONE"),exit(0);
			}
			val[col[i][j]]=cur;
		}
	}
	rep(i,1,n/2)if(val[i]==-1)puts("MULTIPLE"),exit(0);
	puts("UNIQUE");
	rep(i,1,n)rep(j,1,n){
		putchar((val[col[i][j]]^tag[i][j])?'S':'G');
		if(j==n)puts("");
	}
	return 0;
}