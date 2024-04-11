#include <bits/stdc++.h>

const int mask = (1 << 22)-1;
const int N = 1 << 22;
int n, m;
std::vector<int> idn;
std::vector<bool> visited[2];

void dfs(int v, int type){
	if(type == 0) visited[0][idn[v]] = true;
	else visited[1][v] = true;
	if(type == 0) dfs(v, 1);
	else{
		for(int j = 0; j < 22; ++j){
			if((v & (1 << j)) != 0) continue;
			int ch = (v | (1 << j));
			if(visited[1][ch]) continue;
			dfs(ch, 1);
		}
		if(idn[(~v)&mask] != -1 && !visited[0][idn[(~v)&mask]]){
			dfs((~v)&mask, 0);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	idn.resize(N, -1);
	std::vector<int> A;
	for(int i = 0; i < m; ++i){
		int a;
		std::cin >> a;
		A.push_back(a);
		idn[a] = i;
	}	
	visited[0].resize(m, false);
	visited[1].resize(N, false);
	int count = 0;	
	for(auto i : A){
		if(visited[0][idn[i]]) continue;
		count++;
		dfs(i, 0);
	}
	std::cout << count << "\n";
	return 0;
}