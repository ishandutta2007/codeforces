#include<stdio.h>
#include<vector>
int v[200010];
std::vector<int> map[200010];
struct ans{
	int x, y, z;
	ans(int X, int Y, int Z):x(X), y(Y), z(Z){}
};
std::vector<ans> A;

bool dfs(int x, int p){
	v[x] = 1;
	std::vector<int> t;
	for(auto &xx: map[x]){
		if(xx == p) continue;
		if(v[xx] == 2) continue;
		if(v[xx] == 1) t.push_back(xx);
		else if(dfs(xx, x)) t.push_back(xx);
	}
	for(int i=0; i+1<t.size(); i+=2){
		A.emplace_back(t[i], x, t[i+1]);
	}
	v[x] = 2;
	if(t.size()%2 == 0) return true;
	if(p!=-1) A.emplace_back(t.back(), x, p);
	return false;
}

int main(){
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d%d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for(int i=1; i<=n; i++){
		if(v[i] == 0) dfs(i, -1);
	}
	printf("%d\n", A.size());
	for(auto &t: A) printf("%d %d %d\n", t.x, t.y, t.z);
	return 0;
}