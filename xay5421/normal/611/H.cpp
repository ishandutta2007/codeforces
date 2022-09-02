#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005,INF=0X3F3F3F3F;
int n,lg[N],ind,len,g[10][10],fa[10],id[10][10],cnt[10];
char s[10];
int rds(){
	scanf("%s",s);
	return strlen(s);
}
struct ufs{
	int fa[N];
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	void init(int n){
		rep(i,1,n)fa[i]=i;
	}
}o;
bool chk(){
	o.init(len);
	int tt=0;
	rep(i,1,len){
		if(fa[i]){
			o.fa[o.fd(i)]=o.fd(fa[i]);
		}
		else ++tt;
	}
	if(tt!=1)return 0;
	rep(i,1,len)if(o.fd(i)!=o.fd(1)){
		return 0;
	}
	return 1;
}
int S,T;
struct maxFlow{
	int pp,lnk[1005],cur[1005],nxt[1005],to[1005],we[1005];
	int dep[1005],gap[1005];
	void clear(){
		rep(i,1,ind)lnk[i]=0;
		pp=1;
	}
	void ae(int k1,int k2,int k3){
		//D("ae %d %d %d\n",k1,k2,k3);
		to[++pp]=k2,nxt[pp]=lnk[k1],we[pp]=k3,lnk[k1]=pp;
		to[++pp]=k1,nxt[pp]=lnk[k2],we[pp]= 0,lnk[k2]=pp;
	}
	int sap(int k1,int k2){
		if(k1==T)return k2;
		int v=k2;
		for(int&i=cur[k1];i;i=nxt[i])if(we[i]&&dep[k1]==dep[to[i]]+1){
			int f=sap(to[i],min(v,we[i]));
			we[i]-=f,we[i^1]+=f,v-=f;
			if(!v)return k2;
		}
		if(!--gap[dep[k1]++])dep[S]=T+1;
		++gap[dep[k1]],cur[k1]=lnk[k1];
		return k2-v;
	}
	void sol(){
		int res=0;
		rep(i,1,T)cur[i]=lnk[i],dep[i]=0,gap[i]=0;
		gap[0]=T;
		while(dep[S]<=T){
			res+=sap(S,INF);
		}
		//D("res=%d\n",res);
		if(res==n-1-len+1){
			vector<vector<int> >node(len+1);
			vector<int>sym(len+1);
			rep(i,1,n){
				node[lg[i]+1].PB(i);
			}
			rep(i,1,len){
				sym[i]=node[i].back();
				node[i].pop_back();
			}
			rep(i,1,len){
				if(fa[i]){
					printf("%d %d\n",sym[i],sym[fa[i]]);
				}
			}
			rep(k1,1,len){
				for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=S){
					rep(j,1,len)if(to[i]==id[k1][j]){
						int tt=INF-we[i];
						//D("%d %d %d\n",k1,j,tt);
						while(tt--){
							assert(SZ(node[k1]));
							printf("%d %d\n",sym[j],node[k1].back());
							node[k1].pop_back();
						}
					}
				}
			}
			exit(0);
		}
	}
}mf;
void work(){
	mf.clear();
	rep(i,1,len){
		mf.ae(S,i,cnt[i]-1);
	}
	rep(i,1,len){
		rep(j,1,len){
			mf.ae(i,id[i][j],INF);
		}
	}
	rep(i,1,len)rep(j,i,len)mf.ae(id[i][j],T,g[i][j]);
	mf.sol();
}
void sol(){
	bool flg=1;
	rep(i,1,len){
		if(fa[i]){
			int k1=i,k2=fa[i];
			if(k1>k2)swap(k1,k2);
			if(--g[k1][k2]<0)flg=0;
		}
	}
	if(flg){
		/*D("-----\n");
		rep(i,1,len){
			D("fa[%d]=%d\n",i,fa[i]);
		}*/
		work();
	}
	rep(i,1,len){
		if(fa[i]){
			int k1=i,k2=fa[i];
			if(k1>k2)swap(k1,k2);
			++g[k1][k2];
		}
	}
}
void dfs(int k1){
	if(k1>len){
		if(chk()){
			sol();
		}
		return;
	}
	rep(i,0,len){
		fa[k1]=i;
		dfs(k1+1);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,10,N-1)lg[i]=lg[i/10]+1;
	scanf("%d",&n);
	len=lg[n]+1,ind=len;
	rep(i,1,n)++cnt[lg[i]+1];
	rep(i,1,len)rep(j,i,len){
		id[i][j]=++ind;
	}
	S=++ind,T=++ind;
	rep(i,1,len)rep(j,1,i-1){
		id[i][j]=id[j][i];
	}
	rep(i,1,n-1){
		int k1=rds(),k2=rds();
		if(k1>k2)swap(k1,k2);
		++g[k1][k2];
	}
	dfs(1);
	puts("-1");
	return 0;
}