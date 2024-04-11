#include<vector>
#include<cstdio>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005;
int a[N];

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0, cnt = 0, cntz[5];
	memset(cntz, 0, sizeof(cntz));
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		sum += a[i];
		cnt += a[i] > 0;
		cntz[a[i]]++;
	}
	if (sum < 3 || sum == 5) {
		printf("-1\n");
		return 0;
	}
	int ans = 0;
	int mov = min(cntz[1], cntz[2]);
	ans += mov;
	cntz[1] -= mov;
	cntz[2] -= mov;
	cntz[3] += mov;
	if (cntz[1] > 0) {
		mov = cntz[1] / 3 * 2;
		ans += mov;
		cntz[1] -= mov / 2 * 3; 
		cntz[3] += mov / 2;
		if (cntz[1] > 0) {
			if (cntz[3] >= cntz[1]) {
				mov = min(cntz[1], cntz[3]);
				ans += mov;
				cntz[1] -= mov;
				cntz[3] -= mov;
				cntz[4] += mov;
			} else {
				ans += 2;
			}
		}
	} else if (cntz[2] > 0) {
		mov = cntz[2] / 3;
		ans += mov * 2;
		cntz[2] -= mov * 3;
		cntz[3] += mov * 2;
		if (cntz[2] > 0) {
			if (cntz[2] == 1) {
				if (cntz[4]) {
					ans += 1;
				} else {
					ans += 2;
				}
			} else {
				ans += 2;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}