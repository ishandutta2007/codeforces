#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	long long x, y;
	cin >> x >> y;
	--x, --y;
	vector<pair<long long, char> > ans;
	while (true) {
		if (x > y) {
			ans.push_back(make_pair(x / (y + 1), 'A'));
			x %= (y + 1);
		} else if (y > x) {
			ans.push_back(make_pair(y / (x + 1), 'B'));
			y %= (x + 1);
		} else {
			if (x == 0) {
				break;
			} else {
				puts("Impossible");
				return 0;
			}
		}
	}
	for (int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i].first << ans[i].second;
	}
	cout << endl;
	return 0;
}