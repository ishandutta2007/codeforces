#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

const int ms = 1001000;

char str[ms][5];
int usual[ms];
int dp[ms][2];
int par[ms];

std::vector<int> edges[ms];

int dfs(int on, int p = -1) {
	par[on] = p;
	if(str[on][0] == 'I') {
		return usual[on];
	} else if(str[on][0] == 'A') {
		return usual[on] = dfs(edges[on][0], on) & dfs(edges[on][1], on);
	} else if(str[on][0] == 'O') {
		return usual[on] = dfs(edges[on][0], on) | dfs(edges[on][1], on);
	} else if(str[on][0] == 'X') {
		return usual[on] = dfs(edges[on][0], on) ^ dfs(edges[on][1], on);
	} else {
		return usual[on] = dfs(edges[on][0], on) ^ 1;
	}
}

int rise(int on, int v) {
	if(on == 0) return v;
	int &ans = dp[on][v];
	if(ans != -1) return ans;
	char t = str[par[on]][0];
	if(t == 'A') {
		int other = edges[par[on]][0] != on ? edges[par[on]][0] : edges[par[on]][1];
		ans = rise(par[on], usual[other] & v);
	} else if(t == 'O') {
		int other = edges[par[on]][0] != on ? edges[par[on]][0] : edges[par[on]][1];
		ans = rise(par[on], usual[other] | v);
	} else if(t == 'X') {
		int other = edges[par[on]][0] != on ? edges[par[on]][0] : edges[par[on]][1];
		ans = rise(par[on], usual[other] ^ v);
	} else {
		ans = rise(par[on], v ^ 1);
	}
	return ans;
}

int main() {
	memset(dp, -1, sizeof dp);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		scanf(" %s", str[i]);
		if(str[i][0] == 'I') {
			scanf("%d", &usual[i]);
		} else if(str[i][0] == 'N') {
			int u;
			scanf("%d", &u);
			u--;
			edges[i].push_back(u);
		} else {
			int u, v;
			scanf("%d %d", &u, &v);
			u--;v--;
			edges[i].push_back(u);
			edges[i].push_back(v);
		}
	}
	dfs(0);
	for(int i = 0; i < n; i++) {
		if(str[i][0] == 'I') {
			printf("%c", rise(i, usual[i] ^ 1) == 1 ? '1' : '0');
		}
	}
	printf("\n");
}