#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int cnt[8];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		int t1;
		scanf("%d", &t1);
		++cnt[t1];
	}
	if (cnt[7] || cnt[5]) {
		printf("-1\n");
		return 0;
	}
	int type1 = cnt[4];
	cnt[4] -= type1;
	cnt[2] -= type1;
	cnt[1] -= type1;
	int type2 = cnt[3];
	cnt[6] -= cnt[3];
	cnt[3] -= type2;
	cnt[1] -= type2;
	int type3 = cnt[6];
	if (type3 < 0) {
		printf("-1\n");
		return 0;
	}
	cnt[6] -= type3;
	cnt[2] -= type3;
	cnt[1] -= type3;
	for (int i = 1; i <= 7; ++i) {
		if (cnt[i] != 0) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 0; i < type1; ++i) {
		printf("1 2 4\n");
	}
	for (int i = 0; i < type2; ++i) {
		printf("1 3 6\n");
	}
	for (int j = 0; j < type3; ++j) {
		printf("1 2 6\n");
	}
	return 0;
}