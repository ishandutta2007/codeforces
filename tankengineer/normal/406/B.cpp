#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005;
bool take[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int c;
		scanf("%d", &c);
		take[c] = true;
	}
	vector<pair<int, int> > pairs;
	int cntpairs = 0;
	vector<int> ans;
	for (int i = 1; i * 2 <= 1000000; ++i) {
		if (take[i] && take[1000000 - i + 1]) {
			++cntpairs;
		} else if (take[i]) {
			ans.push_back(1000000 - i + 1);
		} else if (take[1000000 - i + 1]) {
			ans.push_back(i);
		} else {
			pairs.push_back(make_pair(i, 1000000 - i + 1));
		}
	}
	for (int i = 0; i < cntpairs; ++i) {
		ans.push_back(pairs[i].first);
		ans.push_back(pairs[i].second);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}