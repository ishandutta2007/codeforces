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
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
const int N=100005;
int n,dp[N],res[N],fa[N];
vector<int>e[N];
vector<int>ee[N];
void dfs1(int k1,int k2){
	fa[k1]=k2;
	each(x,e[k1])if(x!=k2){
		dfs1(x,k1);
	}
	vector<int>v;
	v.clear();
	each(x,e[k1])if(x!=k2)v.pb(x);
	if(v.empty()){
		dp[k1]=0;
		ee[k1]=move(v);
		return;
	}
	sort(v.begin(),v.end(),[&](int lhs,int rhs){return dp[lhs]>dp[rhs];});
	dp[k1]=0;
	rep(i,0,SZ(v)-1){
		umax(dp[k1],max(1,dp[v[i]])+i);
	}
	if(!k2){
		if(SZ(v)==1){
			res[k1]=max(1,dp[v[0]]);
		}else{
			res[k1]=0;
			rep(i,1,SZ(v)-1){
				umax(res[k1],max(1,dp[v[i]])+i-1+max(1,dp[v[0]]));
			}
		}
	}
	ee[k1]=move(v);
}
int num[N];
void dfs2(int k1,int k2,int key){
	auto&v=ee[k1];
	dp[k2]=key;
	if(k2){
		v.insert(lower_bound(v.begin(),v.end(),k2,[&](int lhs,int rhs){return dp[lhs]>dp[rhs];}),k2);
		if(SZ(v)==1){
			res[k1]=max(1,dp[v[0]]);
		}else{
			res[k1]=0;
			rep(i,1,SZ(v)-1){
				umax(res[k1],max(1,dp[v[i]])+i-1+max(1,dp[v[0]]));
			}
		}
	}
	vector<int>pre(SZ(ee[k1])),suf(SZ(ee[k1]));
	{
		int cur=0;
		rep(i,0,SZ(ee[k1])-1){
			pre[i]=cur;
			cur=max(cur,max(1,dp[v[i]])+i);
		}
	}
	{
		int cur=0;
		per(i,SZ(ee[k1])-1,0){
			suf[i]=cur;
			cur=max(cur,max(1,dp[v[i]])+i-1);
		}
	}
	rep(i,0,SZ(ee[k1])-1){
		num[ee[k1][i]]=max(pre[i],suf[i]);
	}
	each(x,e[k1])if(x!=k2){
		// vx
		dfs2(x,k1,num[x]);
	}
}
int query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	return y;
}
pair<int,int>solve(int root){
	dfs1(root,0);
	int u=root;
	static int cur[N];
	rep(i,1,n){
		cur[i]=0;
	}
	vector<int>ans;
	if(n==1)return {1,1};
	while(1){
		if(SZ(ans)==2)break;
		while(SZ(ee[u])){
			u=ee[u][cur[u]++];
		}
		int ret=query(u);
		if(ret==u){
			ans.pb(u);
			u=root;
			if(cur[u]>=SZ(ee[u]))break;
			continue;
		}
		if(cur[ret]<SZ(ee[ret])){
			u=ret;
		}else{
			ans.pb(ret);
			u=root;
			if(cur[u]>=SZ(ee[u]))break;
		}
	}
	while(SZ(ans)<2)ans.pb(root);
	return {ans[0],ans[1]};
}
vector<int>init(int n,vector<pair<int,int> >es){
	::n=n;
	each(x,es){
		int u,v;
		tie(u,v)=x;
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0,0);
	return vector<int>(res+1,res+n+1);
}

int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int,int> >es;
	rep(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		es.eb(u,v);
	}
	auto ret=init(n,es);
	printf("%d\n",*max_element(ret.begin(),ret.end()));
	fflush(stdout);
	int f;
	scanf("%d",&f);
	auto ans=solve(f);
	printf("! %d %d\n",ans.first,ans.second);
	fflush(stdout);
}