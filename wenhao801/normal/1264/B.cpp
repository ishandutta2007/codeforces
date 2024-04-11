#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
int a[5] = {};
int ans[100100] = {};
 
void solve (int S) {
	int N = a[1] + a[2] + a[3] + a[4];
	if (ans[N]) return;
	int i, j;
	if (!a[S]) return;
	for (i = 1; i <= N; i++) {
		ans[i] = S;
		a[S]--;
		if (i == N) break;
		if (S == 1) {
			if (a[2]) S++;
			else return;
		}
		else if (S == 2) {
			if (a[1]) S--;
			else if (a[3]) S++;
			else return;
		}
		else if (S == 3) {
			if (a[4]) S++;
			else if (a[2]) S--;
			else return;
		}
		else {
			if (a[3]) S--;
			else return;
		}
	}
}
 
int main () {
	int p, q, r, s;
	cin >> p >> q >> r >> s;
	for (int i = 1; i <= 4; i++) a[1] = p, a[2] = q, a[3] = r, a[4] = s, solve(i);
	if (ans[p + q + r + s]) {
		puts("YES");
		for (int i = 1; i <= p + q + r + s; i++) printf("%d ", ans[i] - 1);
	}
	else puts("NO");
	return 0;
}