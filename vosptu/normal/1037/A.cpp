#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int k = 1, ans = 0;
	while (k <= n) {
		k *= 2;
		ans ++;
	}
	printf("%d\n", ans);
}