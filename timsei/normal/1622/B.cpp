#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int T, n, m, x, y, P[N], A[N];
vector <int> L, R;
char s[N];

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) scanf("%d", &P[i]);
	scanf("%s", s + 1);
	L.clear(); R.clear();
	for(int i = 1; i <= n; ++ i) if(s[i] == '0') L.push_back(P[i]); else R.push_back(P[i]);
	sort(L.begin(), L.end()); sort(R.begin(), R.end());
	long long ans = 0;
	for(int i = 1; i <= L.size(); ++ i) {
		A[L[i - 1]] = i;
	}
	for(int i = L.size() + 1; i <= n; ++ i) {
		A[R[i - L.size() - 1]] = i;
	}
	for(int i = 1; i <= n; ++ i) printf("%d ", A[P[i]]);
	puts("");
} 

int main() {
	for(cin >> T; T --;) rmain();
}