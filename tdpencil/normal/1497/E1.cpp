#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e7+1;
int lpf[mxN];

void sieve(int MAX_V) {
	for(int i = 2; i <= MAX_V; ++i) {
		if(lpf[i]) continue;
		lpf[i] = i;
		for(int j = 2 * i; j <= MAX_V; j += i) {
			lpf[j] = i;
		}
	}
}

vector<pair<int, int>> fac(int A) {
	map<int, int> cnt;
	vector<pair<int, int>> ans;
	
	while(A > 1) {
		++cnt[lpf[A]];
		A /= lpf[A];
	}
	
	for(auto &e : cnt) ans.push_back({e.first, e.second}); // val, freq
	return ans;
	
	
	
	
}

int setout(int X) {
	vector<pair<int, int>> a=fac(X);
	long long r = 1;
	for(auto &i : a) {
		if(i.second % 2 == 1) r *= i.first;
	}
	
	return r;
	
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(mxN - 1);
	int t; cin >> t;
	
	
	while(t--) {
		int n; cin >> n;
		int k; cin >> k;
		vector<int> a(n); for(auto &i : a) cin >> i;
		for(auto &i : a) {
			i = setout(i);
		}
		int ans = 1;
		
		set<int> s;
		for(auto &i : a) {
			if(s.count(i)) {
				++ans;
				s.clear();
				s.insert(i);
			} else {
				s.insert(i);
			}
		}
		
		cout << ans << "\n";
		
	}
	
}