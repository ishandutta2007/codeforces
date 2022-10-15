#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if(k > 4 * n * m - 2 * n - 2 * m) {
		printf("NO\n");
		return 0;
	}
	vector<pair<int, string> > ans, a1;
	for(int i(1); i <= n; i++) {
		if(m > 1) ans.push_back(make_pair(m - 1, (string)"R"));
		
		if(i < n) {
			ans.push_back(make_pair(1, (string)"D"));
			if(m > 1) ans.push_back(make_pair(m - 1, (string)("ULD")));
		}else {
			if(m > 1) ans.push_back(make_pair(m - 1, (string)"L"));
			if(n > 1) ans.push_back(make_pair(n - 1, (string)"U"));
		}

	}
	
	for(auto & tmp : ans) {
		if(tmp.first * tmp.second.size() <= k) {
			k -= tmp.first * tmp.second.size();
			a1.push_back(tmp);
		}else {
			int div = k / tmp.second.size();
			int rmn = k % tmp.second.size();
			if(div) a1.push_back(make_pair(div, tmp.second));
			if(rmn) a1.push_back(make_pair(1, tmp.second.substr(0, rmn)));
			break;
		}
	}
	ans = a1;
	printf("YES\n%d\n", (int)ans.size());
	for(int i = 0; i < (int)ans.size(); i++) printf("%d %s\n", ans[i].first, ans[i].second.c_str());

}