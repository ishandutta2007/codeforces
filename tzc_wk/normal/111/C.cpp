#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n=read(),m=read(),dp[45][(1<<7)+15][(1<<7)+15];
int main(){
	if(n<m)	swap(n,m);
	if(n==1&&m==1)	return print(0),0;
	memset(dp,63,sizeof(dp));
	for(int i=0;i<(1<<m);++i)	dp[1][0][i]=__builtin_popcount(i);
	int ans=0x3f3f3f3f;
	for(int i=2;i<=n;i++){
		for(int j=0;j<(1<<m);j++){
			for(int k=0;k<(1<<m);k++){
				for(int l=0;l<(1<<m);l++){
					bool vis[15];
					memset(vis,0,sizeof(vis));
					for(int x=1;x<=m;x++)	if(l&(1<<(x-1)))	vis[x]=1;
					for(int x=1;x<=m;x++)	if(j&(1<<(x-1)))	vis[x]=1;
					for(int x=1;x<=m;x++)	if(k&(1<<(x-1)))	vis[x]=vis[x-1]=vis[x+1]=1;
					bool ok=1;
					for(int x=1;x<=m;x++){
						if(vis[x]==0){
							ok=0;break;
						}
					}
					if(ok)
						dp[i][k][j]=min(dp[i][k][j],dp[i-1][l][k]+__builtin_popcount(j));
					if(i==n){           
						bool vis2[15];
						memset(vis2,0,sizeof(vis2));
						for(int x=1;x<=m;x++)	if(j&(1<<(x-1)))	vis2[x-1]=vis2[x]=vis2[x+1]=1;
						for(int x=1;x<=m;x++)	if(k&(1<<(x-1)))	vis2[x]=1;
						bool flag=1;
						for(int x=1;x<=m;x++){
							if(vis2[x]==0){
								flag=0;break;
							}
						}
						if(flag)	ans=min(ans,dp[i][k][j]);
					}
				}
			}
		}
	}
	print(n*m-ans);
}