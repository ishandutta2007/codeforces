#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3 * 100000;
int n;
vector<pair<int, int> > v;
long long sum[N + 1];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		v.push_back(make_pair(p, i));
	}
	sort(v.begin(), v.end());
	sum[0] = 0;
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + v[i].first;
	}
	int k;
	scanf("%d", &k);
	long long ans = 1ll << 61;
	int cntx = 0;
	long long cur = 0;
	for (int i = 1; i < k; ++i) {
		cur += v[i].first * i - (sum[i] - sum[0]);
	}
	ans = cur;
	for (int i = 0; i + k < n; ++i) {
		cur -= (sum[i + k] - sum[i + 1]) - (long long)v[i].first * (k - 1);	
		cur += (long long)v[i + k].first * (k - 1) - (sum[i + k] - sum[i + 1]);
		if (cur < ans) {
			cntx = i + 1;
			ans = cur;
		}
	}
	for (int i = 0; i < k; ++i) {
		printf("%d%c", v[i + cntx].second + 1, " \n"[i == k - 1]);
	}
	return 0;
}