#include <bits/stdc++.h>
using namespace std;

const int N = 4e3 + 5;
const long long INF = 2e10;

int n, m, x, y, id[N], lk[N], vy[N], pre[N], d;
long long w[N][N], lx[N], ly[N], slk[N], cnt[N];

int with[N], vis[N];

bool ok[N];
int cn = 0;

void solve(int i, int x) {
	if(vis[i]) {
		return;
	}
	vis[i] = 1;
	int now = with[i];
	int it = id[i] - x;
	assert((id[i] & it) == it);
	for(int j = 0; j < d; ++ j) {
		if((it >> j) & 1)  printf("%d ", j), ++ cn;
	}
	if(!now) {
		return;
	}
	solve(with[i], id[i]);
}

char s[N];

int main() {
	cin >> d >> n;
	cnt[0] = 0;
	for(int i = 1; i < (1 << d); ++ i)
	cnt[i] = cnt[i >> 1] + (i & 1);
	for(int i = 1; i <= n; ++ i) {
		scanf("%s", s);
		int l = strlen(s);
		for(int j = 0; j < l; ++ j)
		id[i] += (s[j] == '1') * (1 << j);
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) if(j != i) {
			if((id[i] & id[j]) == id[i]) {
				w[i][j] = cnt[id[i]] + 2;
			} else w[i][j] = 1;
		}
		w[i][i] = 1;
	}
	for(int i = 1, py, p; i <= n; ++ i) {
		long long d;
		for(int j = 1; j <= n; ++ j) slk[j] = INF, vy[j] = 0;
		for(lk[py = 0] = i; lk[py]; py = p){
			vy[py] = 1; d = INF; x = lk[py];
			for(int y = 1; y <= n; ++ y) if(!vy[y]) {
				if(lx[x] + ly[y] - w[x][y] < slk[y])
				slk[y] = lx[x] + ly[y] - w[x][y], pre[y] = py;
				if(slk[y] < d) d = slk[y], p = y;
			}
			for(int y = 0; y <= n; ++ y)
			if(vy[y])
			 lx[lk[y]] -= d, ly[y] += d; else slk[y] -= d;
		}
		for(; py; py = pre[py]) lk[py] = lk[pre[py]];
  	}
	int ans = 0;
	for(int i = 1; i <= n; ++ i) 
	if(lk[i] != -1 && w[lk[i]][i] != 1) ans += w[lk[i]][i], with[lk[i]] = i;
	else ++ ans;
	ans = ans - n * 2;
	ans = -ans;
	for(int i = 1; i <= n; ++ i) 
	ans += cnt[id[i]];
	cn = 0;
	cout << ans - 1 << endl;
	for(int i = 1; i <= n; ++ i)
	if(!with[i]) cn += cnt[id[i]] + 1;
	memset(vis, 0, sizeof(vis));
	int tt = 0;
	for(int i = 1; i <= n; ++ i) {
		if(id[i] == 0) continue;
		if(w[lk[i]][i] == 1) {
			if(tt) printf("R "), ++ cn;
			cn = 0;
			++ tt;
			solve(i, 0);
		}
	}
}