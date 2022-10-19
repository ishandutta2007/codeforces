#include <bits/stdc++.h>
using namespace std;

const int N = 4e6 + 5;

int ch[N][26], n, m, x, y, dep[N], MxDep, cnt, tot;

char c;

vector <int> D[333333];

void dfs(int x) {
	D[dep[x]].push_back(x);
	MxDep = max(MxDep, dep[x]);
	for(int i = 0; i < 26; ++ i) 
	if(ch[x][i]) dep[ch[x][i]] = dep[x] + 1, dfs(ch[x][i]);
}

int newnode() {
	++ tot;
	memset(ch[tot], 0, sizeof(ch[tot]));
	return tot;
}

int merge(int x, int y) {
	if(!x || !y) return x + y;
	++ cnt;
	int who = newnode();
	for(int i = 0; i < 26; ++ i) {
		ch[who][i] = merge(ch[x][i], ch[y][i]);
	}
	return who;
}

int solve(int x) {
	cnt = 0;
	for(int i = 0; i < (int) D[x].size(); ++ i) {
		int V = D[x][i];
		tot = n;
		int now = 0;
		for(int j = 0; j < 26; ++ j) {
			if(ch[V][j]) {
				now = merge(ch[V][j], now);
			}
		}
		if(now) ++ cnt;
	}
	return cnt;
}

bool f[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++ i) {
		scanf("%d%d", &x, &y);
		c = ' ';
		while(c < 'a' || c > 'z') c = getchar();
		ch[x][c - 'a'] = y;	
		f[y] = 1;
	}
	int t = 0;
	for(int i = 1; i <= n; ++ i) if(!f[i]) t = i;
	dep[t] = 1;
	dfs(t);
	int ans = 0;
	int Min = 0;
	for(int i = 1; i <= MxDep; ++ i) {
		int it = solve(i);
		if(it > ans) ans = it, Min = i;
	}
	cout << n - ans << endl;
	cout << Min << endl;
}