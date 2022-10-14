#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int &i : a) {
		cin >> i;
	}
	
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i : a) {
		pq.push(i);
	}
	
	while(k > 0) {
		int res = pq.top();
		pq.pop();
		res = -res;
		pq.push(res);
		--k;
	}
	long long ans =0;
	for(; int(pq.size()) > 0; ) {
		ans += pq.top();
		pq.pop();
	}
	
	cout << ans << "\n";
	
	
	
}