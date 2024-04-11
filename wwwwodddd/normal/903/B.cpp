#include <bits/stdc++.h>
using namespace std;
int h1, a1, c1, h2, a2;
vector<int> z;
int main() {
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	while (true) {
		if (h2 <= a1) {
			z.push_back(0);
			break;
		}
		h1 -= a2;
		if (h1 <= 0) {
			h1 += c1;
			z.push_back(1);
		} else {
			h2 -= a1;
			z.push_back(0);
		}
		if (h2 <= 0) {
			break;
		}
	}
	printf("%d\n", z.size());
	for (int i: z) {
		if (i) {
			printf("HEAL\n");
		} else {
			printf("STRIKE\n");
		}
	}
}