#include<deque>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int d, n, m;

int main() {
	scanf("%d%d%d", &d, &n, &m);
	vector<pair<int, int> > stations(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &stations[i].first, &stations[i].second);
	}
	sort(stations.begin(), stations.end());
	int cur = n, nxt = 0, last = -1;
	long long ans = 0;
	deque<int> q;
	while (cur < d) {
		if (nxt < m && cur >= stations[nxt].first) {
			while (q.size() && stations[q.back()].second >= stations[nxt].second) {
				q.pop_back();
			}
			if (q.size() == 0) {
				last = cur - stations[nxt].first;
			}
			q.push_back(nxt++);
		} else {
			int target = nxt < m ? stations[nxt].first : d;
			int toAdd = target - cur;
			while (toAdd) {
				if (q.size() == 0) {
					printf("-1\n");
					return 0;
				}
				int delta = min(toAdd, n - last);
				ans += (long long)delta * stations[q.front()].second;
				toAdd -= delta;
				last += delta;
				cur += delta;
				if (last == n) {
					q.pop_front();
					if (q.size()) {
						last = cur - stations[q.front()].first;
					} else {
						last = -1;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}