#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;

const int N = 200;
int a[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int ans = a[0];
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			vector<int> in, out;
			for (int l = 0; l < n; ++l) {
				if (l >= i && l <= j) {
					in.push_back(a[l]);
				} else {
					out.push_back(a[l]);
				}
			}
			sort(in.begin(), in.end());
			sort(out.begin(), out.end());
			reverse(out.begin(), out.end());
			int sum = 0;
			for (int l = 0; l < (int)in.size(); ++l) {
				sum += in[l];
			}
			for (int e = 0; e <= k && e <= in.size() && e <= out.size(); ++ e) {
				int tmp = sum;
				for (int l = 0; l < e; ++l) {
					tmp -= in[l];
					tmp += out[l];
				}
				ans = max(ans, tmp);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}