#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 400005, INF = 1000000000 + 1;

int n, m;

int a[N], pre[N], suf[N];

int cnt[N];

bool mark[N];

int p[N], v[N], ord[N];

bool byP(const int &i, const int &j) {
	return p[i] < p[j];
}

int ansp[N], anss[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	vector<int> tmp;
	tmp.push_back(0);
	for (int i = 0; i < n; ++i) {
		pre[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
		if (tmp.size() == pre[i]) {
			tmp.push_back(a[i]);
		} else {
			tmp[pre[i]] = min(tmp[pre[i]], a[i]);
		}
	}
	tmp.clear();
	tmp.push_back(-INF);
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = lower_bound(tmp.begin(), tmp.end(), -a[i]) - tmp.begin();
		if (tmp.size() == suf[i]) {
			tmp.push_back(-a[i]);
		} else {
			tmp[suf[i]] = min(tmp[suf[i]], -a[i]);
		}
	}
	int maxs = 0;
	for (int i = 0; i < n; ++i) {
		maxs = max(maxs, pre[i] + suf[i] - 1);
	}
	for (int i = 0; i < n; ++i) {
		if (pre[i] + suf[i] - 1 == maxs) {
			++cnt[pre[i]];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (pre[i] + suf[i] - 1 == maxs && cnt[pre[i]] == 1) {
			mark[i] = true;
		}
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", p + i, v + i);	
		--p[i];
		ord[i] = i;
	}
	sort(ord, ord + m, byP);
	int pp = 0;
	tmp.clear();
	tmp.push_back(0);
	for (int i = 0; i < n; ++i) {
		while (pp < m && p[ord[pp]] == i) {
			ansp[ord[pp]] = lower_bound(tmp.begin(), tmp.end(), v[ord[pp]]) - tmp.begin();
			++pp;
		}
		if (tmp.size() == pre[i]) {
			tmp.push_back(a[i]);
		} else {
			tmp[pre[i]] = min(tmp[pre[i]], a[i]);
		}
	}
	tmp.clear();
	tmp.push_back(-INF);
	pp = m - 1;
	for (int i = n - 1; i >= 0; --i) {
		while (pp >= 0 && p[ord[pp]] == i) {
			anss[ord[pp]] = lower_bound(tmp.begin(), tmp.end(), -v[ord[pp]]) - tmp.begin();
			--pp;
		}
		if (tmp.size() == suf[i]) {
			tmp.push_back(-a[i]);
		} else {
			tmp[suf[i]] = min(tmp[suf[i]], -a[i]);
		}
	}
	for (int i = 0; i < m; ++i) {
		int nlen = ansp[i] + anss[i] - 1;
		int olen = mark[p[i]] ? maxs - 1 : maxs;
		printf("%d\n", max(nlen, olen));
	}
	return 0;
}