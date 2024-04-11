#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int n, k;

vector<pair<int, int> > evt, ans;

enum {LEFT = -1, RIGHT = 1};

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		evt.push_back(make_pair(l, LEFT));
		evt.push_back(make_pair(r, RIGHT));
	}
	sort(evt.begin(), evt.end());
	int cnt = 0, last;
	for (int i = 0; i < (int)evt.size(); ++i) {
		int pos = evt[i].first, delta = evt[i].second;
		if (delta == LEFT) {
		   if (cnt + 1 == k) {
			   last = pos;
		   }
		   cnt += 1;
		}
		if (delta == RIGHT) {
		   if (cnt == k) {
			   ans.push_back(make_pair(last, pos));
		   }
		   cnt -= 1;
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}