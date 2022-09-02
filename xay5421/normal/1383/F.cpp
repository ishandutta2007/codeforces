// author: xay5421
// created: Fri Dec 18 18:40:44 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define CTZ(x) __builtin_ctz(x)
#define POP(x) __builtin_popcount(x)
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=10005,INF=0X3F3F3F3F;
int n,m,K,Q,maxf[1030],w[N],sum[1030];
int q[N],he,ta,dep[N],pre[N],ret,tim,pd[N];
struct solver{
	int pp=1,lnk[N],cur[N],to[N*2],we[N*2],nxt[N*2];
	void ae(int k1,int k2,int k3){
		to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
		to[++pp]=k1,we[pp]= 0,nxt[pp]=lnk[k2],lnk[k2]=pp;
	}
	bool bfs(int s,int t){
		fill(dep+1,dep+1+n,0);
		he=0,dep[q[ta=1]=s]=1;
		if(q[ta]==t)return 1;
		while(he!=ta){
			int k1=q[++he];
			for(int i=lnk[k1];i;i=nxt[i])if(dep[to[i]]==0&&we[i]){
				dep[to[i]]=dep[k1]+1;
				q[++ta]=to[i];
				if(q[ta]==t)return 1;
			}
		}
		return 0;
	}
	int dfs(int k1,int t,int val){
		//D("dfs %d %d %d\n",k1,t,val);
		if(k1==t)return val;
		int v=val;
		for(int&i=cur[k1];i;i=nxt[i])if(we[i]&&dep[to[i]]==dep[k1]+1){
			int f=dfs(to[i],t,min(we[i],v));
			we[i]-=f,we[i^1]+=f,v-=f;
			if(!v)return val;
		}
		return val-v;
	}
	int sol(){	
		int flow=0;
		while(bfs(1,n)){
			copy_n(lnk+1,n,cur+1);
			flow+=dfs(1,n,INF);
			flow=min(flow,INF);
		}
		return flow;
	}
	bool BFS(int s,int t){
		he=0,q[ta=1]=s,pd[s]=++tim;
		if(q[ta]==t)return 1;
		while(he!=ta){
			int k1=q[++he];
			for(int i=lnk[k1];i;i=nxt[i])if(we[i]&&pd[to[i]]!=tim){
				pd[to[i]]=tim;
				pre[to[i]]=i;
				q[++ta]=to[i];
				if(q[ta]==t)return 1;
			}
		}
		return 0;
	}
	int work(){
		ret=0;
		while(BFS(1,n)){
			int f=INF;
			for(int i=pre[n];i;i=pre[to[i^1]])f=min(f,we[i]);
			for(int i=pre[n];i;i=pre[to[i^1]])we[i]-=f,we[i^1]+=f;
			ret+=f;
		}
		return ret;
	}
}mf[2][270];
map<int,int>id[2];
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m),rd(K),rd(Q);
	vector<array<int,3> >e;
	rep(i,1,K){
		int u,v,w;
		rd(u),rd(v),rd(w);
		e.push_back({u,v,w});
	}
	rep(i,K+1,m){
		int u,v,w;
		rd(u),rd(v),rd(w);
		mf[0][0].ae(u,v,w);
	}
	vector<int>eid(K);
	rep(i,0,K-1){
		eid[i]=mf[0][0].pp+1;
		mf[0][0].ae(e[i][0],e[i][1],0);
	}
	auto init=[&](int t){
		id[t&1].clear();
		int ind=0;
		rep(i,0,(1<<K)-1)if(POP(i)==t){
			id[t&1][i]=ind++;
		}
	};
	int o=0;
	id[0][0]=0;
	maxf[0]=mf[0][0].sol();
	rep(t,1,K){
		o^=1,init(t);
		rep(i,0,(1<<K)-1)if(POP(i)==t){
			vector<int>tem;
			rep(k,0,K-1)if(i>>k&1)tem.push_back(k);
			int p=tem[rng()%SZ(tem)];
			int j=i^(1<<p);
			mf[o][id[o][i]]=mf[o^1][id[o^1][j]];
			mf[o][id[o][i]].we[eid[p]]=25;
			maxf[i]=min(maxf[j]+mf[o][id[o][i]].work(),INF);
		}
	}
	rep(_,1,Q){
		rep(i,0,K-1){
			rd(w[i]);
		}
		int ans=maxf[(1<<K)-1];
		rep(i,1,(1<<K)-1){
			sum[i]=sum[i&(i-1)]+w[CTZ(i)];
			ans=min(ans,maxf[(1<<K)-1-i]+sum[i]);
		}
		pt(ans,'\n');
	}
	return 0;
}