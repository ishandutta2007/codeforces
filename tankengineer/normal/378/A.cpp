#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int cnt[3];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= 6; ++i) {
		int t1 = abs(i - a), t2 = abs(i - b);
		if (t1 < t2) {
			++cnt[0];
		} else if (t1 == t2) {
			++cnt[1];
		} else {
			++cnt[2];
		}
	}
	printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
	return 0;
}