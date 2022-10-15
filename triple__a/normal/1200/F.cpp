#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int maxm=2520;
const int maxn=1007;

int n;
int ans[maxn][maxm],k[maxn],m[maxn];
int vis[maxn][maxm];
vector<int> e[maxn];
pair<int,int> st[maxn*maxm];

void solve(int u,int w){
	queue<pair<int,int> > q;
	while(!q.empty()){
		q.pop();
	}
	int cnt=0;
	while (1){
		vis[u][w]=++cnt;
		st[cnt]=make_pair(u,w);
		w=((w+k[u])%maxm+maxm)%maxm;
		u=e[u][(w%m[u]+m[u])%m[u]];
		if (vis[u][w]){
			if (ans[u][w]){
				for (int i=1;i<=cnt;++i){
					pair<int,int> p=st[i];
					ans[p.first][p.second]=ans[u][w];
				}
			}
			else{
				set<int> s;
				s.clear();
				for (int i=vis[u][w];i<=cnt;++i){
					s.insert(st[i].first);
				}
				for (int i=1;i<=cnt;++i){
					pair<int,int> p=st[i];
					ans[p.first][p.second]=s.size();
				}
//				cout<<s.size()<<endl;
			}
			break;
		}
	}
}
int main(){
	memset(ans,0,sizeof(ans));
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>k[i];
	}
	for (int i=1;i<=n;++i){
		cin>>m[i];
		for (int j=1;j<=m[i];++j){
			int u;
			cin>>u;
			e[i].push_back(u);
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=0;j<maxm;++j){
			if (!ans[i][j]){
				solve(i,j);
			}
		}
	}

//	solve(4,2518);
	int q;
	cin>>q;
	while(q--){
		int u,w;
		cin>>u>>w;
		cout<<ans[u][(w%maxm+maxm)%maxm]<<endl;
	}
	return 0;
}