#include<bits/stdc++.h>
using namespace std;

const int maxn=107;
int n,m;
int u[maxn],w[maxn];
struct edge{
	int a,b;
	friend bool operator< (edge u,edge v){
		return u.a+u.b>v.a+v.b;
	}
}edge[maxn];

bool solve_up(){
	bool vis[maxn];
	memset(vis,0,sizeof(vis));
	while (1){
		int j=-1;
		for (int i=1;i<=n;++i){
			if (!vis[i]&&w[i]>=0&&(j==-1||u[i]<u[j])){
				j=i;
			}
		}
		if (j==-1) return 1;
		if (m<u[j]) return 0;
		vis[j]=1;
		m+=w[j]; 
	}
}

bool solve_down(){
	int cnt=0;
	for (int i=1;i<=n;++i){
		if (w[i]<0){
			edge[cnt].a=u[i];
			edge[cnt++].b=w[i];
		}
	}
	sort(edge,edge+cnt);
	for (int i=0;i<cnt;++i){
		if (m<edge[i].a) return 0;
		m+=edge[i].b;
	}
	if (m>=0) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>u[i]>>w[i];
	}
	if (solve_up()&&solve_down()){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}