#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;

int t, x[4], y[4];
vector<int> ord(4);
const int dx[] = {0, 1, 0, 1};
const int dy[] = {0, 0, 1, 1};
vector<int> delta;

inline const int sign(const int x) {
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 4; ++i) 
			scanf("%d%d", x + i, y + i);
		ll res = 1LL << 60;
		for (int a = 0; a < 4; ++a)
			for (int b = 0; b < 4; ++b) {
				int dx = x[a], dy = y[b];
				ll curr = 0;
				for (int k = 0; k < 4; ++k) {
					curr += abs(x[k] - dx);
					curr += abs(y[k] - dy);
				}
				for (int ax : {-1, 1})
					for (int ay : {-1, 1}) {
						iota(ord.begin(), ord.end(), 0);
						do {
							delta.clear();
							for (int i = 0; i < 4; ++i) {
								if (ord[i] == 1 || ord[i] == 3) {
									if (sign(x[i] - dx) == ax)
										delta.push_back(abs(x[i] - dx));
									else
										delta.push_back(0);
								}
								if (ord[i] == 2 || ord[i] == 3) {
									if (sign(y[i] - dy) == ay)
										delta.push_back(abs(y[i] - dy));
									else
										delta.push_back(0);
								}
							}
							sort(delta.begin(), delta.end());
							res = min(res, curr - 4LL * delta[0] - 2LL * (delta[1] - delta[0]));
						} while (next_permutation(ord.begin(), ord.end()));
					}
			}
		printf("%lld\n", res);
	}
	return 0;
}