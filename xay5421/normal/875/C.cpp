#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=100005;
int n,m;
vector<int>str[N];
vector<int>e[N*2];
int dfn[N*2],low[N*2],idx,st[N*2],top,bel[N*2],cnt;
bool in[N*2];
void tarjan(int u){
	st[++top]=u,dfn[u]=low[u]=++idx,in[u]=1;
	each(x,e[u]){
		if(!dfn[x])tarjan(x),low[u]=min(low[u],low[x]);
		else if(in[x])low[u]=min(low[u],dfn[x]);
	}
	if(low[u]==dfn[u]){
		++cnt;
		do{
			bel[st[top]]=cnt;
			in[st[top]]=0;
		}while(st[top--]!=u);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,n){
		int l;
		rd(l);
		str[i].resize(l);
		rep(j,0,l-1)rd(str[i][j]);
	}
	rep(i,1,n-1){
		int pos=-1;
		rep(j,0,min(SZ(str[i]),SZ(str[i+1]))-1){
			if(str[i][j]!=str[i+1][j]){pos=j;break;}
		}
		if(pos==-1&&SZ(str[i])>SZ(str[i+1])){puts("No"),exit(0);}
		if(pos!=-1){
			int j=pos;
			D("! %d %d\n",str[i][j],str[i+1][j]);
			if(str[i][j]<str[i+1][j]){
				e[str[i+1][j]+m].pb(str[i][j]+m);
				e[str[i][j]].pb(str[i+1][j]);
			}else{
				e[str[i][j]].pb(str[i][j]+m);
				e[str[i+1][j]+m].pb(str[i+1][j]);
			}
		}
	}
	rep(i,1,m*2)if(!dfn[i])tarjan(i);
	rep(i,1,m)if(bel[i]==bel[i+m])puts("No"),exit(0);
	puts("Yes");
	vector<int>v;
	rep(i,1,m)if(bel[i]>bel[i+m])v.pb(i);
	printf("%d\n",SZ(v));
	each(x,v)printf("%d ",x);
	return 0;
}