#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, m, A[N], B[N], cnt[N], now[N], x, y;

vector <int> ban[N], All[N];

int calc(int x) {
	return x * x;
}

vector <int> who;

int g(int x) {
	return lower_bound(who.begin(), who.end(), x) - who.begin() + 1;
}

int Id(int x) {
	return who[x - 1]; 
}

void rmain() {
	long long ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i) ban[i].clear(), cnt[i] = 0; who.clear();
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), who.push_back(A[i]);
	sort(who.begin(), who.end());
	who.erase(unique(who.begin(), who.end()), who.end());
	for(int i = 1; i <= n; ++ i) ++ cnt[g(A[i])];
	const int MAX = (int)sqrt(n);
	for(int i = 1; i <= MAX; ++ i) All[i].clear();
	for(int i = 1; i <= m; ++ i) {
		scanf("%d%d", &x, &y);
		ban[g(x)].push_back(g(y));
		ban[g(y)].push_back(g(x));
	}
	
	
	for(int i = who.size(); i >= 1; -- i) {
		if(cnt[i] <= MAX) All[cnt[i]].push_back(i);
		ban[i].push_back(i);
	} 
	for(int i = 1; i <= who.size(); ++ i) sort(ban[i].begin(), ban[i].end());
	
	for(int i = 1; i <= who.size(); ++ i) {
		if(cnt[i] > MAX) {
			int it = 0;
			for(int j = 1; j <= who.size(); ++ j) {
				if(it != ban[i].size() && ban[i][it] == j) {
					++ it; continue;
				}
				ans = max(ans, (Id(i) + Id(j)) * 1ll * (cnt[i] + cnt[j]));
			}
			continue;
		} else {
			for(int j = 1; j <= MAX; ++ j) {
				now[j] = 0;
			}
			for(int j = ban[i].size() - 1; j >= 0; -- j) {
				int x = ban[i][j];
				if(cnt[x] > MAX) continue;
				if(now[cnt[x]] != All[cnt[x]].size() && All[cnt[x]][now[cnt[x]]] == x) {
					++ now[cnt[x]];
				}
			}
			for(int j = 1; j <= MAX; ++ j) {
				if(now[j] == All[j].size()) continue;
				ans = max(ans, 1LL * (cnt[i] + j) * (Id(i) + Id(All[j][now[j]])));
			}
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}