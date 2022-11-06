#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> in[1001];
int remain[1001];
int loc[1001][1001];
vector<pair<int, int>> ans;
vector<int> map[1001];
int v[1001];
bool dfs(int x, int p){
	v[x] = 1;
	for(int xx:map[x]){
		if(xx == p) continue;
		if(v[xx] != 0) return false;
		if(!dfs(xx, x)) return false;
	}
	v[x] = 2;
	return true;
}
bool dfs2(int x, int c, int p, int r){
	for(int xx: map[x]){
		if(xx == p) continue;
		if(loc[r][xx] != loc[r][c]) return false;
		if(!dfs2(xx, c, x, r)) return false;
	}
	return true;
}
bool chk(int x){
	for(int xx: map[x]){
		if(!dfs2(xx, xx, x, x)) return false;
	}
	return true;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int s = 0, t, u;
		for(; s<n-1; s+=t){
			if(s!=0)scanf("-");
			scanf("%d:", &t);
			in[i].push_back(0);
			remain[i]++;
			for(int j=1; j<=t; j++){
				if(j!=1) scanf(",");
				scanf("%d",&u);
				in[i].back()++;
				loc[i][u] = in[i].size()-1;
			}
		}
	}
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=n; j++) printf("%d ", loc[i][j]);
//		puts("");
//	}
	std::queue<int> Q;
	for(int i=2; i<=n; i++){
		if(remain[i] == 1) Q.push(i);
	}
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
//		dead[x] = 1;
		//		printf("^%d\n", x);
		int c = 0;
		for(int i=1; i<=n; i++) if(i!=x){
			int v = loc[i][x];
			if(--in[i][v] == 0){
				remain[i]--;
				ans.emplace_back(i, x);
				map[i].push_back(x);
				map[x].push_back(i);
				c++;
				if(remain[i] == 1 && i!=1){
					Q.push(i);
				}
			}
		}
		//if(c > 1){
		//	printf("-1\n");
		//	return 0;
		//}
	}
	//	printf("**%d\n", ans.size());
	if(ans.size() != n-1 || !dfs(1, -1)){
		printf("-1\n");
		return 0;
	}
	for(int i=1; i<=n; i++){
		if(v[i] != 2){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1; i<=n; i++){
		if(!chk(i)){
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", n-1);
	for(int i=0; i<n-1; i++){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}