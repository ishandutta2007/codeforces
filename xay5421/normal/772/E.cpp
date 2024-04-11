#include<bits/stdc++.h>
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=2005,INF=0X3F3F3F3F;
int n,ind,lc[N],rc[N],fa[N],ban[N],sz[N],rt,f[N],all;
vector<int>G[N];
char ask(int k1,int k2,int k3){
	printf("%d %d %d\n",k1,k2,k3);
	fflush(stdout);
	char s[3];
	scanf("%s",s);
	return s[0];
}
int getason(int k1){
	while(k1>n)k1=lc[k1];
	return k1;
}
void gsz(int k1,int k2){
	sz[k1]=1;
	for(auto j:G[k1])if(j!=k2&&!ban[j])gsz(j,k1),sz[k1]+=sz[j];
}
void grt(int k1,int k2){
	f[k1]=0;
	for(auto j:G[k1])if(j!=k2&&!ban[j]){
		grt(j,k1);
		f[k1]=max(f[k1],sz[j]);
	}
	f[k1]=max(f[k1],all-sz[k1]);
	if(f[k1]<f[rt])rt=k1;
}
void push(int k1){
	rep(i,1,ind)ban[i]=0;
	rep(i,1,ind)G[i].clear();
	rep(i,1,ind)if(fa[i]){
		G[fa[i]].PB(i);
		G[i].PB(fa[i]);
	}
	int u=1;
	while(1){
		rt=0;
		gsz(u,0);
		all=sz[u];
		grt(u,0);
		u=rt;
		if(u<=n){
			u=fa[u];
		}
		int t=ask(getason(lc[u]),getason(rc[u]),k1);
		if(t=='X'){
			ban[u]=1;
			if(!fa[u]||ban[fa[u]]){
				++ind;
				fa[ind]=fa[u];
				if(fa[u]){
					if(lc[fa[u]]==u){
						lc[fa[u]]=ind;
					}else{
						rc[fa[u]]=ind;
					}
				}
				fa[u]=ind,lc[ind]=u;
				fa[k1]=ind,rc[ind]=k1;
				return;
			}
			u=fa[u];
		}else if(t=='Y'){
			ban[u]=1;
			if(rc[u]<=n||ban[rc[u]]){
				u=rc[u];
				++ind;
				fa[ind]=fa[u];
				rc[fa[u]]=ind;
				fa[u]=ind,lc[ind]=u;
				fa[k1]=ind,rc[ind]=k1;
				return;
			}
			u=rc[u];
		}else{
			ban[u]=1;
			if(lc[u]<=n||ban[lc[u]]){
				u=lc[u];
				++ind;
				fa[ind]=fa[u];
				lc[fa[u]]=ind;
				fa[u]=ind,lc[ind]=u;
				fa[k1]=ind,rc[ind]=k1;
				return;
			}
			u=lc[u];
		}
	}
}
int main(){
	scanf("%d",&n),ind=n;
	fa[1]=fa[2]=++ind,lc[ind]=1,rc[ind]=2;
	f[0]=INF;
	rep(i,3,n){
		push(i);
	}
	puts("-1");
	rep(i,1,ind)if(fa[i])printf("%d ",fa[i]);else printf("%d ",-1);
	return 0;
}