#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, x, y, A[N], nxt[N], lst[N];

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

set <int> S;

int main() {
	int t;
	for(cin >> t; t --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), 
		lst[i] = i - 1, nxt[i] = i + 1;
		lst[1] = n; nxt[n] = 1;
		for (int i = 1; i <= n; ++ i) {
			if(gcd(A[i], A[nxt[i]]) == 1) S.insert(i);
		}
		
		int be = 1;
		
		vector <int> ans;
		
		while(S.size()) {
			auto now = S.lower_bound(be);
			if(now == S.end()) {
				now = S.lower_bound(1);
			}
			
			int x = nxt[*now];
			ans.push_back(x);
			S.erase(now);
			int a = lst[x], b = nxt[x];
			if(a == x) break;
			lst[b] = a; nxt[a] = b;
			
			if(gcd(A[b], A[x]) == 1) S.erase(x);
			if(gcd(A[b], A[a]) == 1) S.insert(a);
			be = x;
		}
		printf("%d ", (int)ans.size());
		for(auto x : ans) printf("%d ", x);
		puts("");
	}
}