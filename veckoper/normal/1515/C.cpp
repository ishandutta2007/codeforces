#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int Case, n, m, x;
set<pii> st;
int main() {
	scanf("%d", &Case);
	while (Case--) {
		scanf("%d%d%d", &n, &m, &x);
		st.clear();
		for (int i = 1; i <= m; ++i) st.insert(pii(0, i));
		puts("YES");
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &x);
			pii tmp = *st.begin(); tmp.first += x;
			st.erase(st.begin());
			printf("%d ", tmp.second);
			st.insert(tmp);
		}
		puts("");
	}
	return 0;
}