#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define vt(i) vector<i>
#define PB push_back
#define uset unordered_set

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	cin >> n;
	pair<int, int> b[n];
	for(int i = 0; i < n; i++) {
		int A; cin >> A;
		b[i].first = A-1;
		b[i].second = i;
	}
	vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		ans[b[i].first] = b[i].second + 1;
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}