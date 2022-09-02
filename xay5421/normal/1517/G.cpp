// author: xay5421
// created: Sat Apr 24 16:11:57 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=1005,M=100005;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,x[N],y[N],w[N],id[N],ind,in[N],out[N],S,T;
map<pair<int,int>,int>mp;
int pp=1,lnk[N*2],cur[N*2],to[M],nxt[M]; LL we[M];
void ae(int k1,int k2,LL k3){
	//D("ae %d %d %lld\n",k1,k2,k3);
	to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
	to[++pp]=k1,we[pp]=0, nxt[pp]=lnk[k2],lnk[k2]=pp;
}
int ID(int x,int y){
	if(x&1){
		if(y&1)return 3;
		else return 2;
	}else{
		if(y&1)return 0;
		else return 1;
	}
}
int q[N*2],pre[N*2],dep[N*2];
bool bfs(){
	rep(i,1,ind)pre[i]=0,dep[i]=-1;
	int he=0,ta=0;
	q[++ta]=S,dep[S]=1;
	while(he!=ta){
		int k1=q[++he];
		for(int i=lnk[k1];i;i=nxt[i])if(dep[to[i]]==-1&&we[i]){
			dep[to[i]]=dep[k1]+1;
			pre[to[i]]=i;
			q[++ta]=to[i];
			if(to[i]==T)return 1;
		}
	}
	return 0;
}
LL dfs(int k1,int k2,LL k3){
	if(k1==k2)return k3;
	LL k4=k3;
	for(int&i=cur[k1];i;i=nxt[i])if(dep[k1]+1==dep[to[i]]&&we[i]){
		LL f=dfs(to[i],k2,min(k4,we[i]));
		we[i]-=f,we[i^1]+=f,k4-=f;
		if(k4==0)return k3;
	}
	dep[k1]=-1;
	return k3-k4;
}
LL dinic(){
	LL res=0;
	while(bfs()){
		memcpy(cur,lnk,(ind+1)*4);
		res+=dfs(S,T,INFLL);
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	LL sum=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d%d",&x[i],&y[i],&w[i]),swap(x[i],y[i]),sum+=w[i];
		mp[make_pair(x[i],y[i])]=i;
	}
	S=++ind,T=++ind;
	rep(i,1,n){
		id[i]=ID(x[i],y[i]);
		if(id[i]==0||id[i]==3){
			in[i]=out[i]=++ind;
			if(id[i]==0)ae(S,in[i],w[i]);
			if(id[i]==3)ae(out[i],T,w[i]);
		}else{
			in[i]=++ind,out[i]=++ind;
			ae(in[i],out[i],w[i]);
		}
	}
	rep(i,1,n){
		if(id[i]==0||id[i]==2){
			if(mp.count(make_pair(x[i],y[i]-1))){
				ae(out[i],in[mp[make_pair(x[i],y[i]-1)]],INFLL);
			}
			if(mp.count(make_pair(x[i],y[i]+1))){
				ae(out[i],in[mp[make_pair(x[i],y[i]+1)]],INFLL);
			}
		}else if(id[i]==1){
			if(mp.count(make_pair(x[i]-1,y[i]))){
				ae(out[i],in[mp[make_pair(x[i]-1,y[i])]],INFLL);
			}
			if(mp.count(make_pair(x[i]+1,y[i]))){
				ae(out[i],in[mp[make_pair(x[i]+1,y[i])]],INFLL);
			}
		}
	}
	printf("%lld\n",sum-dinic());
	return 0;
}