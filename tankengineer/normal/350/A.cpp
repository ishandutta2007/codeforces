#include<climits>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int mins = INT_MAX, maxs = INT_MIN;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		mins = min(mins, a);
		maxs = max(maxs, a);
	}
	int v = max(maxs, mins * 2);
	for (int i = 0; i < m; ++i) {
		int a;
		scanf("%d", &a);
		if (v >= a) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", v);
	return 0;
}