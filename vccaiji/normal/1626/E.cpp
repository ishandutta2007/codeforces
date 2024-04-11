#include<bits/stdc++.h>
using namespace std;
int a[310000];
int ans[310000];
vector<int> e[310000];
int fa[310000];
vector<int> ch[310000];
int dfn[310000],sz[310000],s[310000],num[310000];
int tot=0;
void dfs1(int i,int f){
	fa[i]=f;
	dfn[i]=++tot;
	sz[i]=1;
	if(a[i])s[i]=i;
	if(a[i])num[i]=1;
	for(int j=0;j<e[i].size();j++){
		if(e[i][j]!=f){
			ch[i].push_back(e[i][j]);
			dfs1(e[i][j],i);
			sz[i]+=sz[e[i][j]];
			s[i]^=s[e[i][j]];
			num[i]+=num[e[i][j]];
		}
	}
}
bool upd(int i,int j,bool r,int u,int v){
	if(r){
		u--;
		v^=j;
	}
	if(u==0)return 0;
	if(u==1){
		if(ans[i]==0){
			ans[i]=v;
			return 1;
		}
		if(ans[i]==310000)return 0;
		if(ans[i]==v)return 0;
		ans[i]=310000;
		return 1;
	}
	if(ans[i]<310000){
		ans[i]=310000;
		return 1;
	}
	return 0;
}
void dfs2(int i){
	if(i>1){
		if(upd(fa[i],ans[i],ans[i]<310000&&dfn[i]<=dfn[ans[i]]&&dfn[ans[i]]<dfn[i]+sz[i],num[i],s[i]))dfs2(fa[i]);
	}
	for(int j=0;j<ch[i].size();j++){
		if(upd(ch[i][j],ans[i],ans[i]<310000&&(dfn[ans[i]]<dfn[ch[i][j]]||dfn[ans[i]]>=dfn[ch[i][j]]+sz[ch[i][j]]),num[1]-num[ch[i][j]],s[1]^s[ch[i][j]]))dfs2(ch[i][j]);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,1);
	for(int i=1;i<=n;i++)if(a[i]&&(ans[i]<310000)){
		ans[i]=310000;
		dfs2(i);
	}
	for(int i=1;i<=n;i++){
		if(ans[i])cout<<"1 ";
		else cout<<"0 ";
	}
	return 0;
}