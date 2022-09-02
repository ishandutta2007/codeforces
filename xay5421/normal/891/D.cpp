// author: xay5421
// created: Thu Nov 11 14:27:06 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005;
int n,sz[N];
vector<int>e[N];
struct node{
	LL dp[2][2]; // 
	void setI(){
		dp[0][0]=1;
		dp[0][1]=0;
		dp[1][0]=0;
		dp[1][1]=1;
	}
	void setI_(){
		dp[0][0]=1;
		dp[0][1]=0;
		dp[1][0]=0;
		dp[1][1]=0;
	}
	void setO(){
		dp[0][0]=0;
		dp[0][1]=1;
		dp[1][0]=0;
		dp[1][1]=0;
	}
	void operator+=(const node&b){
		node c;
		memset(c.dp,0,sizeof(c.dp));
		rep(i,0,1)rep(j,0,1){
			rep(i_,0,1)rep(j_,0,1){
				if(i&&i_)continue;
				if(j&&!j_)continue;
				c.dp[i+i_][j+(!j_)]+=dp[i][j]*b.dp[i_][j_];
			}
		}
		*this=c;
	}
	void operator^=(const node&b){
		node c;
		memset(c.dp,0,sizeof(c.dp));
		rep(i,0,1)rep(j,0,1){
			rep(i_,0,1)rep(j_,0,1){
				if(i&&i_)continue;
				if(j&&j_)continue;
				c.dp[i|i_][j|j_]+=dp[i][j]*b.dp[i_][j_];
			}
		}
		*this=c;
	}
}f[N],g[N];
void dfs1(int k1,int k2){
	if(k2){
		e[k1].erase(find(e[k1].begin(),e[k1].end(),k2));
	}
	f[k1].setI();
	sz[k1]=1;
	for(auto x:e[k1]){
		dfs1(x,k1);
		f[k1]+=f[x];
		sz[k1]+=sz[x];
	}
}
void dfs2(int k1,node k2){
	node cur;
	cur.setI();
	cur+=k2;
	for(auto x:e[k1]){
		g[x]=cur;
		cur+=f[x];
	}
	cur.setI_();
	per(i,SZ(e[k1])-1,0){
		//g[e[k1][i]]+=cur;
		g[e[k1][i]]^=cur;
		cur+=f[e[k1][i]];
	}
	for(auto x:e[k1])dfs2(x,g[x]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	if(n&1){puts("0"),exit(0);}
	rep(i,2,n){
		int k1,k2;
		rd(k1),rd(k2);
		e[k1].pb(k2),e[k2].pb(k1);
	}
	dfs1(1,0);
	node cur;
	cur.setO();
	dfs2(1,cur);
	LL ans=0;
	rep(i,2,n)if(f[i].dp[0][1]&&g[i].dp[0][1]){
		ans+=1LL*sz[i]*(n-sz[i]);
	}
	rep(i,2,n)if(sz[i]&1){
		ans+=1LL*f[i].dp[1][1]*g[i].dp[1][1];
	}
	printf("%lld\n",ans);
	return 0;
}