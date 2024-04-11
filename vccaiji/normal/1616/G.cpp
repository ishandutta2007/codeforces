#include<bits/stdc++.h> 
using namespace std;
int n,m;
vector<int> lc[210000],rc[210000];
int has[210000];
int l[210000];
int vis[210000][2];
int vis2[210000][2];
void dfs(int i,int o){
	if(vis[i][o])return;
	vis[i][o]=1;
	for(int j : lc[i+1]){
		if(j<i&&l[j+1]==l[i])dfs(j,o^1);
	}
}
void dfs2(int i,int o){
	if(vis2[i][o])return;
	vis2[i][o]=1;
	for(int j : rc[i]){
		if(j>i+1&&l[j-1]==l[i+1])dfs2(j-1,o^1);
	}
}
int main(){
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(int i=0;i<=n;i++){
			has[i]=0;
			lc[i].clear();
			rc[i].clear();
		}
		for(int i=0;i<=n+1;i++)for(int j=0;j<2;j++)vis[i][j]=vis2[i][j]=0;
		has[0]=has[n]=1;
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			rc[u].push_back(v);
			lc[v].push_back(u);
			if(v==u+1)has[u]=1;
		}
		for(int i=1;i<=n+1;i++){
			rc[0].push_back(i);
			lc[i].push_back(0);
		}
		for(int i=1;i<=n;i++){
			lc[n+1].push_back(i);
			rc[i].push_back(n+1);
		}
		bool r=1;
		int t;
		for(int i=1;i<n;i++)if(!has[i]){
			t=i;
			r=0;
		}
		if(r){
			cout<<1ll*n*(n-1)/2<<"\n";
			continue;
		}
		l[0]=0;
		for(int i=1;i<=n+1;i++){
			if(has[i-1])l[i]=l[i-1];
			else l[i]=i;
		}
		dfs(t,0);
		dfs2(t,0);
		int s,s1;
		for(int i=0;;i++){
			if(!has[i]){
				s=i;
				break;
			}
		}
		for(int i=n;;i--){
			if(!has[i]){
				s1=i;
				break;
			}
		}
		int c1=0,c2=0;
		for(int i=0;i<=s;i++){
			if(vis[i][0])c1++;
		}
		for(int i=n;i>=s1;i--){
			if(vis2[i][0])c2++;
		}
		long long ans=1ll*c1*c2;
		c1=c2=0;
		for(int i=0;i<=s;i++){
			if(vis[i][1])c1++;
		}
		for(int i=n;i>=s1;i--){
			if(vis2[i][1])c2++;
		}
		ans+=1ll*c1*c2;
		c1=c2=0;
		for(int i=0;i<=s;i++){
			if(vis[i][1]&&vis[i][0])c1++;
		}
		for(int i=n;i>=s1;i--){
			if(vis2[i][1]&&vis2[i][0])c2++;
		}
		ans-=1ll*c1*c2;
		if(s1==s)ans--;
		cout<<ans<<endl;
	}
	return 0;
}