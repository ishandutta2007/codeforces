#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main() {
	int n;
	scanf("%d", &n);
	vector<iii> v(n);
	for(int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		v[i] = {{a, b}, i+1};
	}
	sort(v.begin(), v.end(), [](const iii a, const iii b) {
		if(a.first.first != b.first.first) return a.first.first < b.first.first;
		return a.first.second > b.first.second;
	;});
	ii ans = {v[0].first.second, v[0].second};
	for(int i = 1; i < n; i++) {
		if(ans.first >= v[i].first.second) {
			return 0 * printf("%d %d\n", v[i].second, ans.second);
		} else {
			ans = {v[i].first.second, v[i].second};
		}
	}
	return 0 * puts("-1 -1");
}//