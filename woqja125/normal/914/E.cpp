#include<cstdio>
#include<vector>
using namespace std;
vector<int> map[200001];
int n;
long long ans[200001];
int color[200001];
int v[200001];
int cnta[1 << 20];
int cntb[1 << 20];
int sz[200001];

void getSZ(int x, int p = -1) {
	sz[x] = 1;
	for (auto xx : map[x]) {
		if (xx == p || v[xx]) continue;
		getSZ(xx, x);
		sz[x] += sz[xx];
	}
}

int getCenter(int x) {
	getSZ(x);
	int T = sz[x], p = -1, fg = 0;
	while (true) {
		fg = 1;
		for (auto xx : map[x]) {
			if (xx == p || v[xx]) continue;
			if (sz[xx] > T / 2) {
				p = x;
				x = xx;
				fg = 0;
				break;
			}
		}
		if (fg) return x;
	}
}

void getC(int x, int b, int p = -1) {
	cnta[b]++;
	for (auto xx : map[x]) {
		if (xx == p || v[xx]) continue;
		getC(xx, b ^ color[xx], x);
	}
}

void remC(int x, int b, int p = -1) {
	cnta[b] = 0;
	for (auto xx : map[x]) {
		if (xx == p || v[xx]) continue;
		remC(xx, b ^ color[xx], x);
	}
}

void getC2(int x, int b, int p) {
	cntb[b]++;
	for (auto xx : map[x]) {
		if (xx == p || v[xx]) continue;
		getC2(xx, b ^ color[xx], x);
	}
}

void remC2(int x, int b, int p) {
	cntb[b] = 0;
	for (auto xx : map[x]) {
		if (xx == p || v[xx]) continue;
		remC2(xx, b ^ color[xx], x);
	}
}

long long addAns(int rb, int x, int b, int p) {
	int ansb = 0;
	long long S = 0;
	for (int i = 0; i < 21; i++) {
		if (i == 20) ansb = 0;
		else ansb = 1 << i;
		ansb ^= b ^ rb;
		S += cnta[ansb] - cntb[ansb];
	}
	for (auto xx : map[x]) {
		if (xx == p || v[xx]) continue;
		S += addAns(rb, xx, b ^ color[xx], x);
	}
	ans[x] += S;
	return S;
}

void solve(int x) {
	x = getCenter(x);
	
	getC(x, 0);
	long long S = 0;
	for (auto xx : map[x]) {
		if (v[xx] != 0) continue;
		getC2(xx, color[xx], x);
		S += addAns(color[x], xx, color[xx], x);
		remC2(xx, color[xx], x);
	}
	int ansb = 0;
	cntb[0] = 1;
	for (int i = 0; i < 21; i++) {
		if (i == 20) ansb = 0;
		else ansb = 1 << i;
		ansb ^= color[x];
		S += cnta[ansb] - cntb[ansb];
	}
	cntb[0] = 0;
	ans[x] += S / 2;

	v[x] = 1;
	remC(x, 0);
	for (auto xx : map[x]) {
		if (v[xx] == 0) solve(xx);
	}
}

char cs[200010];
int main() {
	scanf("%d", &n);
	int a, b;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	scanf("%s", cs);
	for (int i = 1; i <= n; i++) color[i] = (1 << (cs[i - 1] - 'a'));
	solve(1);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i] + 1);
	return 0;
}