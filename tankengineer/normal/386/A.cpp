#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int maxs = -1, maxn = -1, smaxs = -1;
	for (int i = 0; i < n; ++i) {
		int v = 0;
		scanf("%d", &v);
		if (v > maxs) {
			smaxs = maxs;
			maxs = v;
			maxn = i + 1;
		} else if (v > smaxs) {
			smaxs = v;
		}
	}
	printf("%d %d\n", maxn, smaxs);
	return 0;
}