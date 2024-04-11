#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
//#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,P=998244353,INF=0X3F3F3F3F;
int n,m,f[N][2];
bool used[N][2];
int pp,lnk[N],nxt[N*2],to[N*2],we[N*2];
void ae(int k1,int k2,int k3){to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;}
priority_queue<pair<int,pair<int,int> > >q;
void dij(){
	memset(f,63,sizeof(f));
	auto push=[&](int x,int y,int z){
		if(z<f[x][y]){
			f[x][y]=z;
			q.push({-f[x][y],{x,y}});
		}
	};
	push(1,0,0);
	push(1,1,1);
	while(SZ(q)){
		int x,y;
		tie(x,y)=q.top().Y;
		q.pop();
		if(used[x][y])continue;
		used[x][y]=1;
		for(int i=lnk[x];i;i=nxt[i]){
			push(to[i],we[i],f[x][y]+(y^we[i]));
		}
	}
}
namespace AA{
	const int K=21;
	int dp[N][K];
	bool vis[N][K];
	void sol(){
		memset(dp,63,sizeof(dp));
		auto push=[&](int x,int y,int z){
			if(z<dp[x][y]){
				dp[x][y]=z;
				q.push({-dp[x][y],{x,y}});
			}
		};
		push(1,0,0);
		while(SZ(q)){
			int x,y;
			tie(x,y)=q.top().Y;
			q.pop();
			if(vis[x][y])continue;
			vis[x][y]=1;
			for(int i=lnk[x];i;i=nxt[i]){
				if((we[i]^(y&1))&&y+1<K){
					push(to[i],y+1,dp[x][y]+(1<<y)+1);
				}else{
					push(to[i],y,dp[x][y]+1);
				}
			}
		}
		int ans=INF;
		rep(i,0,K-1)ans=min(ans,dp[n][i]);
		pt(ans,'\n');
		exit(0);
	}
}
namespace BB{
	int dp[N][2];
	bool vis[N][2];
	void sol(){
		memset(dp,63,sizeof(dp));
		auto push=[&](int x,int y,int z){
			if(z<dp[x][y]){
				dp[x][y]=z;
				q.push({-dp[x][y],{x,y}});
			}
		};
		push(1,0,0);
		push(1,1,0);
		while(SZ(q)){
			int x,y;
			tie(x,y)=q.top().Y;
			q.pop();
			if(vis[x][y])continue;
			vis[x][y]=1;
			for(int i=lnk[x];i;i=nxt[i]){
				if(f[x][y]+(y^we[i])==f[to[i]][we[i]]){
					push(to[i],we[i],dp[x][y]+1);
				}
			}
		}
		auto sum=[&](int x){
			int pw=1;
			int res=0;
			rep(i,0,x-1){
				(res+=pw)%=P;
				(pw+=pw)%=P;
			}
			return res;
		};
		if(f[n][0]<f[n][1]||(f[n][0]==f[n][1]&&dp[n][0]<dp[n][1])){
			pt((dp[n][0]+sum(f[n][0]))%P,'\n');
		}else{
			pt((dp[n][1]+sum(f[n][1]))%P,'\n');
		}
	}
}
signed main(){
	rd(n),rd(m);
	rep(i,1,m){
		int k1,k2;
		rd(k1),rd(k2);
		ae(k1,k2,0),ae(k2,k1,1);
	}
	dij();
	if(min(f[n][0],f[n][1])<20){
		AA::sol();
	}else{
		BB::sol();
	}
	return 0;
}