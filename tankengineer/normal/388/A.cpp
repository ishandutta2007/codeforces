#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int l[105];

int main() {
	vector<int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 1; i <= n; ++i) {
		bool flag = true;
		int t = 0;
		for (int j = 0; j < i; ++j) {
			l[j] = v[t++];
		}
		while (t < (int)v.size()) {
			int k = 0;
			for (int o = 0; o < i; ++o) {
				if (l[o] > l[k]) {
					k = o;
				}
			}
			if (l[k] == 0) {
				flag = false;
				break;
			}
			l[k] = min(l[k] - 1, v[t++]);
		}
		if (flag) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}