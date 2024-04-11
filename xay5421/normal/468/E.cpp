// author: xay5421
// created: Sat Jun 19 09:56:50 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=115;
int n,m,pre[N],e[N][N],fac[100005],f[N][2][60],g[2][60],sz[N];
int pp=1,lnk[N],nxt[N*2],to[N*2],we[N*2];
bool vis[N],pd[N],ban[N];
void ae(int k1,int k2,int k3){
	e[k1][k2]=k3;
	to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
}
struct edge{
	int u,v,w;
};
int main(){
	fac[0]=fac[1]=1;
	rep(i,2,100004)fac[i]=mu(fac[i-1],i);
	scanf("%d%d",&n,&m);
	map<int,int>mpx,mpy;
	int ind=0;
	rep(i,1,m){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z==1)continue;
		--z;
		if(!mpx.count(x))mpx[x]=++ind;
		x=mpx[x];
		if(!mpy.count(y))mpy[y]=++ind;
		y=mpy[y];
		ae(x,y,z);
		ae(y,x,z);
	}
	vector<int>dp(ind+1); dp[0]=1;
	rep(rt,1,ind)if(!vis[rt]){
		int _n=0,_m=0;
		vector<edge>es;
		vector<int>nds[2];
		function<void(int,int,int)>dfs1=[&](int k1,int k2,int k3){
			++_n,vis[k1]=1,nds[k3].push_back(k1);
			for(int i=lnk[k1];i;i=nxt[i]){
				if(to[i]!=k2){
					if(!vis[to[i]])pre[to[i]]=k1,dfs1(to[i],k1,k3^1);
					else{
						ban[i]=1;
						if(~i&1)
							es.push_back((edge){k1,to[i],we[i]});
					}
				}
				++_m;
			}
		};
		dfs1(rt,0,0);
		assert(_m%2==0),_m>>=1;
		vector<int>coef(_n+1);
		if(_n<=_m*2/3){
			D("sol1\n");
			if(SZ(nds[0])<SZ(nds[1]))swap(nds[0],nds[1]);
			vector<int>old(1<<SZ(nds[1])); old[0]=1;
			rep(i,0,SZ(nds[0])-1){
				int*E=e[nds[0][i]];
				vector<int>now(old);
				rep(j,0,SZ(nds[1])-1)if(E[nds[1][j]]){
					rep(s,0,(1<<SZ(nds[1]))-1)if(s>>j&1){
						uad(now[s],mu(old[s^(1<<j)],E[nds[1][j]]));
					}
				}
				swap(now,old);
			}
			rep(i,0,(1<<SZ(nds[1]))-1){
				uad(coef[__builtin_popcount(i)],old[i]);
			}
		}else{
			D("sol2\n");
			function<void(int,int)>treedp=[&](int k1,int k2){
				sz[k1]=1;
				memset(f[k1],0,sizeof(f[k1]));
				if(pd[k1]){
					f[k1][0][0]=0;
					f[k1][1][0]=1;
				}else{
					f[k1][0][0]=1;
					f[k1][1][0]=0;
				}
				for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&!ban[i]){
					treedp(to[i],k1);
					rep(x,0,1)rep(y,0,(sz[k1]+sz[to[i]])/2)g[x][y]=0;
					rep(a,0,1)rep(b,0,sz[k1]/2){
						rep(x,0,1)rep(y,0,sz[to[i]]/2){
							uad(g[a][b+y],mu(f[k1][a][b],f[to[i]][x][y]));
							if(!a&&!x){
								uad(g[1][b+y+1],mu(f[k1][0][b],f[to[i]][0][y],we[i]));
							}
						}
					}
					rep(x,0,1)rep(y,0,(sz[k1]+sz[to[i]])/2)f[k1][x][y]=g[x][y];
					sz[k1]+=sz[to[i]];
				}
			};
			assert(SZ(es)==_m-(_n-1));
			rep(i,0,(1<<SZ(es))-1){
				int ws=1;
				rep(j,0,SZ(es)-1)pd[es[j].u]=pd[es[j].v]=0;
				rep(j,0,SZ(es)-1){
					if(i>>j&1){
						if(pd[es[j].u]||pd[es[j].v])ws=0;
						pd[es[j].u]=pd[es[j].v]=1;
						ws=mu(ws,es[j].w);
					}
				}
				if(!ws)continue;
				treedp(rt,0);
				rep(j,0,sz[rt]/2)if(f[rt][0][j]||f[rt][1][j]){
					uad(coef[j+__builtin_popcount(i)],mu(ws,ad(f[rt][0][j],f[rt][1][j])));
				}
			}
		}
		vector<int>ndp(ind+1);
		per(i,ind,0)if(dp[i]){
			rep(j,0,_n)if(coef[j])uad(ndp[i+j],mu(dp[i],coef[j]));
		}
		dp=ndp;
	}
	int ans=0;
	rep(i,0,ind)if(i<=n)uad(ans,mu(dp[i],fac[n-i]));
	printf("%d\n",ans);
	return 0;
}