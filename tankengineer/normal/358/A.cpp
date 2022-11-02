#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000;
int n, x[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", x + i);
	}
	bool flag = false;
	for (int i = 0; !flag && i + 1 < n; ++i) {
		for (int j = i + 1; !flag && j + 1 < n; ++j) {
			int l1 = min(x[i], x[i + 1]), r1 = max(x[i], x[i + 1]),
				l2 = min(x[j], x[j + 1]), r2 = max(x[j], x[j + 1]);
			if (!(l1 <= l2 && r2 <= r1 || l2 <= l1 && r1 <= r2) && !(r1 <= l2 || r2 <= l1)) {
				flag = true;
			}
		}
	}
	puts(!flag ? "no" : "yes");
	return 0;
}