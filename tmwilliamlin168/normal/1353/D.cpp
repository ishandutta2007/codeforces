#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		priority_queue<ar<int, 2>> pq;
		int b=0;
		pq.push({n, 0});
		while(pq.size()) {
			ar<int, 2> u=pq.top();
			pq.pop();
			if(!u[0])
				continue;
			a[-u[1]+(u[0]-1)/2]=++b;
			pq.push({(u[0]-1)/2, u[1]});
			pq.push({u[0]/2, -(-u[1]+(u[0]-1)/2+1)});
		}
		for(int i=0; i<n; ++i)
			cout << a[i] << " ";
		cout << "\n";
	}
}