#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int st[N][31], n, m, x, y, A[N], B[N], tot, k, ok[N], L[N];

vector <int> All[N];

set <int> S;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &st[i][0]); ++ ok[st[i][0]];
	}
	for(int i = 1; i < 31; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			st[j][i] = st[st[j][i - 1]][i - 1];
		}
	}
	int mx = 0;
	for(int i = 1; i <= n; ++ i)  {
		scanf("%d", &A[i]);
		mx = max(mx, A[i]);
		if(!ok[i]) ++ tot;
	}
	k = (mx - n) / tot;
	for(int i = 1; i <= n; ++ i) {
		int now = i;
		for(int j = 30; j >= 0; -- j) if((k >> j) & 1) {
			now = st[now][j];
		}
		All[now].push_back(i);
	}
	
	for(int i = 1; i <= n; ++ i) S.insert(i);
	
	for(int i = 1; i <= n; ++ i) {
		if(A[i] <= n) {
			S.erase(A[i]);
			sort(All[i].begin(), All[i].end());
			B[All[i][0]] = A[i];
			for(int j = 1; j < (int) All[i].size(); ++ j)
			L[All[i][j]] = A[i];
		}
	}
	for(int i = 1; i <= n; ++ i) if(!B[i]) {
		int now = *(S.lower_bound(L[i]));
		B[i] = now;
		S.erase(now);
	}
	for(int i = 1; i <= n; ++ i) printf("%d ", B[i]);
	puts("");
}