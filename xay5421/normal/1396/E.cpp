#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define X first
#define Y second
#define PB push_back
#define SZ(x) (int((x).size()))
using namespace std;
typedef long long LL;
const int N=100005,INF=0X3F3F3F3F;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;

int n;
LL K;

int pp=1,lnk[N],nxt[N*2],_lnk[N*2],_nxt[N*2],pre[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],pre[lnk[k1]]=pp,lnk[k1]=pp;}
void del_e(int k1,int k2){
	if(k2==lnk[k1]){
		lnk[k1]=nxt[lnk[k1]];
	}else{
		nxt[pre[k2]]=nxt[k2];
		pre[nxt[k2]]=pre[k2];
	}
}

int rt,f[N],sz[N];
void grt(int k1,int k2){
	f[k1]=0,sz[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		grt(to[i],k1);
		sz[k1]+=sz[to[i]];
		if(f[k1]<sz[to[i]])f[k1]=sz[to[i]];
	}
	if(f[k1]<n-sz[k1])f[k1]=n-sz[k1];
	if(f[k1]<f[rt])rt=k1;
}

int dep[N],tofa[N],bel[N],ban[N];
struct cmp{
	bool operator()(const int&k1,const int&k2)const{return dep[k1]^dep[k2]?dep[k1]<dep[k2]:k1<k2;}
};
set<int,cmp>S[N];
set<pair<int,int> >T;
void dfs1(int k1,int k2){
	sz[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dep[to[i]]=dep[k1]+1;
		dfs1(to[i],k1),sz[k1]+=sz[to[i]];
	}
}
void dfs2(int k1,int k2,int k3){
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		tofa[to[i]]=i;
		dfs2(to[i],k1,k3==-1?to[i]:k3);
	}else del_e(k1,i);
	if(k3!=-1){
		bel[k1]=k3;
		if(lnk[k1])S[bel[k1]].insert(k1);
	}
}
void del_v(int k1){
	int k2=to[tofa[k1]^1];
	ban[k1]=1;
	if(k1!=rt){
		del_e(k2,tofa[k1]);
		S[bel[k1]].erase(k1);
		if(!lnk[k2]){
			S[bel[k2]].erase(k2);
		}
	}
}

vector<int>vv;
void dfs3(int k1,int k2){
	if(!ban[k1])vv.PB(k1);
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2)dfs3(to[i],k1);
}

int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%lld",&n,&K);
	rep(i,2,n){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	memcpy(_lnk,lnk,sizeof(lnk));
	memcpy(_nxt,nxt,sizeof(nxt));
	rt=0,f[0]=INF;
	grt(1,0);
	dfs1(rt,0);
	LL mn=0,mx=0;
	rep(i,1,n){
		mx+=dep[i];
		mn+=sz[i]&1;
	}
	if(K<mn||K>mx||(K&1)!=(mn&1)){
		puts("NO");
		return 0;
	}
	dfs2(rt,0,-1);
	for(int i=lnk[rt];i;i=nxt[i]){
		T.insert(make_pair(sz[to[i]],to[i]));
	}
	puts("YES");
	LL rest=mx-K;
	while(rest){
		D("233\n");
		auto big=(--T.end())->Y;
		T.erase(--T.end());
		if(SZ(S[big])==0){
			D("GG\n");
		}
		int k1=*--S[big].end();
		if(dep[k1]*2<rest){
			rest-=dep[k1]*2;
			vector<int>v;
			D(">>> k1=%d\n",k1);
			assert(lnk[k1]);
			for(int i=lnk[k1];i;i=nxt[i])if(i!=(tofa[k1]^1)){
				v.PB(to[i]);
				if(SZ(v)>1)break;
			}
			if(SZ(v)<2)v.PB(k1);
			assert(!ban[v[0]]&&!ban[v[1]]);
			printf("%d %d\n",v[0],v[1]);
			D("del %d %d\n",v[0],v[1]);
			del_v(v[0]),del_v(v[1]);
			if((sz[big]-=2)>1){
				T.insert(make_pair(sz[big],big));
			}
		}else{
			dep[0]=rest/2;
			k1=*S[big].lower_bound(0);
			vector<int>v;
			for(int i=lnk[k1];i;i=nxt[i])if(i!=(tofa[k1]^1)){
				v.PB(to[i]);
				if(SZ(v)>1)break;
			}
			if(SZ(v)<2)v.PB(k1);
			printf("%d %d\n",v[0],v[1]);
			ban[v[0]]=ban[v[1]]=1;
			break;
		}
	}
	memcpy(lnk,_lnk,sizeof(lnk));
	memcpy(nxt,_nxt,sizeof(nxt));
	dfs3(rt,0);
	rep(i,0,SZ(vv)/2-1)printf("%d %d\n",vv[i],vv[i+SZ(vv)/2]);
	return 0;
}