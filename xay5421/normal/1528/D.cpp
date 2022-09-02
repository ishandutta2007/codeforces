// author: xay5421
// created: Mon May 24 23:11:47 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
const int N=605;
int n,m,mp[N][N];
bool vis[N];
LL dis[N],cst[N];
void sol(int beg){
	memset(vis,0,n*sizeof(bool));
	memset(dis,63,n*sizeof(LL));
	dis[beg]=0;
	rep(_,0,n-1){
		int id=-1;
		rep(i,0,n-1)if(!vis[i]&&(id==-1||dis[i]<dis[id]))id=i;
		vis[id]=1;
		int j=dis[id]%n;
		memset(cst,63,n*sizeof(LL));
		rep(i,0,n-1){
			if(i)j=j==n-1?0:j+1;
			if(mp[id][i]!=-1){
				cst[j]=dis[id]+mp[id][i];
			}
		}
		rep(i,0,n-2)umin(cst[i+1],cst[i]+1);
		umin(cst[0],cst[n-1]+1);
		rep(i,0,n-2)umin(cst[i+1],cst[i]+1);
		rep(i,0,n-1)if(!vis[i])umin(dis[i],cst[i]);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(mp,-1,sizeof(mp));
	rd(n),rd(m);
	rep(i,0,m-1){
		int u,v,w;
		rd(u),rd(v),rd(w);
		mp[u][v]=w;
	}
	rep(i,0,n-1){
		sol(i);
		rep(j,0,n-1)pt(dis[j],j==n-1?'\n':' ');
	}
	return 0;
}