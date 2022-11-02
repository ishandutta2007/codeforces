#include <bits/stdc++.h>

typedef long long ll;

const int N = 600;

int P;
int norm(int x) {if (x >= P) x -= P; return x;}
int reduce(int x) {if (x < 0) x += P; return x;}
void add(int &x, int y) {if ((x += y) >= P) x -= P;}
void sub(int &x, int y) {if ((x -= y) < 0) x += P;}
int mpow(int b, int p) {
	int r = 1;
	for (; p; p >>= 1, b = (ll)b * b % P)
		if (p & 1) r = (ll)r * b % P;
	return r;
}

int a[N + 5][N + 5], k;

int det() {
//	for (int i = 0; i < k; i++) for (int j = 0; j < k; j++)
//		printf("%d%c", a[i][j], j + 1 == k ? '\n' : ' ');

	int f = 0;
	for (int i = 0; i < k; i++) {
		if (!a[i][i]) {
			for (int j = i + 1; j < k; j++) if (a[j][i]) {
				for (int p = i; p < k; p++) std::swap(a[i][p], a[j][p]);
				break;
			}
			f ^= 1;
		}
		if (!a[i][i]) return 0;
		
		int iv = mpow(a[i][i], P - 2);
		for (int j = i + 1; j < k; j++) {
			int coef = (ll)iv * a[j][i] % P;
			for (int p = i; p < k; p++) sub(a[j][p], (ll)coef * a[i][p] % P);
		}
	}
	
	int ans = 1;
	for (int i = 0; i < k; i++)
		ans = (ll)ans * a[i][i] % P;
	if (f) ans = reduce(0 - ans);
	return ans;
}

std::vector<int>G[N + 5];

int f[N + 5][N + 5], ind[N + 5], oud[N + 5], n, m;

int s[N + 5], t[N + 5];
int main() {
	scanf("%d%d%d", &n, &m, &P);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		ind[v]++, oud[u]++, G[u].push_back(v);
	}
	
	std::queue<int>que; k = 0;
	for (int i = 1; i <= n; i++) if (!ind[i])
		que.push(s[k] = i), f[i][k] = 1, k++;
	
	while (!que.empty()) {
		int x = que.front(); que.pop();
		for (auto to : G[x]) {
			for (int i = 0; i < k; i++)
				add(f[to][i], f[x][i]);
			
			ind[to]--;
			if( ind[to] == 0 )
				que.push(to);
		}
	}
	
	k = 0;
	for (int i = 1; i <= n; i++) if (!oud[i])
		t[k++] = i;
	
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = f[t[i]][j];
	printf("%d\n", det());
}