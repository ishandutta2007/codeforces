#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int n,m;
bool vis[1000005];
vector<int>e[1000005];
int main(){
	rd(n),rd(m);
	rep(i,1,m){
		int u,v;
		rd(u),rd(v);
		e[u].pb(v);
	}
	rep(i,1,n)if(!vis[i]){
		for(auto&x:e[i])if(i<x)vis[x]=1;
	}
	per(i,n,1)if(!vis[i]){
		for(auto&x:e[i])vis[x]=1;
	}
	printf("%d\n",(int)count(vis+1,vis+1+n,0));
	rep(i,1,n)if(!vis[i])printf("%d ",i);
	puts("");
	return 0;
}