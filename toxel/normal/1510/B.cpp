#include <bits/stdc++.h>

using namespace std;

const int maxn = 2050;

int d,n;
int a[maxn];
vector<int> G[maxn];
bool used[maxn],hd[maxn];
int match[maxn];
stack<int> st;

bool dfs(int u) {
	used[u] = 1;
	for (int v: G[u]) {
		int w = match[v];
		if (w==0 || (used[w]==0  && dfs(w))) {
			match[u] = v;
			match[v] = u;
			return true;
		}
	}
	return false;
}

bool cmp(int x,int y) {
	return __builtin_popcount(x) > __builtin_popcount(y);
}

void init() {
	char str[20];
	scanf("%d%d",&d,&n);
	for (int i = 1; i <= n; i++) {
		scanf("%s",str);
		for (int j = 0; j < d; j++) a[i] = a[i]  * 2 + str[j] - '0';
	}
	sort(a + 1, a + n + 1,cmp);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i] > a[j] && (a[i]&a[j]) == a[j]) {
				G[i+n].push_back(j);
				G[j].push_back(i+n);
			}

	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (!match[i]) {
			std::fill(used,used+n+1,0);
			if (!dfs(i) || i == 1) {
				hd[i] = 1;
				ans += __builtin_popcount(a[i]) + 1;
			}
		}
	}

	printf("%d\n",ans);
	for (int i = 1 ; i <= n; i++) {
		if (!hd[i]) continue;
		int u = i, v;
		st.push(-1);
		while (u) {
			v = match[u + n];
			if (v > n) v -= n;
				for (int j = 0; j < d; j++) {
					if ((a[u]>>j&1) != (a[v]>>j&1)) st.push(d-1-j);
				}
			u = v;
		}
	}

	while (st.size() > 1) {
		if (st.top() == -1) printf("R ");
		else printf("%d ",st.top());
		st.pop();
	}
	printf("\n");
}

int main() {
	init();
	return 0;
}