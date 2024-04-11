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

using namespace std;

vector <long long> ans;

int calc(int X) {
	for (int i = 1; ; i++)
		if ((1LL << i) - 1 > X)
			return i - 1;
}

int main() {
	int X, d;
	scanf("%d%d", &X, &d);
	long long now = 1;
	while (X) {
		int t = calc(X);
		for (int i = 1; i <= t; i++)
			ans.push_back(now);
		now += d + 1;
		X -= (1LL << t) - 1;
		// printf("%d\n", X);
	}
	printf("%lu\n", ans.size());
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << ' ';
	printf("\n");
}