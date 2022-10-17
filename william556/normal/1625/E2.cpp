#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=3e5+5;
int n,q;
char s[N];
int fa[N],tot;
int lp[N],rp[N];
vector<int> e[N];
int lid[N],rid[N];
long long f[N],sum[N],sum1[N];
int bfn[N],bfp[N],dfn[N],sz[N],dfn1[N];
bool vis[N];
int tim=0;
void dfs(int x){
	long long res=0;
	dfn[x]=++tim,sz[x]=e[x].size();
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		dfs(y);
		f[x]+=f[y];
		res+=f[y];
	}
	int l=e[x].size();
	f[x]+=1ll*l*(l-1)/2+1;
	lid[lp[x]]=x,rid[rp[x]]=x;
	dfn1[x]=tim;
}
void bfs(){
	queue<int> q;
	q.push(1);
	tim=0;
	while(q.size()){
		int x=q.front();q.pop();
		bfn[x]=++tim,bfp[tim]=x;
		for(int y:e[x])q.push(y);
	}
}
int c[N];
void add(int p,int v){
	for(int i=p;i<=tot;i+=i&-i)c[i]+=v;
}
int get(int p){
	int res=0;
	for(int i=p;i;i-=i&-i)res+=c[i];
	return res;
}
long long c1[N];
void add1(int p,long long v){
	for(int i=p;i<=tot;i+=i&-i)c1[i]+=v;
}
long long get1(int p){
	long long res=0;
	for(int i=p;i;i-=i&-i)res+=c1[i];
	return res;
}
int main(){
	n=in(),q=in();
	scanf("%s",s+1);
	tot=1;
	for(int i=1,p=1;i<=n;i++){
		if(s[i]=='('){
			fa[++tot]=p;
			e[p].push_back(tot);
			p=tot,lp[p]=i;
		}else{
			if(p!=1)rp[p]=i,p=fa[p];
		}
	}
	dfs(1);
	bfs();
	for(int i=1;i<=tot;i++)sum[i]=sum[i-1]+f[bfp[i]];
	while(q--){
		int t=in(),l=in(),r=in();
		l=lid[l],r=rid[r];
		if(t==1){	
			add(bfn[l],1);
			int x=fa[l];
			long long val=1ll*sz[x]*(sz[x]-1)/2;
			sz[x]--;
			val=1ll*sz[x]*(sz[x]-1)/2-val;
			add1(dfn[fa[l]],val);
			add1(dfn[l],-1);
		}else{
			long long ans=sum[bfn[r]]-sum[bfn[l]-1]+get1(dfn1[r])-get1(dfn[l]-1);
			int x=bfn[r]-bfn[l]+1-(get(bfn[r])-get(bfn[l]-1));
			ans+=1ll*x*(x-1)/2;
			printf("%lld\n",ans);
		}
		
		
	}
	return 0;
}