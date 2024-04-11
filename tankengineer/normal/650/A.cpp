#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

map<int, int> xs, ys;

map<pair<int, int>, int> xy;

int main() {
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		ans += xs[x] + ys[y] - xy[make_pair(x, y)];
		++xs[x], ++ys[y], ++xy[make_pair(x, y)];
	}
	cout << ans << endl;
	return 0;
}