// author: xay5421
// created: Wed Aug 18 08:38:16 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244853;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
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
					//q.push(G[i].to);
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
	void sol(){
		mc=0,mf=0;
		while(spfa()){
			zg1();
		}
		mc*=op;
	}
}f;
const int inv2=po(2,P-2),inv4=po(4,P-2),inv8=po(8,P-2),N=105;
int n,m,ans1,ans2,deg[N],g[N][N];
int zip(int k1,int k2){return(k1-1)*n+k2;}
void sol(){
	f.init(n*2+n*n);
	rep(i,1,n)rep(j,i+1,n)if(g[i][j]==-1){
		f.ae(f.S,zip(i,j)+n*2,1,0);
		f.ae(zip(i,j)+n*2,i,1,0);
		f.ae(zip(i,j)+n*2,j,1,0);
	}
	rep(i,1,n){
		ans1+=deg[i]*(deg[i]-1)/2;
		f.ae(i+n,f.T,INF,0);
	}
	rep(i,1,n){
		rep(j,deg[i],n){
			f.ae(i,i+n,1,j);
		}
	}
	f.sol();
	rep(i,1,n){
		rep(j,1,n){
			if(i==j)g[i][j]=0;
			if(i<j){
				if(g[i][j]==-1){
					int k1=zip(i,j)+n*2,_=0;
					for(int k=f.lnk[k1];k!=-1;k=f.G[k].nxt){
						++_;
						if(_==2&&f.G[k].w==0)g[i][j]=1,g[j][i]=0;
						if(_==1&&f.G[k].w==0)g[i][j]=0,g[j][i]=1;
					}
				}
			}
			putchar(g[i][j]+'0');
		}
		puts("");
	}
}
int main(){
	scanf("%d%d",&n,&m);
	memset(g,-1,sizeof(g));
	rep(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=1,g[v][u]=0;
		++deg[u];
	}
	sol();
	return 0;
}