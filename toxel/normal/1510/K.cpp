#include <bits/stdc++.h>

std::map< std::vector<int>,int > vis;

int cnt;
int n;

void dfs(std::vector<int> now,int step) {
	bool flag = true;
	for (int i = 1; i <= 2 * n; i++) {
		if (now[i-1] != i) {
			flag = false;
			//break;
		}
	}

	if (flag) {
		if (cnt == -1) cnt = step;
		else cnt = std::min(cnt,step);
		return ;
	}

	std::vector<int> nxt1,nxt2;
	vis[now] = 1;

	for (int i = n; i < 2 * n; i++) nxt1.push_back(now[i]);
	for (int i = 0; i < n; i++) nxt1.push_back(now[i]);

	for (int i = 0; i < 2 * n; i+=2) {
		nxt2.push_back(now[i + 1]);
		nxt2.push_back(now[i]);
	}

	if (!vis[nxt1]) {
		vis[nxt1] = 1;
		dfs(nxt1,step+1);
		vis[nxt1] = 0;
	}

	if (!vis[nxt2]) {
		vis[nxt2] = 1;
		dfs(nxt2,step+1);
		vis[nxt2] = 0;
	}
}

int main() {
	int a;
	cnt = -1;
	std::vector<int> init;
	scanf("%d",&n);
	for (int i = 1; i <= 2 * n; i++) {
		scanf("%d",&a);
		init.push_back(a);
	}
	dfs(init,0);
	printf("%d\n",cnt);
	return 0;
}