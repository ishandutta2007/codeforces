#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#define ff first
#define ss second
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	map<int, vector<cat> > M;
	vector<cat> A(N), T(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		M[A[i]] = {};
	}
	for(int i = 0; i < N; i++) {
		cin >> T[i];
		M[A[i]].push_back(T[i]);
	}
	cat ans = 0, sum = 0, cur = 0;
	multiset<cat> S;
	for(auto [val, vt] : M) {
		while(!S.empty() && cur < val) {
			sum -= *rbegin(S);
			ans += sum;
			S.erase(--end(S));
			cur++;
		}
		if(cur < val) cur = val;
		for(auto x : vt) {
			sum += x;
			S.insert(x);
		}
		sum -= *rbegin(S);
		ans += sum;
		S.erase(--end(S));
		cur++;
	}
	while(!S.empty()) {
		sum -= *rbegin(S);
		ans += sum;
		S.erase(--end(S));
	}
	cout << ans << "\n";
}