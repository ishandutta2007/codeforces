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
const int N=200005;
int n,m,dis[N],dp[N],val[N];
vector<int>e[N],ie[N];
priority_queue<pair<int,int> >pq;
void push(int x,int y){
	if(y<dp[x]){
		dp[x]=y;
		pq.emplace(-y,x);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(dp,63,sizeof(dp));
	rd(n),rd(m);
	rep(i,1,m){
		int u,v;
		rd(u),rd(v);
		e[u].pb(v),ie[v].pb(u);
	}
	dp[n]=0;
	pq.emplace(0,n);
	vector<bool>vis(n+1);
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		each(x,ie[u]){
			push(x,dp[u]+(SZ(e[x])-val[x]));
			++val[x];
		}
	}
	printf("%d\n",dp[1]);
	return 0;
}