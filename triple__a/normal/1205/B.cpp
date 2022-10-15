#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
const int INF=1e9;
int n,cnt=0,en=0;
long long a[maxn];
int vis[maxn],dist[127][127];
int ex[maxn],ey[maxn];

int floyd(int u,int v){
	int d[127][127];
	for (int i=0;i<127;++i){
		for (int j=0;j<127;++j){
			d[i][j]=dist[i][j];
		}
	}
	for (int k=1;k<=cnt;++k){
		for (int i=1;i<=cnt;++i){
			for (int j=1;j<=cnt;++j){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	return d[u][v];
}
void add_edge(int u,int v){
	if (!vis[u]){
		vis[u]=++cnt;
	}	
	if (!vis[v]){
		vis[v]=++cnt;
	}
	dist[vis[u]][vis[v]]=dist[vis[v]][vis[u]]=1;
	ex[++en]=vis[u],ey[en]=vis[v];
}

void decomp(){
	while (1){
		bool ck=false;
		vector<int> tmp;
		tmp.clear();
		for (int i=1;i<=n;++i){
			if (a[i]) ck=true;
			if (a[i]&1) tmp.push_back(i);
			a[i]>>=1;
		}
		if (tmp.size()>2){
			cout<<3<<endl;
			exit(0);
		}
		if (tmp.size()==2){
			add_edge(tmp[0],tmp[1]);
		}
		if (!ck) break;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	for (int i=1;i<127;++i){
		for (int j=1;j<127;++j){
			if (i!=j){
				dist[i][j]=INF;
			}
		}
	}
	decomp();
/*	for (int i=1;i<=cnt;++i){
		for (int j=1;j<=cnt;++j){
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	int ans=INF;
	for (int i=1;i<=en;++i){
		dist[ex[i]][ey[i]]=dist[ey[i]][ex[i]]=INF;
//		cout<<ex[i]<<" "<<ey[i]<<endl;
		ans=min(ans,floyd(ex[i],ey[i]));
		dist[ex[i]][ey[i]]=dist[ey[i]][ex[i]]=1;
	}
	if (ans>=INF){
		cout<<-1;
		return 0; 
	}
	cout<<ans+1<<endl;
	return 0;
}