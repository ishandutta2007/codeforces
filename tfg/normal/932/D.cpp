#include <iostream>
#include <cstdio>

const int ms = 400100;
const int me = 20;

long long up[ms][me][4];
int a[ms];
int c = 1;

void add(int x, int par) {
	int n = c++;
	a[n] = x;
	up[n][0][0] = par;
	up[n][0][1] = x;
	for(int i = 1; i < me; i++) {
		up[n][i][0] = up[up[n][i - 1][0]][i - 1][0];
		up[n][i][1] = std::max(up[n][i - 1][1], up[up[n][i - 1][0]][i - 1][1]);
	}
	for(int i = me - 1; i >= 0; i--) {
		if(up[par][i][1] < x) par = up[par][i][0];
	}
	up[n][0][2] = par;
	up[n][0][3] = x;
	for(int i = 1; i < me; i++) {
		up[n][i][2] = up[up[n][i - 1][2]][i - 1][2];
		up[n][i][3] = std::min(up[n][i - 1][3] + up[up[n][i - 1][2]][i - 1][3], (long long) 1e16);
	}
}

long long solve(int n, long long x) {
	int ans = 0;
	for(int i = me - 1; i >= 0; i--) {
		if(up[n][i][3] <= x) {
			x -= up[n][i][3];
			n = up[n][i][2];
			ans += (1 << i);
		}
	}
	return ans;
}

int main() {
	for(int i = 0; i < me; i++) {
		up[0][i][1] = up[0][i][3] = 1e16;
	}
	int q;
	std::cin >> q;
	add(0, 0);
	long long last = 0;
	while(q--) {
		long long t, p, q;
		scanf("%lli %lli %lli", &t, &p, &q);
		long long r = p ^ last, w = q ^ last;
		//std::cout << t << ", " << r << ", " << w << "\n";
		if(t == 1) {
			add(w, r);
		} else {
			last = solve(r, w);
			printf("%lli\n", last);
		}
	}
}