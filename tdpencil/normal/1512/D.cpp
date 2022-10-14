
#include "bits/stdc++.h"

using namespace std;

#pragma GCC optimize("Ofast")
typedef long long ll;

void io(const string s="") {
	if(s != "") {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout);
	} else {
		ios_base::sync_with_stdio(false); cin.tie(0);
	}
}
ll pow(ll x, ll y) {
	if(y == 0)
		return 1;

	ll mid = pow(x, y / 2);
	if(y&1)
		return mid * mid * x;
	
	return mid * mid;
}
const int mxN = 2e5;

const long long mod = 1e9+7;

vector<int> test(vector<int> res, int val) {
	ll sum = accumulate(res.begin(), res.end(), 0LL);
	res.erase(find(res.begin(), res.end(), val));
	sum -= val;
	vector<int> t = res;
	for(auto i : t) {
		if(sum - i == val) {
			res.erase(find(res.begin(), res.end(), i));
			return res;
		}
	}

	return {-1};
}
void solve() {
	int n; cin >> n;
	vector<int> a(n+2);

	for(auto &i : a)
		cin >> i;


	sort(a.begin(), a.end());

	vector<int> f = test(a, a[n+1]);
	vector<int> s = test(a, a[n]);
	if(f != vector<int> {-1}) {
		for(auto &i : f)
			cout << i << " ";
		cout << "\n";
	} else if(s != vector<int> {-1}) {
		for(auto &i : s)
			cout << i << " " ;
		cout << "\n";
	} else {
		cout << -1 << "\n";
		return;
	}
}

int main() {
	
	
	io();
	int t = 1;
	cin >> t;
	

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) solve();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}