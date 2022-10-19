#include <bits/stdc++.h>
using namespace std;

const int N = 11111111;

#define int long long

int A[N], n, m, a, b, B[N];

bool cmp(int x, int y) {
	return x > y;
}

vector <int> who;

map <int, int> vis;

main(void) {
	clock_t start = clock();
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%lld", &A[i]);
		if(vis.count(A[i])) continue;
		who.push_back(A[i]);
		vis[A[i]] = 1;
	}
	scanf("%lld%lld", &a, &b);
	sort(who.begin(), who.end());
	who.erase(unique(who.begin(), who.end()), who.end());
	n = who.size();
	for(int i = 1; i <= n; ++ i) A[i] = who[i - 1];
	int ans = 0;
	while(a != b) {
		int Min = a - 1;
		int m = 0;
		for(int i = 1; i <= n; ++ i) {
			if(a - a % A[i] < b) continue;
			Min = min(Min, a - a % A[i]);
			B[++ m] = A[i];
		}
		a = Min;
		n = m;
		for(int i = 1; i <= n; ++ i) A[i] = B[i];
		++ ans;
	}
	cout << ans << endl;
}