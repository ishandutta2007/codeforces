#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 100'007;

int n;
bool used[N];
vector <int> G[N], T[N];

void clear() {
	for(int i = 1; i <= n; ++i) {
		used[i] = false;
		G[i].clear();
		T[i].clear();
	}
}

void read() {
	int m;
	scanf("%d %d", &n, &m);

	if(n == 0)	exit(0);
	clear();
	
	for(int i = 1; i <= m; ++i) {
		int len;
		scanf("%d", &len);

		int cur;
		scanf("%d", &cur);
		len--;

		while(len--) {
			int nxt;
			scanf("%d", &nxt);
			
			G[cur].push_back(nxt);
			G[nxt].push_back(cur);
			cur = nxt;
		}
	}
}

namespace getForest {
	int Time;
	int pre[N];
	int low[N];
	
	void clear() {
		for(int i = 1; i <= n; ++i)
			low[i] = pre[i] = 0;
		Time = 0;
	}

	void go(int u, int p) {
		pre[u] = low[u] = ++Time;
		for(auto v: G[u])
			if(!pre[v]) {
				go(v, u);
				low[u] = min(low[u], low[v]);
			} else if(v != p) {
				low[u] = min(low[u], pre[v]);
			}
		
		if(low[u] == pre[u] and u != p) {
//			printf("%d -> %d\n", u, p);
			T[u].push_back(p);
			T[p].push_back(u);
		}
	}

	void solve() {
		clear();
		go(1, 1);
	}
}

namespace getMaxCactus {
	vector <PII> ans;
	vector <int> sons[N];

	int mem[N][2];
	int dp[N][3];
	vector <vector <vector <int> > > prv[N];	
	
	void updateDP(int id, int u, vector <vector <int> > &dp_me, int *dp_son, bool root) {
		vector <vector <int> > nxt (2, vector <int> (4, N));
				
		for(int m = 0; m < 2; ++m)
			for(int s = 0; s < 4; ++s) {
				int p_me = 4 * m + s;
				auto updateCell = [&](int r, int c, int val, int p_son) {
					if(val < nxt[r][c]) {
						nxt[r][c] = val;
						prv[u][id][r][c] = p_me * 3 + p_son;
					}
				};
				
				if(s < 3)
					updateCell(m, s == 0 ? 1 : 3, dp_me[m][s] + dp_son[0], 0);
				updateCell(m ^ 1, s, dp_me[m][s] + (m ^ 1) + dp_son[0], 0);
				
				if(s <= 1 and !root)	updateCell(m, s + 2, dp_me[m][s] + dp_son[1], 1);
				updateCell(m, s, dp_me[m][s] + 1 + dp_son[1], 1);
				updateCell(m ^ 1, s, dp_me[m][s] + (m ^ 1) + dp_son[1], 1);

				if(s <= 1 and !root)	updateCell(m, s + 2, dp_me[m][s] + dp_son[2], 2);
				updateCell(m, s, dp_me[m][s] + 1 + dp_son[2], 2);
				updateCell(m ^ 1, s, dp_me[m][s] + (m ^ 1) + dp_son[2], 2);
			}
		
		dp_me = nxt;
	}
	
	void calcDP(int u, int p) {
		used[u] = true;

		sons[u].clear();
		prv[u].clear();

		for(auto v: T[u]) {
			if(v == p)
				continue;

			calcDP(v, u);
			sons[u].push_back(v);
		}
		
		vector <vector <int> > tmp (2, vector <int> (4, N));
		tmp[0][0] = 0;

		prv[u].resize(sons[u].size());
		for(auto &vec: prv[u])
			vec.resize(2, vector <int> (4, -1));
		
		int id = 0;
		for(auto v: sons[u]) {
			updateDP(id, u, tmp, dp[v], u == p);
			id++;
		}
		
		dp[u][0] = tmp[0][0];
		dp[u][1] = min(tmp[0][1], tmp[0][2]);
		dp[u][2] = tmp[0][3];
		
		mem[u][0] = tmp[0][1];
		mem[u][1] = tmp[0][2];
//		printf("DP %d :: 0 : %d; 1 : %d; 2 : %d\n", u, dp[u][0], dp[u][1], dp[u][2]);
	}
	
	int restore(int u, int type) {
		int mt = 0;
		if(type == 2) type = 3;
		else if(type == 1) {
			if(mem[u][0] > mem[u][1])
				type = 2;
		}
		
		int m = sons[u].size();
		int matched = -1;
		
		int result = -1;
		for(int i = m - 1; i >= 0; --i) {
			int new_mt = prv[u][i][mt][type] / 12;
			int new_type = prv[u][i][mt][type] / 3 % 4;
			int son_result = restore(sons[u][i], prv[u][i][mt][type] % 3);

			bool was_matched = false;
			
			if(new_mt != mt) {
				was_matched = true;
			} else {
				was_matched |= new_type == type;
			}
			
			if(was_matched) {
				if(new_mt == mt)
					ans.push_back({son_result, u});
				else if(matched == -1)
					matched = son_result;
				else {
					ans.push_back({matched, son_result});
					matched = -1;
				}
			} else {
				if(prv[u][i][mt][type] % 3 == 0) {
					if(result == -1)
						result = son_result;
				} else {
					result = son_result;
				}
			}
			
//			printf("%d :: %d %d\n", u, new_mt, new_type);
			mt = new_mt;
			type = new_type;
		}
		
		if(result == -1)
			result = u;
		return result;
	}
	
	vector <PII> solve(int root) {
		calcDP(root, root);
		ans.clear();
		
		if(dp[root][0] < dp[root][1])
			restore(root, 0);
		else
			restore(root, 1);
		return ans;
	}
}

void solve() {
	read();
	getForest::solve();
	
	vector <PII> ans;
	for(int i = 1; i <= n; ++i) {
		if(used[i])
			continue;
		
		auto push_ans = getMaxCactus::solve(i);
		for(auto &v: push_ans)
			ans.push_back(v);
	}
	
	printf("%d\n", (int)ans.size());
	for(auto &[x, y]: ans)
		printf("%d %d\n", x, y);
}

int main() {
	while(true)
		solve();
	return 0;
}