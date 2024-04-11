#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
ll m, k, x, y;
ll f1[100005];
string s;
int n, q, p, r, t, i, u, v;
ll a[100005];
int query(int p, int q) {
// 	cout << "QUERYING: ";
	cout << "? " << p  << " " << q << endl;
	int x; cin >> x;
	
	return x;
}

bool rC(int x, int y) {
	return y>=x;
}
void solve() {
	cin >> n;

	int lb = 1, rb = n;

	while(rb - lb > 1) {
		int mid=(lb+rb)/2;

		int range=query(lb, rb);

		bool b = rC(mid, range);
		int qu=-1;
		if(b) {
			qu=query(mid, rb);
		} else {
			qu=query(lb, mid);
		}
		if(b){
			if(qu == range) {
				lb = mid;
			} else {
				rb = mid;
			}
		} else {
			if(qu == range) {
				rb = mid;
			} else {
				lb = mid;
			}
		}
	}

	int x=query(lb, rb);
	// cout << lb << " " << rb << endl;
	if(x==lb) {
		cout << "! " << rb << endl;
	} else {
		cout << "! " << lb << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; //cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		// cout << "Case #" << case_num << ": ";
		solve();
	}
}