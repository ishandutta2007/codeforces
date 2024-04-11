#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,vis[105],rt,dep[105];
vector<int> v[105],tmp;
int f[105][105],NMSL[105][105][105];
vector<pair<int,int> >v0[105];
vector<vector<int> >sb[105];

void dfs0(int x){
	tmp.push_back(x);vis[x]=1;
	for(auto i:v[x]){
		if(!vis[i])dfs0(i);
	}
}

void dfs(int x,int fa){
	vis[x]=1;
	if(fa){
		for(auto v0:sb[x]){
			for(auto i:v0){
				if(i==fa){
					for(auto j:v0){
						f[x][j]=f[j][x]=1;
					}
					goto aaa;
				}
			}
		}
		aaa:;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&f[x][i])dfs(i,x);
	}
}

void dfs1(int x){
	vis[x]=1;
	for(auto i:v[x]){
		if(!vis[i])dfs1(i);
	}
}

void dfs2(int x,int fa,int d){
	dep[x]=d;
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs2(i,x,d+1);
	}
}

bool chk(int x,vector<int> q){
	int i,j,k=0;
	rt=x;
	for(i=1;i<=n;i++){
		memset(f[i],0,sizeof(f[i]));
		vis[i]=0;
	}
	for(auto i:q){
		f[x][i]=f[i][x]=1;
	}
	dfs(x,0);
	for(i=1;i<=n;i++){
		vis[i]=0;
		v[i].clear();
	}
	for(i=1;i<=n;i++)for(j=i+1;j<=n;j++){
		if(f[i][j]){
			k+=f[i][j];
			v[i].push_back(j);
			v[j].push_back(i);
		}
	}
	if(k!=n-1)return 0;
	dfs1(x);
	for(i=1;i<=n;i++)if(!vis[i])return 0;
	for(i=1;i<=n;i++){
		dfs2(i,0,0);
		for(auto v0:sb[i]){
			k=-1;
			for(auto i:v0){
				if(k==-1)k=dep[i];
				else if(k!=dep[i]){
					return 0;
				}
			}
		}
	}
	return 1;
}

void show(){
	cout<<"Yes\n";
	for(i=1;i<=n;i++)for(auto j:v[i])if(j>i)cout<<i<<' '<<j<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			v0[i].clear();
			sb[i].clear();
			memset(f[i],0,sizeof(f[i]));
			for(j=1;j<=n;j++){
				for(k=1;k<=n;k++)NMSL[i][j][k]=0;
			}
		}
		if(n==2){
			string s;cin>>s;
			if(s=="00"){
				cout<<"Yes\n1 2\n";continue;
			}
			else{
				cout<<"No\n";continue;
			}
		}
		for(i=1;i<n;i++){
			for(j=1;j+i<=n;j++){
				string s;
				cin>>s;s="X"+s;
				for(k=1;k<=n;k++){
					if(s[k]=='1'){
						v0[k].push_back({i,i+j});
						NMSL[i][i+j][k]=s[k]-'0';
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				vis[j]=0;v[j].clear();
			}
			for(auto [x,y]:v0[i]){
				if(x==i||y==i){
					cout<<"No\n";goto aaa;
				}
				v[x].push_back(y);v[y].push_back(x);
			}
			for(j=1;j<=n;j++){
				if(vis[j]||v[j].empty())continue;
				tmp.clear();
				dfs0(j);
				sb[i].push_back(tmp);
			}
		}
		for(i=1;i<=n;i++){
			for(auto v0:sb[i]){
				for(auto j:v0)for(auto k:v0){
					if(j<k&&NMSL[j][k][i]==0){
						cout<<"No\n";goto aaa;
					}
				}
			}
		}
		for(i=1;i<=n;i++)v[i].clear();
		for(i=1;i<=n;i++){
			for(auto v0:sb[i]){
				if(chk(i,v0)){
					show();
					goto aaa;
				}
			}
		}
		cout<<"No\n";
		aaa:;
	}
}