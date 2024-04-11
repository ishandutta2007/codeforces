#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005,INF=0X3F3F3F3F;
int n,rt,ans[N];
int fa[N],sz[N],son[N];
int pp,lnk[N],nxt[N*2],to[N*2];
multiset<int>S[N],other,anc;
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs1(int k1,int k2){
	fa[k1]=k2,sz[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dfs1(to[i],k1);
		sz[k1]+=sz[to[i]];
		if(sz[to[i]]>sz[son[k1]])son[k1]=to[i];
	}
	other.insert(sz[k1]);
}
void dfs2(int k1,int k2){
	D("ha %d %d\n",k1,k2);
	if(k1!=rt){
		assert(other.find(sz[k1])!=other.end());
		other.erase(other.find(sz[k1]));
		if(fa[k1]!=rt){
			anc.insert(sz[fa[k1]]);
		}
	}
	int mx=~INF,smx=~INF,mn=INF;
	auto ps=[&](int x){
		if(k1==1)D(">> ps %d %d\n",k1,x);
		if(mx<x)smx=mx,mx=x;
		else if(smx<x)smx=x;
		mn=min(mn,x);
	};
	if(k1!=rt){
		ps(n-sz[k1]);
	}
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&to[i]!=son[k1]){
		dfs2(to[i],k1);
		ps(sz[to[i]]);
		for(auto x:S[to[i]])other.insert(x);
	}
	if(son[k1]){
		dfs2(son[k1],k1);
		ps(sz[son[k1]]);
	}
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&to[i]!=son[k1]){
		for(auto x:S[to[i]])other.erase(other.find(x));
	}
	if(mx==smx){
		if(mx!=~INF)ans[k1]=mx;
	}
	else{
		int mid=(mx-mn)/2;
		if(sz[son[k1]]==mx){
			auto it=S[son[k1]].lower_bound(mid);
			if(it!=S[son[k1]].end()){
				ans[k1]=min(ans[k1],max({mx-*it,mn+*it,smx}));
			}
			if(it!=S[son[k1]].begin()){
				--it;
				ans[k1]=min(ans[k1],max({mx-*it,mn+*it,smx}));
			}
		}
		else{
			{
				int dt=-sz[k1];
				auto it=anc.lower_bound(mid-dt);
				if(it!=anc.end()){
					ans[k1]=min(ans[k1],max({mx-*it-dt,mn+*it+dt,smx}));
				}
				if(it!=anc.begin()){
					--it;
					ans[k1]=min(ans[k1],max({mx-*it-dt,mn+*it+dt,smx}));
				}
			}
			{
				auto it=other.lower_bound(mid);
				if(it!=other.end()){
					ans[k1]=min(ans[k1],max({mx-*it,mn+*it,smx}));
				}
				if(it!=other.begin()){
					--it;
					ans[k1]=min(ans[k1],max({mx-*it,mn+*it,smx}));
				}
			}
		}
	}
	if(son[k1]){
		swap(S[k1],S[son[k1]]);
	}
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&to[i]!=son[k1]){
		for(auto x:S[to[i]])S[k1].insert(x);
	}
	S[k1].insert(sz[k1]);
	if(k1!=rt&&fa[k1]!=rt){
		anc.erase(anc.find(sz[fa[k1]]));
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n)ans[i]=n-1;
	rep(i,1,n){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		if(!k1||!k2)rt=k1+k2;
		else ae(k1,k2),ae(k2,k1);
	}
	dfs1(rt,0);
	dfs2(rt,0);
	D("-----\n");
	rep(i,1,n)printf("%d\n",ans[i]);
	return 0;
}