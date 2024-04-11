#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int A[N], n, m, x, y, k, S[N], f[N];

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 0; i <= n; ++ i) S[i] = f[i] = 0;
	int now = 0;
	for(int i = n; i >= 1; -- i) {
		++ S[A[i]];
		while(S[now]) ++ now;
		f[i] = now;
	}
	
	vector <int> b;
	for(int i = 0; i <= n; ++ i) S[i] = 0;
	int cur = 1;
	now = -1;
	while(cur <= n) {
		int it = f[cur], L = cur;
		now = 0;
		++ S[A[cur]]; ++ cur;
		while(S[now]) ++ now;
		while(now != it) {
			++ S[A[cur]];
			++ cur;
			while(S[now]) ++ now;
		}
		b.push_back(it);
		for(int i = L; i < cur; ++ i) S[A[i]] = 0;
	}
	cout << b.size() << endl;
	for(int i = 0; i < (int) b.size(); ++ i) printf("%d ", b[i]);
	puts("");
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}