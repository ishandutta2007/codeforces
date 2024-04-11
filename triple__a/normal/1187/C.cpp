#include<bits/stdc++.h>
using namespace std;

const int maxn=1007;

int n,m;

bool vis[maxn];

vector<pair<int,int> >q;
int main(){
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if (u){
			for (int i=v;i<w;++i){
				vis[i]=1;
			}
		}
		else{
			q.push_back(make_pair(v,w));
		}
	}
	for (int i=0;i<q.size();++i){
			bool fg=0;
			for (int j=q[i].first;j<q[i].second;++j){
				if (!vis[j]){
					fg=1;
				}
			}
			if (!fg){
				printf("NO");
				return 0;
			}
	}
	printf("YES\n");
	int u=1e8;
	printf("%d ",u);
	for (int i=2;i<=n;++i){
		if (vis[i-1]){
			u++;
		}
		else{
			u--;
		}
		printf("%d ",u);
	}
	printf("\n");
	return 0;
}