#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
	srand((int)time(NULL));
	int n, m;
	scanf("%d %d", &n, &m);
	set <pair <int, int> > box;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		box.insert(make_pair(v1, v2));
		box.insert(make_pair(v2, v1));
	}
	vector <int> num(n);
	for (int i = 0; i < n; i++) {
		num[i] = i + 1;
	}
	int count = 0;
	while (count < 1000) {
		random_shuffle(num.begin(), num.end());
		bool ok = true;
		for (int i = 0; i < m; i++) {
			if (box.count(make_pair(num[i], num[(i + 1) % n])) == 1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			for (int i = 0; i < m; i++) {
				printf("%d %d\n", num[i], num[(i + 1) % n]);
			}
			return 0;
		}
		count++;
	}
	printf("-1");
	return 0;
}