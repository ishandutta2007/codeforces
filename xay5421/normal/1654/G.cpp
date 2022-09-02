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
const int N=200005,INF=0X3F3F3F3F;
int n,l[N],h[N],dis[N],ans[N];
vector<int>e[N];
vector<pair<int,int> >all[N];
bool vis[N],used[N];
priority_queue<pair<int,int> >pq[N];
int main(){
	rd(n);
	rep(i,1,n)rd(l[i]);
	rep(i,2,n){
		int u,v;
		rd(u),rd(v);
		e[u].pb(v),e[v].pb(u);
	}
	queue<int>que;
	memset(h,63,sizeof(h));
	rep(i,1,n)if(l[i]){
		h[i]=0;
		que.push(i);
	}
	while(!que.empty()){
		int u=que.front();
		que.pop();
		each(x,e[u])if(h[u]+1<h[x]){
			h[x]=h[u]+1;
			que.push(x);
		}
	}
	rep(u,1,n)each(x,e[u])if(h[x]==h[u])vis[h[u]]=1,all[h[u]].eb(u,x);
	memset(ans,-1,sizeof(ans));
	rep(d,0,n)if(vis[d]){
		memset(dis,63,(n+1)*sizeof(dis[0]));
		memset(used,0,(n+1)*sizeof(used[0]));
		each(x,all[d]){
			int u,v;
			tie(u,v)=x;
			if(dis[u]!=1){
				dis[u]=1;
				pq[h[u]].emplace(-dis[u],u);
			}
			if(dis[v]!=1){
				dis[v]=1;
				pq[h[u]].emplace(-dis[v],v);
			}
		}
		rep(dd,d,n){
			while(!pq[dd].empty()){
				int u=pq[dd].top().second;
				pq[dd].pop();
				if(used[u])continue;
				used[u]=1;
				each(x,e[u]){
					if(h[u]+1==h[x]){
						int t=max(dis[u]-1,0);
						if(t<dis[x]){
							dis[x]=t;
							pq[dd+1].emplace(-dis[x],x);
						}
					}else if(h[u]==h[x]){
						if(dis[u]+1<dis[x]){
							dis[x]=dis[u]+1;
							pq[dd].emplace(-dis[x],x);
						}
					}
				}
			}
		}
		rep(u,1,n)if(dis[u]==0&&ans[u]==-1)ans[u]=d;
	}
	rep(u,1,n)printf("%d ",h[u]*2-(ans[u]==-1?h[u]:ans[u]));
	return 0;
}