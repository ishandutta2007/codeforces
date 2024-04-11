#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k, x;

bool make(int ac, int head, int tail, int len, string &ret) {
	ret = "";
	if (head) {
		ret += 'C';
	}
	for (int i = 0; i < ac; ++i) {
		ret += 'A';
		ret += 'C';
	}
	while (ret.size() < len - tail) {
		ret += 'X';
	}
	if (tail) {
		ret += 'A';
	}
	return ret.size() == len;
}

int times[55], head[55], tail[55];

bool check(int l1, int l2, int k1, int k2, int k3, int k4) {
	times[0] = l1, head[0] = k1, tail[0] = k2;
	times[1] = l2, head[1] = k3, tail[1] = k4;
	for (int i = 2; i < k; ++i) {
		times[i] = times[i - 2] + times[i - 1] + tail[i - 2] * head[i - 1];	
		if (times[i] > x) {
			return false;
		}
		head[i] = head[i - 2];
		tail[i] = tail[i - 1];
	}
	return times[k - 1] == x;
}

int main() {
	string ans1, ans2;
	scanf("%d%d%d%d", &k, &x, &n, &m);
	for (int i = 0; i * 2 <= n; ++i) {
		for (int j = 0; j * 2 <= m; ++j) {
			for (int k1 = 0; k1 <= 1; ++k1) {
				for (int k2 = 0; k2 <= 1; ++k2) {
					for (int k3 = 0; k3 <= 1; ++k3) {
						for (int k4 = 0; k4 <= 1; ++k4) {
							if (make(i, k1, k2, n, ans1) && make(j, k3, k4, m, ans2)) {
								if (check(i, j, k1, k2, k3, k4)) {
									cout << ans1 << endl << ans2 << endl;
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "Happy new year!" << endl;
	return 0;
}