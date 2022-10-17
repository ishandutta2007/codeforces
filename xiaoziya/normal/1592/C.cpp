#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=100005;
int T,n,m,all;
int a[maxn],w[maxn];
vector<int>v[maxn];
void dfs1(int x,int last) {
	w[x]=a[x];
	for(int i=0; i<v[x].size(); i++) {
		int y=v[x][i];
		if(y==last)
			continue;
		dfs1(y,x),w[x]^=w[y];
	}
}
int dfs2(int x,int last) {
	int res=0;
	for(int i=0; i<v[x].size(); i++) {
		int y=v[x][i];
		if(y==last)
			continue;
		int r=dfs2(y,x);
		res+=r;
		if(r==1&&w[x]==0)
			return res+1;
	}
	if(w[x]==all&&x!=1)
		return res+1;
	return res;
}
int main() {
	scanf("%d",&T);
	while(T--) {
		all=0;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			v[i].clear();
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]),all^=a[i];
		for(int i=1,x,y; i<n; i++)
			scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
		if(all==0) {
			puts("YES");
			continue;
		}
		if(m==2) {
			puts("NO");
			continue;
		}
		dfs1(1,0);
		if(dfs2(1,0)<2)
			puts("NO");
		else puts("YES");
	}
	return 0;
}