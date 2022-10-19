#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int A[N][N], nn[N], mm[N], n, m;

int L, R;

bool Check() {
	L = R = 0;
	for(int i = 1; i <= n; ++ i) {
		int ans = 0;
		for(int j = 1; j <= m; ++ j) ans += A[i][j];
		if(ans < 0) {
			L = i; return 0;
		}
	}
	for(int i = 1; i <= m; ++ i) {
		int ans = 0;
		for(int j = 1; j <= n; ++ j) ans += A[j][i];
		if(ans < 0) {
			R = i; return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) scanf("%d", &A[i][j]);
	}
	while(!Check()) {
		if(!L) {
			mm[R] ^= 1;
			for(int i = 1; i <= n; ++ i) A[i][R] = - A[i][R];
		} else {
			nn[L] ^= 1;
			for(int i = 1; i <= m; ++ i) A[L][i] = - A[L][i];
		}
	}
	vector <int> a, b;
	for(int i = 1; i <= n; ++ i) if(nn[i]) a.push_back(i);
	cout << a.size() << ' ';
	for(auto x : a) cout << x <<' ';
	cout << endl;
	for(int i = 1; i <= m; ++ i) if(mm[i]) b.push_back(i);
	cout << b.size() <<  ' ';
	for(auto x : b) cout << x <<' ';
	cout << endl;
	
}