#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int n, a[N];
bool mark[N];

bool byA(int i, int j) {
	return a[i] > a[j];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j < n && a[j] != 0) {
			++j;
		}
		vector<int> pos;
		for (int k = i; k < j; ++k) {
			pos.push_back(k);
		}
		sort(pos.begin(), pos.end(), byA);
		for (int k = 0; k < 3 && k < (int)pos.size(); ++k) {
			mark[pos[k]] = true;
		}
		int cnt = 0;
		for (int k = i; k < j; ++k) {
			if (!mark[k]) {
				if (cnt < 3) {
					puts("pushStack");
				} else {
					puts("pushQueue");
				}
			} else {
				if (cnt == 0) {
					puts("pushFront");
				} else if (cnt == 1) {
					puts("pushQueue");
				} else if (cnt == 2) {
					puts("pushStack");
				}
				++cnt;
			}
		}
		if (j != n) {
			printf("%d", cnt);
			if (cnt >= 1) {
				printf(" popFront");
				if (cnt >= 2) {
					printf(" popQueue");
					if (cnt >= 3) {
						printf(" popStack");
					}
				}
			}
			printf("\n");
		}
		i = j;
	}
	return 0;
}