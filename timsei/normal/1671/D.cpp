#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

char s[N];
int n, x;

void rmain() {
	int n;
	scanf("%d%d", &n, &x);
	vector <int> A(n);
	int mi = 1e9, mx = 0;
	long long ans = 0;
	for(int i = 0; i < n; ++ i) scanf("%d", &A[i]), mi = min(mi, A[i]), mx = max(mx, A[i]);
	for(int i = 1; i < n; ++ i) ans += abs(A[i] - A[i - 1]);
	int R = min(mi - 1, x);
	ans += min(2 * (mi - 1), min(A[0] - 1, A.back() - 1));
	int L = mx + 1;
	if(x > mx) {
		ans += min(2 * (x - mx), min(abs(x - A[0]), abs(x - A.back())));
	}
	cout << ans << endl;
}


int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}