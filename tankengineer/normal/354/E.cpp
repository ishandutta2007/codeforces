#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

vector<pair<int, int> > ans, now, sub[10];
bool over;

void construct (long long n) {
	if (n < 0) {
		return;
	}
	if (n == 0) {
		over = true;
		ans = now;
		return;
	}
	long long t = n % 10;
	for (int k = 0; !over && k < (int)sub[t].size(); ++k) {
		int i = sub[t][k].first, j = sub[t][k].second;
		now.push_back(sub[t][k]);
		construct((n - i * 4 - j * 7) / 10);
		now.pop_back();
	}
}

int main() {
	for (int i = 0; i <= 6; ++i) {
		for (int j = 0; i + j <= 6; ++j) {
			sub[(i * 4 + j * 7) % 10].push_back(make_pair(i, j));
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n;
		cin >> n;
		over = false;
		construct(n);
		if (!over) {
			printf("-1\n");
		} else {
			long long a[6];
			memset(a, 0, sizeof(a));
			for (int i = (int)ans.size() - 1; i >= 0; --i) {
				for (int j = 0; j < 6; ++j) {
					a[j] *= 10;
					if (j < ans[i].first) {
						a[j] += 4;
					} else if (j < ans[i].first + ans[i].second) {
						a[j] += 7;
					}
				}
			}
			for (int i = 0; i < 6; ++i) {
				cout << a[i] << (i == 5 ? '\n' : ' ');
			}
		}
	}
	return 0;
}