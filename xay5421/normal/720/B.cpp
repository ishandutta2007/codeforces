// author: xay5421
// created: Wed Jun  2 09:08:24 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005,INF=0X3F3F3F3F;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int n,m,mm,uu[N*2],vv[N*2],ww[N*2],dfn[N],low[N],ind,top,st[N];
int pp=1,lnk[N],nxt[N*4],to[N*4];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
bool pd[N*2],ok[N*2];
map<pair<int,int>,int>mp;
vector<vector<int> >cycs;
void tarjan(int k1,int k2){
	//D("k1=%d\n",k1);
	dfn[k1]=low[k1]=++ind,st[++top]=k1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		if(!dfn[to[i]]){
			tarjan(to[i],k1),low[k1]=min(low[k1],low[to[i]]);
			if(low[to[i]]>=dfn[k1]){
				vector<int>v;
				do{
					v.push_back(st[top]);
				}while(st[top--]!=to[i]);
				v.push_back(k1);
				if(SZ(v)>2){
					vector<int>cyc;
					rep(i,0,SZ(v)-1){
						int id=mp[minmax(v[i],v[(i+1)%SZ(v)])];
						cyc.push_back(ww[id]);
						pd[id]=1;
					}
					cycs.push_back(cyc);
				}
			}
		}
		else low[k1]=min(low[k1],dfn[to[i]]);
	}
}
namespace maxflow{
	const int N=400005,M=N*4;
	int S,T,pp=1,lnk[N],cur[N],nxt[M],to[M],we[M];
	void ae(int k1,int k2,int k3){
		to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
		to[++pp]=k1,we[pp]=0,nxt[pp]=lnk[k2],lnk[k2]=pp;
	}
	void init(){
		S=mm+SZ(cycs)+1;
		T=S+1;
		rep(i,0,SZ(cycs)-1){
			int cur=mm+1+i;
			ae(S,cur,SZ(cycs[i])-1);
			for(int x:cycs[i]){
				ae(cur,x,1);
			}
		}
		rep(i,1,mm)if(!ok[i])ae(i,T,1);
	}
	int q[N],dep[N];
	bool bfs(){
		fill(dep+1,dep+1+T,-1);
		int he=0,ta=0;
		q[++ta]=S,dep[S]=0;
		while(he!=ta){
			int k1=q[++he];
			for(int i=lnk[k1];i;i=nxt[i])if(we[i]&&dep[to[i]]==-1){
				dep[to[i]]=dep[k1]+1;
				q[++ta]=to[i];
			}
		}
		return dep[T]!=-1;
	}
	int dfs(int k1,int k2){
		if(k1==T)return k2;
		int k3=k2;
		for(int&i=cur[k1];i;i=nxt[i])if(we[i]&&dep[to[i]]==dep[k1]+1){
			int f=dfs(to[i],min(we[i],k3));
			we[i]-=f,we[i^1]+=f,k3-=f;
			if(!k3)return k2;
		}
		dep[k1]=-1;
		return k2-k3;
	}
	int dinic(){
		int res=0;
		while(bfs()){
			memcpy(cur,lnk,sizeof(cur[0])*(T+1));
			res+=dfs(S,INF);
		}
		return res;
	}
}
int main(){
	rd(n),rd(m);
	static int _[N*2];
	rep(i,1,m){
		rd(uu[i]),rd(vv[i]),rd(ww[i]),_[i]=ww[i];
		mp[minmax(uu[i],vv[i])]=i;
	}
	sort(_+1,_+1+m);
	mm=unique(_+1,_+1+m)-_-1;
	rep(i,1,m)ww[i]=lower_bound(_+1,_+1+mm,ww[i])-_;
	rep(i,1,m){
		ae(uu[i],vv[i]);
		ae(vv[i],uu[i]);
	}
	rep(i,1,n)if(!dfn[i])tarjan(i,0);
	rep(i,1,m)if(!pd[i])ok[ww[i]]=1;
	int ans=0;
	rep(i,1,mm)if(ok[i])++ans;
	D("!!\n");
	maxflow::init();
	printf("%d\n",ans+maxflow::dinic());
	return 0;
}