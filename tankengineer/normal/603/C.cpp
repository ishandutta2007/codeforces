#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, k;

int sg[N];

int getSG(int a) {
	if (a == 0) {
		return 0;
	} else if (a == 1) {
		return 1;
	} else if (a == 2) {
		return 0;
	} else if (a == 3) {
		return 1;
	} else if (a == 4) {
		return 2;
	}
	if (a % 2) {
		return 0;
	}
	if (getSG(a / 2) == 1) {
		return 2;
	} else {
		return 1;
	}
}

int main() {
	scanf("%d%d", &n, &k);
	int sg = 0;
	if (k % 2 == 0) {
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d", &a);
			if (a == 1) {
				sg ^= 1;
			} else if (a == 2) {
				sg ^= 2;
			} else {
				sg ^= (1 - a % 2);
			}
		}
	} else {
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d", &a);
			sg ^= getSG(a);
		}
	}
	puts(sg ? "Kevin" : "Nicky");
	return 0;
}