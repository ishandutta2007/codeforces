#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, x, y, k, A[N];

map <int, int> Map;

void rmain() {
	cin >> n; int Min = 2e9;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), Min = min(Min, A[i]);
	sort(A + 1, A + n + 1);
	int cnt1 = 0;
	for(int i = 1; i <= n; ++ i) cnt1 += (A[i] == 1);
	if(!cnt1 || cnt1 == n) {
		puts("YES");
		return;
	} 
	if(cnt1 && A[1] == 0) {
		puts("NO");
		return;
	}
	int cnt2 = 0;
	for(int i = 1; i <= n; ++ i) cnt2 += (A[i] == 2);
	if(cnt2) {
		puts("NO");
		return;
	}
	bool ok = 0;
	for(int i = 2; i <= n; ++ i) {
		if(A[i] == A[i - 1] + 1) ok = 1;
	}
	if(!ok)
	puts("YES"); else puts("NO");
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}