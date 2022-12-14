#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
#define max_n 100000
#define max_m 200000
bool vis[max_m+1];
int w[max_n+1];
pair<int,int>a[max_m+1];
queue<int>que;
vector<int>vec[max_n+1];
int ans[max_m+1];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",w+i);
	for(int i=1; i<=m; ++i){
		scanf("%d%d",&a[i].first,&a[i].second);
		--w[a[i].first],--w[a[i].second],vec[a[i].first].push_back(i),vec[a[i].second].push_back(i);
	}
	for(int i=1; i<=n; ++i)
		if(w[i]>=0)
			que.push(i);
	int cnt=m;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int v:vec[u]){
			if(vis[v])
				continue;
			vis[v]=1;
			ans[cnt]=v;
			--cnt;
			if(++w[a[v].first]==0)
				que.push(a[v].first);
			if(++w[a[v].second]==0)
				que.push(a[v].second);
		}
	}
	if(cnt)
		puts("DEAD");
	else{
		puts("ALIVE");
		for(int i=1; i<=m; ++i)
			printf("%d ",ans[i]);
	}
	return 0;
}