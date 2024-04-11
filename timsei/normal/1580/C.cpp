#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int Bl = (int) sqrt(N) + 2;

int n, m, A[N], B[N], op, k, S[(int)sqrt(N) + 3][(int)sqrt(N) + 3], now, x, Tag[N], lst[N];

void add(int k, int x) {
	lst[x] = k;
	if(A[x] + B[x] <= Bl) {
		int t = A[x] + B[x];
		int now = k % t;
		now = (now + A[x] - 1) % t;
		for(int i = 1; i <= B[x]; ++ i) {
			now ++;
			if(now == t) now = 0;
			++ S[t][now];
//			cerr << t <<' ' << now << endl;
		}
		return;
	} else {
		for(int i = k + A[x]; i <= m; i += (A[x] + B[x])) {
			++ Tag[i];
			-- Tag[min(i + B[x], m + 1)];
		}
		return;
	}
}

void del(int k, int x) {
	if(A[x] + B[x] <= Bl) {
		k = lst[x];
		int t = A[x] + B[x];
		int now = k % t;
		now = (now + A[x] - 1) % t;
		for(int i = 1; i <= B[x]; ++ i) {
			now ++;
			if(now == t) now = 0;
			-- S[t][now];
		}
		return;
	} else {
		int ll = k;
		k = lst[x];
		for(int i = k + A[x]; i <= m; i += (A[x] + B[x])) {
			if(ll > i && ll <= i + B[x]) {
				-- now;
			}
			-- Tag[i];
			++ Tag[min(i + B[x], m + 1)];
		}
		
		return;
	}
}

int calc(int x) {
	int ans = 0;
	for(int i = 1; i <= Bl; ++ i) {
		ans += S[i][x % i];
	}
	return ans;
}

int main() {
	cin >> n >> m;
	Bl = (int) sqrt(m) + 1;
	for(int i = 1; i <= n; ++ i) {
		scanf("%d%d", &A[i], &B[i]);
	}
	for(int i = 1; i <= m; ++ i) {
		scanf("%d%d", &op, &x);
		if(op == 1) {
			add(i, x);
		} else del(i, x);
		now = now + Tag[i];
		printf("%d\n", now + calc(i));
	}
}