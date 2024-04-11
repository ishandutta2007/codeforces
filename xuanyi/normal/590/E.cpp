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
const int N=755,M=10000005;
int n,pos[N],where[N];
char s[M];
int idx,ch[M][2],who[M],fa[M];
bool g[N][N];
bool vis[N];
int mate1[N],mate2[N];
int dfs(int u){
	if(vis[u])return 0;
	vis[u]=1;
	rep(v,1,n)if(g[u][v]&&(!mate2[v]||dfs(mate2[v]))){
		mate1[u]=v;
		mate2[v]=u;
		return 1;
	}
	return 0;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",s+pos[i]);
		pos[i+1]=pos[i]+strlen(s+pos[i]);
	}
	rep(i,1,n){
		int u=0;
		rep(j,pos[i],pos[i+1]-1){
			if(!ch[u][s[j]-'a']){
				ch[u][s[j]-'a']=++idx;
			}
			u=ch[u][s[j]-'a'];
		}
		who[u]=i;
		where[i]=u;
	}
	queue<int>q;
	rep(i,0,1)if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty()){
		int u=q.front();
		if(!who[u])who[u]=who[fa[u]];
		q.pop();
		rep(i,0,1){
			if(!ch[u][i])ch[u][i]=ch[fa[u]][i];
			else{
				fa[ch[u][i]]=ch[fa[u]][i];
				q.push(ch[u][i]);
			}
		}
	}
	rep(i,1,n){
		int u=0;
		rep(j,pos[i],pos[i+1]-1){
			u=ch[u][s[j]-'a'];
			if(who[j==pos[i+1]-1?fa[u]:u]){
				g[i][who[j==pos[i+1]-1?fa[u]:u]]=1;
			}
		}
	}
	rep(k,1,n)rep(i,1,n)if(i!=k)rep(j,1,n)if(j!=k&&j!=i)g[i][j]|=g[i][k]&&g[k][j];
	int ans=0;
	rep(i,1,n)if(!vis[i]){
		memset(vis,0,sizeof(vis));
		ans+=dfs(i);
	}
	vector<int>v;
	rep(i,1,n)if(!mate1[i])v.pb(i);
	while(1){
		bool flg=0;
		vector<bool>used(n+1);
		each(x,v){
			rep(y,1,n)if(g[x][y])used[y]=1;
		}
		each(x,v)while(used[x])flg=1,x=mate2[x];
		if(!flg)break;
	}
	printf("%d\n",n-ans);
	each(x,v)printf("%d ",x);
	return 0;
}