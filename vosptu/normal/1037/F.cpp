#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

#define P 1000000007

#define N 4100000
int ma[N], a[N], U;
int L[N], R[N], up[N];
int n;
int k;

struct Task {
	int l, r;
	Task(int _l, int _r) {
		l = _l;
		r = _r;
	}
};

vector <Task> tasks;

int calc(int x, int y) {
	if (a[x] > a[y])
		return x;
	else
		return y;
}

void mkt(int k, int l, int r) {
	if (l < r) {
		mkt(k * 2, l, (l + r) / 2);
		mkt(k * 2 + 1, (l + r) / 2 + 1, r);
		ma[k] = calc(ma[k * 2], ma[k * 2 + 1]);
	}else {
		ma[k] = l;
	}
}

int getmax(int k, int l, int r, int q, int h) {
	if (q <= l && r <= h)
		return ma[k];
	if (h <= (l + r) / 2)
		return getmax(k * 2, l, (l + r) / 2, q, h);
	if ((l + r) / 2 < q)
		return getmax(k * 2 + 1, (l + r) / 2 + 1, r, q, h);
	return calc(getmax(k * 2, l, (l + r) / 2, q, h), getmax(k * 2 + 1, (l + r) / 2 + 1, r, q, h));
}

int pp(int l) {
	if (!up[l])
		return 0;
	return
		1LL * (up[l] * k - up[l] + 1 - (l - 1) + U * k - U + 1 - (l - 1)) * (U - up[l] + 1) / 2 % P;
}

int calc2(int l, int r, int x) {
	long long ans = (pp(1) - pp(x - l + 2) - pp(r - x + 2) + pp(r - l + 3)) % P;
	ans = (ans + P) % P;
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	U = 1;
	while (U * k - U + 1 < n)
		U++;
	for (int i = 1; i <= k; i++)
		up[i] = 1;
	for (int i = 1; i < U; i++)
		for (int j = i * k - i + 2; j <= (i + 1) * k - (i + 1) + 1; j++)
			up[j] = i + 1;

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	mkt(1, 1, n);

	tasks.push_back(Task(1, n));
	for (int i = 0; i < (int) tasks.size(); i++) {
		Task t = tasks[i];
		if (t.l == t.r) {
			L[t.l] = R[t.l] = t.l;
		}else {
			int x = getmax(1, 1, n, t.l, t.r);
			L[x] = t.l;
			R[x] = t.r;
			if (L[x] < x)
				tasks.push_back(Task(L[x], x - 1));
			if (x < R[x])
				tasks.push_back(Task(x + 1, R[x]));
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + 1LL * a[i] * calc2(L[i], R[i], i) % P) % P;
	}
	printf("%d\n", ans);
}