#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3005;
const double pi = acos(-1), eps = 1e-9;
int n;
pair<int, int> p[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		vector<pair<double, int> > v;
		for (int j = 0; j < n; ++j) {
			if (p[j] == p[i]) {
				continue;
			}
			int x = p[j].first - p[i].first, y = p[j].second - p[i].second;
			v.push_back(make_pair(atan2((double)y, (double)x), x * x + y * y));
		}
		sort(v.begin(), v.end());	
		for (int i = 0; i < v.size(); ++i) {
			if (v[i].first < eps) {
				v.push_back(make_pair(v[i].first + pi * 2, v[i].second));
			}
		}
		int p60 = -1;
		priority_queue<pair<int, double> > heap;
		for (int j = 0; j < (int)v.size(); ++j) {
			while (p60 + 1 < v.size() && v[j].first - v[p60 + 1].first > pi / 3 - eps) {
				++p60;
				heap.push(make_pair(v[p60].second, v[p60].first));
			}
			while (heap.size() && v[j].first - heap.top().second > pi + eps) {
				heap.pop();
			}
			if (heap.size()) {
				ans = max(ans, min(v[j].second, heap.top().first));
			}
		}
	}
	printf("%.12lf\n", sqrt((double)ans) / 2);
	return 0;
}