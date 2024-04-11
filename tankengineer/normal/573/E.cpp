#include<cassert>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int BN = 505;

bool convex(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

struct Block {
	vector<pair<long long, long long> > v;

	vector<pair<long long, long long> > con;

	int pt;
	
	long long cnt, sum;

	Block() {
		cnt = sum = 0;
	}

	void build() {
		if (v.size() == 0) {
			return;
		}
		vector<pair<long long, long long> > tmp = v;
		sort(tmp.begin(), tmp.end());
		con.clear();
		for (int i = 0; i < (int)tmp.size(); ++i) {
			while (con.size() > 1 && !convex(con[con.size() - 2], con[con.size() - 1], tmp[i])) {
				con.pop_back();
			}
			con.push_back(tmp[i]);
		}
		pt = 0;
	}

	long long ask(long long x, long long suf) {
		if (v.size() == 0) {
			return 0;
		}
		while (pt + 1 < con.size() && con[pt].first * x + con[pt].second <= con[pt + 1].first * x + con[pt + 1].second) {
			++pt;
		}
		return con[pt].first * x + con[pt].second + suf;
	}

	void extract() {
		int pos = find(v.begin(), v.end(), con[pt]) - v.begin();
		for (int i = 0; i < pos; ++i) {
			v[i].second += v[pos].first;
		}
		for (int i = pos + 1; i < v.size(); ++i) {
			v[i].second += v[i].first;
		}
		sum += v[pos].first;
		++cnt;
		v.erase(v.begin() + pos);
		build();
	}

} block[BN];

int n, bSize, bn;

int main() {
	scanf("%d", &n);
	bSize = max((int)sqrt(n), 10);
	bn = (n + bSize - 1) / bSize;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		block[i / bSize].v.push_back(make_pair(a, a));
	}
	for (int i = 0; i < bn; ++i) {
		block[i].build();
	}
	long long ans = 0;
	while (true) {
		long long maxs = 0;
		int cx = -1;
		long long x = 0, suf = 0;
		for (int i = bn - 1; i >= 0; --i) {
			suf += block[i].sum;
		}
		for (int i = 0; i < bn; ++i) {
			suf -= block[i].sum;
			long long tmp = block[i].ask(x, suf);
			if (tmp > maxs) {
				maxs = tmp;
				cx = i;
			}
			x += block[i].cnt;
		}
		if (cx != -1) {
			ans += maxs;
			block[cx].extract();
		} else {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}