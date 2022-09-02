// author: xay5421
// created: Sat Apr 24 19:38:16 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=998244353;
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
const int N=305;
int n,R,f[N][N],g[N][N],_f[N],_g[N],dep[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs(int k1,int k2){
	f[k1][0]=g[k1][0]=1,dep[k1]=0;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dfs(to[i],k1);
		int _dep=max(dep[k1],dep[to[i]]+1);
		memset(_f,0,(_dep+1)*4);
		memset(_g,0,(_dep+1)*4);
		rep(a,0,dep[k1]){
			rep(b,0,dep[to[i]]){
				uad(_f[min(a,b+1)],mu(f[k1][a],f[to[i]][b]));
				uad(_g[max(a,b+1)],mu(g[k1][a],g[to[i]][b]));
				if(a+b+1<=R)uad(_f[a],mu(f[k1][a],g[to[i]][b])),uad(_f[b+1],mu(g[k1][a],f[to[i]][b]));
				else uad(_g[b+1],mu(f[k1][a],g[to[i]][b])),uad(_g[a],mu(g[k1][a],f[to[i]][b]));
			}
		}
		dep[k1]=_dep;
		rep(i,0,dep[k1])f[k1][i]=_f[i],g[k1][i]=_g[i];
	}
}
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	int lst=0,ans=0;
	for(R=1;R<=n;++R){
		dfs(1,0);
		int cur=0;
		rep(j,0,n)uad(cur,f[1][j]);
		uad(ans,mu(su(cur,lst),R-1));
		lst=cur;
	}
	ans=ad(ans,n-1);
	printf("%d\n",mu(ans,po((P+1)>>1,n)));
	return 0;
}