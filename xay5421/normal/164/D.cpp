#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=1005;
int n,K,x[N],y[N],choose[N],deg[N];
vector<int>G[N];
vector<int>res;
struct cmp{
	bool operator()(const int&k1,const int&k2)const{return deg[k1]>deg[k2];}
};
set<int,cmp>S;
void remove(int k1){
	assert(!choose[k1]);
	choose[k1]=1;
	for(auto x:G[k1])if(!choose[x]){
		--deg[k1];
		--deg[x];
	}
}
void restore(int k1){
	assert(choose[k1]);
	choose[k1]=0;
	for(auto x:G[k1])if(!choose[x]){
		++deg[k1];
		++deg[x];
	}
}
bool dfs(int remain){
	int tt=0;
	rep(i,1,n){
		if(choose[i])++tt;
	}
	assert(tt+remain==K);
	if(remain==0){
		rep(i,1,n)if(deg[i])return 0;
		return 1;
	}
	int pos=-1;
	rep(i,1,n)if(!choose[i]&&deg[i]==1){
		pos=i;
		break;
	}
	if(pos!=-1){
		int tem=-1;
		for(auto x:G[pos])if(!choose[x]){
			tem=x;
			break;
		}
		assert(tem!=-1);
		remove(tem);
		if(dfs(remain-1))return 1;
		restore(tem);
		return 0;
	}
	int u=0;
	rep(i,1,n)if(!choose[i]&&deg[i]>deg[u])u=i;
	if(deg[u]==0){
		remove(u);
		assert(dfs(remain-1));
		return 1;
	}
	remove(u);
	if(dfs(remain-1))return 1;
	restore(u);
	if(deg[u]>1&&remain-deg[u]>=0){
		vector<int>v;
		for(auto x:G[u])if(!choose[x])v.PB(x);
		assert(SZ(v)==deg[u]);
		int tmp=deg[u];
		for(auto x:v)remove(x);
		if(dfs(remain-tmp)){
			return 1;
		}
		for(auto x:v)restore(x);
	}
	return 0;
}
bool chk(int mid){
	rep(i,1,n)G[i].clear(),choose[i]=0,deg[i]=0;
	rep(i,1,n)rep(j,i+1,n){
		if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])>mid){
			G[i].PB(j),G[j].PB(i);
			++deg[i],++deg[j];
		}
	}
	return dfs(K);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	deg[0]=-1;
	scanf("%d%d",&n,&K);
	rep(i,1,n){
		scanf("%d%d",&x[i],&y[i]);		
	}
	int l=0,r=2*32000*32000,ans=0;
	while(l<=r){
		int mid=((r-l)>>1)+l;
		D("%d\n",mid);
		if(chk(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	chk(ans);
	D("ans=%d\n",ans);
	rep(i,1,n)if(choose[i])printf("%d ",i);
	puts("");
	return 0;
}