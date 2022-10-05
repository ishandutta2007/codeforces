#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> e[110000];
int dis[110000],tot=0,dfn[110000],ff[110000][22];
void dfs(int i,int fa){
	dfn[i]=++tot;
	ff[i][0]=fa;
	for(int j=1;j<=20;j++)ff[i][j]=ff[ff[i][j-1]][j-1];
	for(int j : e[i]){
		if(j!=fa){
			dis[j]=dis[i]+1;
			dfs(j,i);
		}
	}
}
int lca(int u,int v){
	if(dis[u]<dis[v])swap(u,v);
	int o=dis[u]-dis[v];
	for(int i=0;i<=20;i++)if((o>>i)&1)u=ff[u][i];
	if(u==v)return u;
	for(int i=20;i>=0;i--)if(ff[u][i]!=ff[v][i])u=ff[u][i],v=ff[v][i];
	return ff[u][0];
} 
bool cmp(int u,int v){
    return dfn[u]<dfn[v]; 
}
vector<int> ch[110000];
int tot1,st[110000];
vector<int> ver;
void insert(int i){
	if(tot1==0){
		ver.push_back(i);
		st[++tot1]=i;
		return;
	}
	int j=lca(i,st[tot1]);
	while((tot1>1)&&(dis[j]<=dis[st[tot1-1]])){
		ch[st[tot1-1]].push_back(st[tot1]);
		tot1--;
	}
	if(st[tot1]==j){
		ver.push_back(i);
		st[++tot1]=i;
		return;
	}
	ch[j].push_back(st[tot1]);
	ver.push_back(j);
	st[tot1]=j;
	ver.push_back(i);
	st[++tot1]=i;
}
int u[110000];
int in[110000];
int dfs2(int i){
	int ans=0;
	for(int j : ch[i])ans+=dfs2(j);
	if(!in[i]){
		int cnt=0;
		for(int j : ch[i])cnt+=u[j];
		if(cnt>=2){
			u[i]=0;
			return ans+1;
		}
		u[i]=cnt;
		return ans;
	}
	u[i]=1;
	for(int j : ch[i])ans+=u[j];
	return ans;
}
int t[110000];
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,1);
	int q;
	cin>>q;
	while(q--){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)scanf("%d",&t[i]);
		sort(t+1,t+k+1,cmp);
		tot1=0;
		for(int i=1;i<=k;i++)in[t[i]]=1;
		for(int i=1;i<=k;i++)insert(t[i]);
		for(int i=1;i<tot1;i++)ch[st[i]].push_back(st[i+1]);
		bool r=0;
		for(int i=1;i<=k;i++)for(int j : ch[t[i]])if(in[j]&&dis[j]-dis[t[i]]==1)r=1;
		if(r){
			for(int i : ver)ch[i].clear();
			ver.clear();
		    for(int i=1;i<=k;i++)in[t[i]]=0;
			printf("-1\n");
			continue;
		}
		printf("%d\n",dfs2(st[1]));
		for(int i : ver)ch[i].clear();
		ver.clear();
		for(int i=1;i<=k;i++)in[t[i]]=0;
	}
	return 0;
}