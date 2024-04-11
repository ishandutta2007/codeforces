#include<bits/stdc++.h>
using namespace std;
const int N(222222);
int u[N], v[N];
long long w[N];
int rela[N], siz[N], cnt[N][60][2];
long long delta[N];
bool ok[N];
int modulo(1e9 + 7);
int getr(int x) {
	long long tot(0);
	int p(x);
	while(p != rela[p]) {
		tot ^= delta[p];
		p = rela[p];
	}
	int p1(p); 
	p = x;
	while(p != rela[p]) {
		int p2(rela[p]);
		tot ^= delta[p];
		delta[p] ^= tot;
		rela[p] = p1;
		p = p2;
	}
	return p1;
}
struct Set {
	long long a[60];
	Set() {
		memset(a, 0, sizeof(a));
	}
	void insert(long long x) {
		for(int i(59); i >= 0; i--) {
			if(a[i] && ((x >> i & 1) > 0)) {
				x ^= a[i];
			}
		}
		if(x != 0) {
			for(int i(59); i >= 0; i--) {
				if(!a[i] && (x >> i & 1) > 0) {
					a[i] = x;
					break;
				}
			}
		}
	}
	void operator += (const Set & b) {
		for(int i(59); i >= 0; i--) {
			if(b.a[i]) {
				insert(b.a[i]);
			}
		}
	}
} st[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(0); i < m; i++) {
		scanf("%d%d%I64d", &u[i], &v[i], &w[i]);
	}
	int ans(0);
	for(int i(1); i <= n; i++) {
		rela[i] = i;
		siz[i] = 1;
		ok[i] = false;
		delta[i] = 0;
	}
	for(int i(0); i < m; i++) {
		int x(getr(u[i])), y(getr(v[i]));
		long long z(w[i]);
		//printf("%d %d %d\n", x, y, z);
		if(x == y) {
			if((delta[u[i]] ^ delta[v[i]]) != z) {
				//printf("!!\n");
				st[x].insert(delta[u[i]] ^ delta[v[i]] ^ z);
			}
		}else {
			delta[x] = delta[u[i]] ^ delta[v[i]] ^ z;
			rela[x] = y;
			st[y] += st[x];
			siz[y] += siz[x];
		}
	}
	for(int i(1); i <= n; i++) {
		int fa(getr(i));
		for(int j(0); j < 60; j++) {
			cnt[fa][j][delta[i] >> j & 1] ++;
		}
	}
	for(int i(1); i <= n; i++) {
		if(rela[i] == i) {
			//printf("%d %d\n", cnt[i][0][0], cnt[i][0][1]);
			long long tot(0);
			int tmp(1);
			for(int j(0); j < 60; j++) {
				tot |= st[i].a[j];
				if(st[i].a[j]) {
					tmp = tmp * 2 % modulo;
				}
			}
			//printf("%I64d\n", tot);
			int tmp2((long long)tmp * ((modulo + 1) / 2) % modulo);
			for(int j(0); j < 60; j++) {
				ans = (ans + (long long)cnt[i][j][0] * cnt[i][j][1] % modulo * ((tot >> j & 1) ? tmp2 : tmp) % modulo * ((1ll << j) % modulo)) % modulo;
				ans = (ans + ((long long)cnt[i][j][1] * (cnt[i][j][1] - 1) / 2 % modulo) * ((tot >> j & 1) ? tmp2 : 0) % modulo * ((1ll << j) % modulo)) % modulo;
				ans = (ans + ((long long)cnt[i][j][0] * (cnt[i][j][0] - 1) / 2 % modulo) * ((tot >> j & 1) ? tmp2 : 0) % modulo * ((1ll << j) % modulo)) % modulo;
			}
		}
	}
	printf("%d\n", ans);
}