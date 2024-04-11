#include <iostream>
// #include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
// #include <unordered_map>
#include <map>
#include <queue>
#include <set>

using namespace std;

#define N 110000
set <pair <long long, int> > se[N];
set <pair <long long, int> >:: iterator it;
int ans;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		se[i].insert(make_pair(0, 0));
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		long long w = 1LL * c * 1000000 + m - i;
		it = se[a].lower_bound(make_pair(w, 0));
		it--;
		int t = it -> second + 1;
		ans = max(ans, t);
		pair <long long, int> val = make_pair(w, t);
		it = se[b].lower_bound(val);
		it--;
		if (it -> second >= t)
			continue;
		while (true) {
			it = se[b].lower_bound(val);
			if (it != se[b].end() && t >= it -> second)
				se[b].erase(it);
			else
				break;
		}
		se[b].insert(val);
	}
	printf("%d\n", ans);
}