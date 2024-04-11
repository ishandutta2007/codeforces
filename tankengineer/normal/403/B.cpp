#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int NN = 100005;
vector<int> p;
bool notp[NN];

void init() {
	for (int i = 2; i < NN; ++i) {
		if (!notp[i]) {
			p.push_back(i);
			for (long long j = (long long)i * i; j < NN; j += i) {
				notp[j] = true;
			}
		}
	}
}

set<int> bad;

int cal(int n) {
	int ret = 0;
	for (int j = 0; j < (int)p.size() && (long long)p[j] * p[j] <= n; ++j) {
		if (n % p[j] == 0) {
			int cnt = 0;
			while (n % p[j] == 0) {
				n /= p[j];
				++cnt;
			}
			ret += (bad.count(p[j]) ? -1 : 1) * cnt;
		}
	}
	if (n != 1) {
		ret += bad.count(n) ? -1 : 1;
	}
	return ret;
}

const int N = 5005;
int n, m, a[N], g[N];

int main() {
	init();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		g[i] = i == 0 ? a[i] : __gcd(g[i - 1], a[i]);
	}
	for (int i = 0; i < m; ++i) {
		int b;
		scanf("%d", &b);
		bad.insert(b);
	}
	int div = 1, ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		g[i] /= div;
		if (cal(g[i]) < 0) {
			div *= g[i];
		}
		ans += cal(a[i] /= div);
	}
	/*
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", a[i], cal(a[i]));
	}
	*/
	printf("%d\n", ans);
	return 0;
}