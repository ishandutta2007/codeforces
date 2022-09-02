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
const int N=1000005,INF=0X3F3F3F3F;
int n,Q,fa[N],len[N],son[N],deg[N],dis[N],dep[N];
int pp,lnk[N],nxt[N],to[N];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs1(int k1){
	for(int i=lnk[k1];i;i=nxt[i]){
		dep[to[i]]=dep[k1]+1;
		dfs1(to[i]);
		if(len[son[k1]]<len[to[i]])son[k1]=to[i];
	}
	len[k1]=len[son[k1]]+1;
}
int X,cur;
int beg[N],dp[N],ans;
void dfs2(int k1){
	if(son[k1]){
		beg[son[k1]]=beg[k1];
		dfs2(son[k1]);
	}
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=son[k1]){
		beg[to[i]]=cur;
		cur+=len[to[i]];
		dfs2(to[i]);
		rep(now,0,len[to[i]]-1){
			while(1){
				int tmp=max(ans-now-X,0);
				if(tmp<len[k1]&&dp[beg[k1]+tmp]+dp[beg[to[i]]+now]-dep[k1]*2>=ans)
					++ans;
				else break;
			}
		}
		rep(now,0,len[to[i]]-1){
			dp[beg[k1]+now]=max(dp[beg[k1]+now],dp[beg[to[i]]+now]);
		}
	}
	while(1){
		int tmp=max(ans-dis[k1]-X,0);
		if(tmp<len[k1]&&dp[beg[k1]+tmp]-dep[k1]>=ans)
			++ans;
		else break;
	}
	dp[beg[k1]+dis[k1]]=max(dp[beg[k1]+dis[k1]],dep[k1]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(dis,63,sizeof(dis));
	rd(n);
	rep(i,2,n){
		rd(fa[i]);
		ae(fa[i],i);
		++deg[fa[i]],++deg[i];
	}
	queue<int>que;
	rep(i,1,n)if(deg[i]==1)que.push(i),dis[i]=0;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=lnk[u];i;i=nxt[i]){
			if(dis[u]+1<dis[to[i]]){
				dis[to[i]]=dis[u]+1;
				que.push(to[i]);
			}
		}
		if(fa[u]){
			int x=fa[u];
			if(dis[u]+1<dis[x]){
				dis[x]=dis[u]+1;
				que.push(x);
			}
		}
	}
	dfs1(1);
	memset(dp,192,sizeof(dp));
	rd(Q);
	while(Q--){
		rd(X);
		rep(i,0,cur-1)dp[i]=~INF;
		cur=0;
		beg[1]=cur;
		cur+=len[1];
		ans=1;
		dfs2(1);
		printf("%d ",ans-1);
	}
	return 0;
}