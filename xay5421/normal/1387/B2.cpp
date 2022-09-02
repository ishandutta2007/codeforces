#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005;
typedef long long LL;
typedef vector<int>VI;
int n,sz[N],f[N],fa[N],go[N];VI G[N],S[N];LL ans;
void dfs(int k1,int k2){
	fa[k1]=k2,sz[k1]=1;
	for(auto j:G[k1])if(j!=k2){
		dfs(j,k1);
		sz[k1]+=sz[j];
	}
	if(k2){
		ans+=2LL*min(sz[k1],(n-sz[k1]));
	}
}
void get(int k1,int k2,int k3){
	S[k3].PB(k1);
	for(auto j:G[k1])if(j!=k2)get(j,k1,k3);
}
struct cmp{
	bool operator()(const int&k1,const int&k2)const{
		return SZ(S[k1])!=SZ(S[k2])?SZ(S[k1])>SZ(S[k2]):k1<k2;
	}
};
set<int,cmp>st;
void ae(int k1,int k2){
//	printf("ae:%d %d\n",k1,k2);
	go[k1]=k2,go[k2]=k1;
}
void sol(int k1){
	for(auto j:G[k1]){
		get(j,k1,j),st.insert(j);
	}
	S[k1].PB(k1),st.insert(k1);
	int tmp=-1;
	while(SZ(st)){
		if(SZ(st)==1){
			int k1=*st.begin();
			if(SZ(S[k1])==1){
				go[go[tmp]]=S[k1].back(),go[S[k1].back()]=tmp;
				return;
			}
			int u=tmp=S[k1].back();
			S[k1].pop_back();
			int v=S[k1].back();
			S[k1].pop_back();
			ae(u,v);
			if(SZ(S[k1])==0)exit(0);
			continue;
		}
		int k1=*st.begin();
		int k2=*++st.begin();
		st.erase(k1),st.erase(k2);
		ae(tmp=S[k1].back(),S[k2].back());
		S[k1].pop_back(),S[k2].pop_back();
		if(SZ(S[k1]))st.insert(k1);
		if(SZ(S[k2]))st.insert(k2);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int k1,k2;scanf("%d%d",&k1,&k2);
		G[k1].PB(k2),G[k2].PB(k1);
	}
	int rt=1;
	dfs(rt,0);
	int id=1;
	rep(i,1,n){
		f[i]=0;
		for(auto j:G[i])if(j!=fa[i])f[i]=max(f[i],sz[j]);
		f[i]=max(f[i],sz[rt]-sz[i]);
		if(f[i]<f[id]){
			id=i;
		}
	}
	rt=id;
	sol(id);
	printf("%lld\n",ans);
	rep(i,1,n)printf("%d ",go[i]);
	return 0;
}