#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int T, n, m, x, y;
int ans = 0, All[N], Xi[N], id[N], P[N], who[N];
char s[11][N];

int sgn(int t, int x) {
	if(t == 0) return (-1) * x;
	else return x;
}

bool cmp(int x, int y) {
	return Xi[x] < Xi[y];
}

void rmain() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) scanf("%d", &All[i]);
	for(int i = 1; i <= n; ++ i)
	scanf("%s", s[i] + 1); ans = -1;
	for(int i = 0; i < (1 << n); ++ i) {
		for(int j = 1; j <= m; ++ j) Xi[j] = 0;
		int res = 0;
		for(int j = 1; j <= n; ++ j) {
			res -= sgn(((i >> (j - 1)) & 1), All[j]);
			for(int k = 1; k <= m; ++ k) {
				Xi[k] += sgn(((i >> (j - 1)) & 1), s[j][k] - '0');
				id[k] = k;
			}
		}
		sort(id + 1, id + m + 1, cmp);
		for(int j = 1; j <= m; ++ j) {
			res += Xi[id[j]] * j;
			who[id[j]] = j;
		}
		if(res >= ans) {
			ans = res;
			for(int j = 1; j <= m; ++ j) P[j] = who[j];
		}
	}
	for(int i = 1; i <= m; ++ i) printf("%d ", P[i]);
	puts("");
} 

int main() {
	for(cin >> T; T --;) rmain();
}