#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N(100011);
int b[N];
int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	LL sa(0), sn(1);
	for(int i(0); i < n; i++) {
		int x;
		scanf("%d", &x);
		sa += sn * x;
		sn *= -1;
	}
	LL sb(0);
	sn = -1;
	set<LL> st;
	for(int i(1); i <= m; i++) {
		scanf("%d", &b[i]);
		if(i <= n) {
			sn *= -1;
			sb += sn * b[i];
		}else {
			sb -= b[i - n];
			sb *= -1;
			sb += sn * b[i];
		}
		if(i >= n) {
			st.insert(sb);
		}
	}
	for(int i(0); i <= q; i++) {
		if(i >= 1) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			if(y % 2 == x % 2) {
				if(x & 1) sa += z;
				else sa -= z;
			}
		}
		auto itr(st.lower_bound(sa));
		LL ans(1e18);
		if(itr != st.end()) {
			ans = *itr - sa;
		}
		if(itr != st.begin()) {
			itr--;
			ans = min(ans, sa - *itr);
		}
		cout << ans << endl;
	}
}