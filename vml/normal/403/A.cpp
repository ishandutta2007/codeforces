#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		set <pair <int, int> > s;
		int p;
		scanf("%d", &p);
		for (int i = 0; i < 2 * n + p; i++) {
			printf("%d %d\n", i % n + 1, (i + 1 + i / n) % n + 1);
		}
	}
	return 0;
}