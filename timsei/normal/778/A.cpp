#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int l, r, ans, n, m, A[N];
char s[N], t[N];
bool vis[N];

bool pd(int x) {
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= x; ++ i) {
		vis[A[i]] = 1;
	}
	int it = 1;
	for(int i = 1; i <= n; ++ i) {
		if(it == m + 1) break;
		if(vis[i]) continue;
		if(s[i] == t[it]) ++ it;
	}
	return (it == m + 1);
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%s", t + 1);
	m = strlen(t + 1);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &A[i]);
	}
	l = 0, r = n;
	int res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(pd(mid)) {
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	} 
	cout << res << endl;
}