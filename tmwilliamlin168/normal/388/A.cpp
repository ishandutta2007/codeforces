#include <bits/stdc++.h>
using namespace std;

int n, a[100];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	pq.push(1);
	for(int i=1; i<n; ++i) {
		if(pq.top()<=a[i]) {
			pq.push(pq.top()+1);
			pq.pop();
		} else
			pq.push(1);
	}
	cout << pq.size();
}