#include<bits/stdc++.h>

const int N = 1010;

std::vector <int> vec[N];
bool flag;

void dfs(int u){
	int cnt = 0;
	for (auto v : vec[u]){
		cnt += vec[v].size() == 0;
		dfs(v);
	}
	if (vec[u].size() != 0 && cnt < 3){
		flag = false;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 2, x; i <= n; ++ i){
		scanf("%d", &x);
		vec[x].push_back(i);
	}
	flag = true;
	dfs(1);
	puts(flag ? "Yes" : "No");
	return 0;
}