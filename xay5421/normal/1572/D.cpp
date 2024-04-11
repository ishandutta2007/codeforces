// author: xay5421
// created: Mon Sep 20 20:04:28 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
typedef long long LL;
const int INF=0X3F3F3F3F;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
struct MCMF{
	int S,T;
	vector<int>lnk,pre;
	int mf;
	LL mc;
	int op;
	// min-cost-max-flow if op==+1 (default)
	// max-cost-max-flow if op==-1
	struct edge{
		int nxt,to,w;
		LL c;
	};
	vector<edge>G;
	MCMF(){}
	MCMF(int n,int _op=1){
		init(n,_op);
	}
	void init(int n,int _op=1){
		S=0,T=n+1,op=_op;
		lnk.assign(T+1,-1);
		G.clear();
	}
	void ae(int k1,int k2,int k3,LL k4){
		k4*=op;
		//D("ae %d %d %d %lld\n",k1,k2,k3,k4);
		G.push_back((edge){lnk[k1],k2,k3,k4}),lnk[k1]=((int)G.size())-1;
		G.push_back((edge){lnk[k2],k1,0,-k4}),lnk[k2]=((int)G.size())-1;
	}
	vector<LL>dis;
	vector<bool>vis;
	queue<int>q;
	bool spfa(){
		pre.assign(T+1,-1);
		dis.assign(T+1,INFLL);
		vis.assign(T+1,0);
		while(!q.empty())q.pop();
		dis[S]=0;
		vis[S]=1;
		q.push(S);
		while(!q.empty()){
			int k1=q.front();
			vis[k1]=0;
			q.pop();
			for(int i=lnk[k1];i!=-1;i=G[i].nxt)if(G[i].w&&dis[k1]+G[i].c<dis[G[i].to]){
				dis[G[i].to]=dis[k1]+G[i].c;
				pre[G[i].to]=i;
				if(!vis[G[i].to]){
					vis[G[i].to]=1;
					if(SZ(q)&&dis[G[i].to]<dis[q.front()]){
						q.push(q.front());
						q.front()=G[i].to;
					}else q.push(G[i].to);
					// q.push(G[i].to);
				}
			}
		}
		return dis[T]!=INFLL;
	}
	void zg1(){
		int f=INF;
		for(int i=pre[T];i!=-1;i=pre[G[i^1].to])f=min(f,G[i].w);
		for(int i=pre[T];i!=-1;i=pre[G[i^1].to])G[i].w-=f,G[i^1].w+=f;
		mf+=f;
		mc+=f*dis[T];
	}
	void sol(int K){
		mc=0,mf=0;
		while(spfa()){
			zg1();
			if(!--K)break;
		}
		mc*=op;
	}
};
int n,K,a[(1<<20)+5],id[(1<<20)+5];
bool good[(1<<20)+5];
vector<tuple<int,int,int> >es;
int main(){
	rd(n),rd(K);
	rep(i,0,(1<<n)-1)rd(a[i]);
	rep(i,0,(1<<n)-1)if(__builtin_popcount(i)&1){
		rep(j,0,n-1){
			es.eb(a[i]+a[i^(1<<j)],i,i^(1<<j));
		}
	}
	sort(es.begin(),es.end(),greater<tuple<int,int,int> >());
	for(int i=0;i<SZ(es)&&i<=K*n*2;++i){
		good[get<1>(es[i])]=good[get<2>(es[i])]=1;
	}
	int ind=0;
	rep(i,0,(1<<n)-1)if(good[i]){
		id[i]=++ind;
	}
	MCMF f(ind,-1);
	rep(i,0,(1<<n)-1)if(good[i]){
		if(__builtin_popcount(i)&1){
			f.ae(f.S,id[i],1,a[i]);
		}else{
			f.ae(id[i],f.T,1,a[i]);
		}
	}
	rep(i,0,(1<<n)-1)if((__builtin_popcount(i)&1)&&good[i]){
		rep(j,0,n-1)if(good[i^(1<<j)]){
			f.ae(id[i],id[i^(1<<j)],1,0);
		}
	}
	f.sol(K);
	printf("%lld\n",f.mc);
	return 0;
}