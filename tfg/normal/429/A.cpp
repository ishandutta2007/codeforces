#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

const int INF = 0x3f3f3f3f;
const int SIZE = 100005;

int cnt;
int op[SIZE];
bool vis[SIZE];
int state[SIZE];
int goal[SIZE];
vi g[SIZE];

void dfs(int pos, bool trocar, bool trocarFilho) {
	bool trocarNeto = trocar;
	vis[pos] = true;
	if(trocar) {
		state[pos] ^= 1;
	}
	if(state[pos] != goal[pos]) {
		trocarNeto = !trocar;
		state[pos] ^= 1;
		op[cnt++] = pos;
	}
	for(int a : g[pos]) {
		if(!vis[a]) {
			dfs(a, trocarFilho, trocarNeto);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", state + i);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", goal + i);
	}
	//for(int i = 1; i <= n; i++) {
	//	printf("%d %d\n", state[i], goal[i]);
	//}
	dfs(1, false, false);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++) {
		printf("%d\n", op[i]);
	}
}