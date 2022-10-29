#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxv = 1000001;
int n, m, a[200010];
set<pii> T[maxv];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		int r = i;
		while (r + 1 <= n && a[r + 1] == a[i]) ++r;
		T[a[i]].insert(pii(r, i));
		i = r;	
	}
	for (int i = 1; i <= m; ++i) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		set<pii>::iterator now = T[x].lower_bound(pii(l, 0));
		if (now == T[x].end()) printf("%d\n", l);
		else if (now->first >= r) {
			if (now->second > l) printf("%d\n", l);
			else printf("-1\n");
		}
		else printf("%d\n", now->first + 1); 
	}
}