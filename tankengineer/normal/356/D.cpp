#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

map<long long, int> cnt;

int n, s, last[70000 + 1], a[70000], ans[70000];
bool use[70000];

struct Bits {
	int n, l; 
	long long b[(70001 >> 5) + 1];

	Bits(int n) : n(n) {
		l = (n >> 5) + 1;
		memset(b, 0, sizeof(*b) * l);
	}

	void set(int i) {
		int t1 = i >> 5, t2 = i & 31;
		b[t1] |= 1ll << t2;
	}

	vector<int> ones() {
		vector<int> ret;
		for (int i = 0; i < l; ++i) {
			long long x = b[i] & ((1ll << 32) - 1), lb;
			while (x) {
				lb = x & -x;	
				x ^= lb;
				ret.push_back((i << 5) + cnt[lb]);
			}
		}
		while (ret.size() && ret.back() > n) {
			ret.pop_back();
		}
		return ret;
	}
};

Bits operator << (const Bits &a, int t) {
	Bits b(a.n);
	for (int i = 0; i < a.l; ++i) {
		int l = i + (t >> 5);
		if (l < b.l) {
			b.b[l] |= a.b[i] << (t & 31);
		}
		if (l + 1 < b.l) {
			b.b[l + 1] |= a.b[i] >> (32 - (t & 31));
		}
	}
	return b;
}

Bits& operator -= (Bits &a, const Bits &b) {
	for (int i = 0; i < a.l; ++i) {
		a.b[i] = a.b[i] & (~b.b[i]);
	}
	return a;
}

int main() {
	for (int i = 0; i < 32; ++i) {
		cnt[1ll << i] = i;
	}
	scanf("%d%d", &n, &s);
	vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		v.push_back(make_pair(a[i], i));	
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	if (s < v[0].first) {
		printf("-1\n");
		return 0;
	}
	s -= v[0].first;
	last[0] = -1;
	Bits bag(s), tmp(s);
	bag.set(0);
	for (int i = 1; i < n; ++i) {
		tmp = (bag << v[i].first);
		tmp -= bag;	
		vector<int> t = tmp.ones();
		for (int j = 0; j < (int)t.size(); ++j) {
			if (last[t[j] - v[i].first] == 0 || last[t[j] - v[i].first] >= i) {
				while (true) {
					int t = 1 + 1;
				}
			}
			last[t[j]] = i;
			bag.set(t[j]);
		}
	}
	if (last[s] == 0) {
		printf("-1\n");
		return 0;
	}
	int u = s;
	use[0] = true;
	while (u) {
		use[last[u]] = true;
		u -= v[last[u]].first;
	}
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < n; ++i) {
		if (!use[i]) {
			ans[v[i - 1].second] = v[i].second;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == -1) {
			printf("%d 0\n", a[i]);
		} else {
			printf("%d 1 %d\n", a[i] - a[ans[i]], ans[i] + 1);
		}
	}
	return 0;
}