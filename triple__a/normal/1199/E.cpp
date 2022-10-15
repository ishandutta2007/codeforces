#include<bits/stdc++.h>
using namespace std;

const int maxn=300007;
int n,m;

vector<pair<int,int> > e[maxn];
bool vis[maxn];
int ans[maxn];

int ck(int u){
	if (vis[u]) return -1;
	for (int i=0;i<e[u].size();++i){
		if (!vis[e[u][i].first]){
			vis[e[u][i].first]=1;
			return e[u][i].second;
		}
	}
	return -1;
}
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=3*n;++i){
			e[i].clear();
			vis[i]=0;
		} 
		int cnt=0;
		for (int i=1;i<=m;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(make_pair(v,i));
		}
		for (int i=1;i<=3*n;++i){
			int idx=ck(i);
			if (idx!=-1){
				vis[i]=1;
				ans[++cnt]=idx;
			}
		}
		if (cnt>=n){
			printf("Matching\n");
			for (int i=1;i<=n;++i){
				printf("%d ",ans[i]);
			}
			printf("\n");
		}
		else{
			printf("IndSet\n");
			int cnt=0;
			for (int i=1;i<=3*n;++i){
				if (cnt>=n) break;
				if (!vis[i]){
					printf("%d ",i);
					cnt++;
				}
			}
			printf("\n");
		}
	}
	return 0;
}