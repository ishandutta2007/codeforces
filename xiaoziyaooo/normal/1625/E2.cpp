#include<stdio.h>
#include<vector>
#include<queue>
#include<iostream>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=300005,maxt=maxn*30;
int n,m,top,dfns,bfns;
int stk[maxn],rec[maxn],fa[maxn],dfn[maxn],bfn[maxn],tt[maxn],sz[maxn];
long long t[maxn][2],f[maxn];
vector<int>v[maxn];
queue<int>q;
string s;
void update(int x,long long v,int k){
	if(x==0)
		return ;
	for(int i=x;i<=n;i+=lowbit(i))
		t[i][k]+=v;
}
long long query(int x,int k){
	long long res=0;
	for(int i=x;i;i-=lowbit(i))
		res+=t[i][k];
	return res;
}
void dfs(int x){
	dfn[x]=++dfns;
	int tot=0;
	sz[x]=1;
	for(int i=0;i<v[x].size();i++)
		dfs(v[x][i]),tt[x]++,sz[x]+=sz[v[x][i]];
	f[x]=1ll*tt[x]*(tt[x]+1)/2ll;
	if(x>0)
		update(dfn[x],f[x],1);
}
int main(){
	scanf("%d%d",&n,&m),cin>>s,s=" "+s;
	for(int i=0;i<=n;i++)
		fa[i]=-1;
	for(int i=1;i<=n;i++){
		if(s[i]=='(')
			stk[++top]=i;
		else{
			if(top==0)
				continue;
			rec[i]=stk[top],rec[stk[top]]=i,top--,fa[i]=stk[top];
		}
	}
	for(int i=1;i<=n;i++)
		if(fa[i]!=-1)
			fa[i]=rec[fa[i]],v[fa[i]].push_back(i);
	dfns=bfns=-1,q.push(0);
	while(!q.empty()){
		int x=q.front();
		q.pop(),bfn[x]=++bfns;
		if(x>0)
			update(bfn[x],1,0);
		for(int i=0;i<v[x].size();i++)
			q.push(v[x][i]);
	}
	dfs(0);
	for(int T=1,t,x,y;T<=m;T++){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
			tt[fa[y]]--,update(bfn[y],-1,0),update(dfn[fa[y]],-(tt[fa[y]]+1),1);
		if(t==2){
			x=rec[x];
			long long ans=query(dfn[y]+sz[y]-1,1)-query(dfn[x]-1,1),k=query(bfn[y],0)-query(bfn[x]-1,0);
			printf("%lld\n",ans+k*(k+1)/2ll);
		}
	}
	return 0;
}