#include <bits/stdc++.h>
using namespace std;

const int N = 1.5e6 + 5;
const int M = N * 2;

int fir[N], ne[M], to[M], cnt = 1, du[N], n, x, y;

void add(int x, int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x, int y) {
	add(x, y);
	add(y, x);
	++ du[x], ++ du[y];
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

char s[N];

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n * 3; ++ i) fir[i] = du[i] = 0;
	cnt = 0;
	for(int i = 1; i < n; ++ i) scanf("%d%d", &x, &y), link(x, y);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++ i) {
		if(s[i] == 'W') {
			link(i, ++ n);
			link(n, n + 1);
			link(n, n + 2);
			n += 2;
		}
	}
	bool ok = 0;
	int three = 0;
	for(int i = 1; i <= n; ++ i) {
		if(du[i] >= 4) {
			ok = 1;
			break;
		}
		if(du[i] == 2) {
			bool l = 1;
			Foreachson(j, i) {
				int V = to[j];
				l &= (du[V] >= 3);
			}
			if(l) {
				ok = 1; break;
			}
		}  
		if(du[i] <= 2) continue;
		if(du[i] >= 3) {
			++ three;
		}
		int ban = 0;
		Foreachson(j, i) {
			int V = to[j];
			if(du[V] >= 2) ++ ban;
		}
		if(ban >= 2) {
			ok = 1; break;
		}
	}
	if(ok || three > 2 || (three == 2 && (n & 1))) puts("White");
	else puts("Draw");
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}