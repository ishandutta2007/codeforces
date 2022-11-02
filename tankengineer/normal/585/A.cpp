#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 4005;

int n;

long long v[N], d[N], p[N];

bool used[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		cin >> v[i] >> d[i] >> p[i];
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			ans.push_back(i);
			long long delta = v[i];
			for (int j = i + 1; j < n && delta > 0; ++j) {
				if (!used[j]) {
					p[j] -= delta;
					--delta;
				}
			}
			for (int j = i + 1; j < n; ++j) {
				if (!used[j] && p[j] < 0) {
					for (int k = j + 1; k < n; ++k) {
						p[k] -= d[j];
					}
					used[j] = true;
				}
			}
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d%c", ans[i] + 1, i == (int)ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}