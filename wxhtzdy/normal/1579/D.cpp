#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 500;

int A[N], n;

void solve(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++) scanf("%d", A + i);
	set<pair<int, int>> s;
	for(int i = 0;i < n;i++) if(A[i] > 0) s.insert({A[i], i});
	vector<pair<int, int>> ans;
	while(s.size() > 1){
		auto X = *prev(s.end());
		auto Y = *prev(prev(s.end()));
		ans.push_back({X.second, Y.second});
		s.erase(prev(s.end()));
		s.erase(prev(s.end()));
		if(X.first > 1)s.insert({X.first - 1, X.second});
		if(Y.first > 1)s.insert({Y.first - 1, Y.second});
	}
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++){
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
}

int main(){
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}