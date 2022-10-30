#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

const int N = 200005;
int n, q, a[N], l[N], r[N], hash[1000005], block;
long long sum, ans[N];

void insert(const int l, const int r) {
//cout << l << ' ' << r << endl;
	if (l < r) {
		for (int i = l; i < r; ++i) {
			sum -= (long long)a[i] * hash[a[i]] * hash[a[i]];
			++hash[a[i]];
			sum += (long long)a[i] * hash[a[i]] * hash[a[i]];
		}
	} else if (l > r) {
		for (int i = r; i < l; ++i) {
			sum -= (long long)a[i] * hash[a[i]] * hash[a[i]];
			--hash[a[i]];
			sum += (long long)a[i] * hash[a[i]] * hash[a[i]];
		}
	}
}

bool cmp(const int i, const int j) {
	if (l[i] / block != l[j] / block) {
		return l[i] < l[j];
	} else {
		return r[i] < r[j];
	}
}

int main() {
	scanf("%d%d", &n, &q);
	block = (int)sqrt((double)n + 5);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	vector<int> query;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", l + i, r + i);
		--l[i];
		query.push_back(i);
	}
	sort(query.begin(), query.end(), cmp);
	int nowl = 0, nowr = 0;
	for (int i = 0; i < query.size(); ++i) {
		insert(l[query[i]], nowl);
		insert(nowr, r[query[i]]);
		nowl = l[query[i]];
		nowr = r[query[i]];
		ans[query[i]] = sum;
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}