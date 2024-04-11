#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ar array
int test_cases;
struct cmp {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
		int x = a.second - a.first;
		int y = b.second - b.first;
		
		if(x == y) return a.first < b.first;
		return x > y;
	}
};
void solve() {
	int n; cin >> n;
	vector<int> ans(n);
	int dep=0;
	set<pair<int, int>,cmp> st;
	
	st.insert({0,n-1});
	
	for(int i = 0; i < n; i++) {
		auto u = *st.begin();
		st.erase(u);
		int mid=(u.first+u.second)/2;
		vector<pair<int, int>> s;
		if(mid-1>=u.first) s.push_back({u.first,mid-1});
		if(mid+1<=u.second) s.push_back({mid+1,u.second});
		for(auto x : s) st.insert(x);
		ans[mid]=++dep;
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}
int main() {	
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> test_cases;
	
	for(int tc = 0; tc < test_cases; tc++) {
        solve(); 
	}
}