#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> e[1100000];
vector<int> ch[1100000];
bool vis[1100000];
int tot=0;
int dfn[1100000];
int sz[1100000];
int color[1100000];
int xz,zx;
int cnt[1100000],cnt2[1100000];
void dfs(int x){
	dfn[x]=++tot;
	vis[x]=1;
	sz[x]=1;
	for(int y : e[x]){
		if(vis[y]){
			if(dfn[y]>dfn[x]){
				if(color[y]==color[x]){
					zx=color[x];
					xz++;
					cnt2[x]--;
					cnt2[y]++;
				}
				else{
					cnt[x]--;
					cnt[y]++;
				}
			}
		}
		else{
			ch[x].push_back(y);
			color[y]=(color[x]^1);
			dfs(y);
			sz[x]+=sz[y];
		}
	}
}
bool rr;
void calcnt(int x){
	for(int y : ch[x]){
		calcnt(y);
		if(rr)return;
		cnt[x]+=cnt[y];
		cnt2[x]+=cnt2[y];
	}
	if(x>1&&xz==cnt2[x]&&cnt[x]==0){
		rr=1;
		printf("YES\n");
		for(int i=1;i<=n;i++){
			if(dfn[i]>=dfn[x]&&dfn[i]<dfn[x]+sz[x])printf((color[i]^color[x]) ? "0" : "1");
			else printf((color[i]^color[x]) ? "1" : "0");
		}
		printf("\n");
	}
}
int main(){
	int _;
	cin>>_;
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++)ch[i].clear();
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		tot=0;
		xz=0;
		zx=0;
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt2[i]=0;
		dfs(1);
		if(xz==0){
			printf("YES\n");
			for(int i=1;i<=n;i++)printf(color[i] ? "0" : "1");
			printf("\n");
			continue;
		}
		if(xz==1){
			printf("YES\n");
			for(int i=1;i<=n;i++)printf(color[i]==zx ? "1" : "0");
			printf("\n");
			continue;
		}
		rr=0;
		calcnt(1);
		if(!rr)printf("NO\n");
	}
	return 0;
}