#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, q, aa[mxN], ab[mxN];
deque<int> d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(int i=0, a; i<n; ++i) {
		cin >> a;
		d.push_back(a);
	}
	for(int i=0; i<n; ++i) {
		aa[i]=d.front();
		d.pop_front();
		ab[i]=d.front();
		d.pop_front();
		if(aa[i]>ab[i]) {
			d.push_front(aa[i]);
			d.push_back(ab[i]);
		} else {
			d.push_front(ab[i]);
			d.push_back(aa[i]);
		}
	}
	while(q--) {
		ll m;
		cin >> m;
		if(m<=n)
			cout << aa[m-1] << " " << ab[m-1] << "\n";
		else
			cout << aa[n-1] << " " << d[(m-n-1)%(n-1)+1] << "\n";
	}
}