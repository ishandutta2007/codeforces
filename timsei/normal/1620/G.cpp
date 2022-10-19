#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int mod = 998244353;

namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	int sub(int x) {return (x < 0) ? x + mod : x;}
	void Add(int &x, int y) {x = add(x + y);}
	void Sub(int &x, int y) {x = sub(x - y);}
}

int num[N][N], back[N][N], now[N], who[(1 << 23) + 1], tmp[N], n;

char s[N * 10000];

void dfs(int x, int mask, int sgn = -1) {
	if(x == n) {
		if(!mask) return;
		int ans = 1;
		for(int i = 0; i < 26; ++ i)
		ans = 1LL * ans * (now[i] + 1) % mod;
		who[mask] = ans * 1LL * (mod + sgn) % mod;
		return;
	}
	dfs(x + 1, mask, sgn);
	int tmp[N] = {0};
	for(int i = 0; i < 26; ++ i) tmp[i] = now[i];
	for(int i = 0; i < 26; ++ i) now[i] = min(now[i], num[x][i]);
	dfs(x + 1, mask | (1 << x), sgn * (-1));
	for(int i = 0; i < 26; ++ i) now[i] = tmp[i];
	return;
}

unsigned long long ans = 0;

void dfs2(int x, int mask, int cnt = 0, int sum = 0) {
	if(x == n) {
		if(!mask) return;
		(ans ^= (unsigned long long)1 * who[mask] * cnt * sum);
		return;
	}
	dfs2(x + 1, mask, cnt, sum);
	int tmp[N] = {0};
	dfs2(x + 1, mask | (1 << x), cnt + 1, sum + (x + 1));
	return;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < 26; ++ i) now[i] = 1e9;
	for(int i = 0; i < n; ++ i) {
		scanf("%s", s + 1);
		int l = strlen(s + 1);
		for(int j = 1; j <= l;  ++ j) ++ num[i][s[j] - 'a'];
	}
	dfs(0, 0);
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < (1 << n); ++ j) {
			if(!((j >> i) & 1)) 
			Add(who[j + (1 << i)], who[j]);
		}
	}
	dfs2(0, 0);
	cout << ans << endl;
}