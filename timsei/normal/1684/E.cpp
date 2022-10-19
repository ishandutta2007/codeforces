#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k, A[N], B[N], t;
map <int, int> cnt;

void rmain() {
	int ans = 0;
	scanf("%d%d", &n, &k);
	cnt.clear();
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), ++ cnt[A[i]];
	int now = cnt.size(); int emp = 0;
	multiset <int> S, T;
	S.clear(); T.clear();
	for(auto x : cnt) S.insert(x.second);
	int L = k;
	while(S.size() && (*S.begin()) <= L) {
		int no = (*S.begin()); L -= no;
		S.erase(S.find(no));
		T.insert(no);
	}
	ans = now - T.size();
	int all = n;
	for(int i = 0; i < n; ++ i) {
		emp += (!cnt.count(i));
		if(cnt.count(i)) all -= cnt[i];
		if(emp > k) break;
		if(!cnt.count(i)) {
		} else {
			-- now;
			int cur = cnt[i];
			if(S.find(cur) != S.end()) {
				S.erase(S.find(cur));
			} else {
				L += cur; T.erase(T.find(cur));
			}
			while(S.size() && (*S.begin()) <= L) {
				int no = (*S.begin()); L -= no;
				S.erase(S.find(no));
				T.insert(no);
			}			
		}
		ans = min(ans, now - (int)T.size());
	}
	cout << ans << endl;
}

main() {
	for(cin >> t; t --;) {
		rmain();
	}
}