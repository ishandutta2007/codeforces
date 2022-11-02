#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <memory.h>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <vector>
#include <unordered_set>
 
using namespace std;

int main() {
	int n;

	scanf("%d", &n);

	int now;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		while (x % 2 == 0) {
			x /= 2;
		}

		while (x % 3 == 0) {
			x /= 3;
		}

		if (i == 0) {
			now = x;
		} else if (now != x) {
			printf("No");
			return 0;
		}
	}

	printf("Yes");

	return 0;
}