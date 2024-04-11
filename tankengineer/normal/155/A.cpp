#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int mins, maxs, ans = 0;
	for (int i = 0; i < n; ++i) {
		int t1;
		scanf("%d", &t1);
		if (i == 0) {
			mins = maxs = t1;
		} else {
			if (t1 < mins || t1 > maxs) {
				++ans;
			}
			mins = min(t1, mins);
			maxs = max(t1, maxs);
		}
	}
	printf("%d\n", ans);
	return 0;
}