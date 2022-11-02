#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2 * 100000;
int n;
long long target;
long long f[N], g[N];

vector<pair<long long, long long> > b;

long long cal(long long cur_time, long long cur_money, long long growth, long long target) {
	if (cur_money >= target) {
		return cur_time + 1;
	}
	long long gap = target - cur_money;
	return cur_time + (gap + growth - 1) / growth;
}

bool check(int i, int j, long long target) {
	long long t1 = cal(f[i], g[i], b[i].second, target), 
			  t2 = cal(f[j], g[j], b[j].second, target);
	if (t1 != t2) {
		return t1 > t2;
	}
	long long g1 = (t1 - f[i]) * b[i].second + g[i] - target,
			  g2 = (t2 - f[j]) * b[j].second + g[j] - target;
	return g1 <= g2;
}

bool check2(int i, int j, int k) {
	
	return (g[i] + b[i].second * (f[j] - f[i]) - g[j]) * (b[k].second - b[j].second) + f[j] * (b[j].second - b[i].second) * (b[k].second - b[j].second) >= (g[j] + b[j].second * (f[k] - f[j]) - g[k]) * (b[j].second - b[i].second) + f[k] * (b[j].second - b[i].second) * (b[k].second - b[j].second);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> target;
	vector<pair<int, int> > tmp;
	for (int i = 0; i < n; ++i) {
		int v, c;
		cin >> v >> c;
		tmp.push_back(make_pair(c, v));
	}
	sort(tmp.begin(), tmp.end());
	int cur_max = -1;
	for (int i = 0; i < (int)tmp.size(); ++i) {
		if (tmp[i].first >= target) {
			continue;
		}
		int j = i;
		while (j < (int)tmp.size() && tmp[j].first == tmp[i].first) {
			++j;
		}
		i = j - 1;
		if (tmp[i].second > cur_max) {
			b.push_back(tmp[i]);
			cur_max = tmp[i].second;
		}
	}
	n = b.size();
	f[0] = 0;
	g[0] = 0;
	long long ans = cal(0, 0, b[0].second, target);
	deque<int> q;
	q.push_back(0);
	for (int i = 1; i < n; ++i) {
		f[i] = 1ll << 62;
		while (q.size() > 1 && check(q[0], q[1], b[i].first)) {
			q.pop_front();
		}
		int j = q.front();
		f[i] = cal(f[j], g[j], b[j].second, b[i].first);
		g[i] = (g[j] + b[j].second * (f[i] - f[j]) - b[i].first);
		ans = min(ans, f[i] + (target - g[i] + b[i].second - 1) / b[i].second);
		if (i < n - 1) {
			while (q.size() > 1 && check2(q[q.size() - 2], q[q.size() - 1], i)) {
				q.pop_back();
			}
			q.push_back(i);
		}
	}
	cout << ans << endl;
	return 0;
}