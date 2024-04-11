#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
//	int t; cin >> t;
	int t = 1;
	
	while(t--) {
		long long n, k, x, y;
		cin >> n >> k >> x >> y;
		
		if(k == 1) {
			cout << (n - 1) * x;
		} else {
			long long cost = 0;
			while(n > 1) {
				// always better
				if( n < k) {
					cost += (n - 1) * x;
					n = 1;
				} else if(n > k && !(n % k == 0)) {
					long long next = (n / k) * k;
					cost += (n - next) * x;
					n = next;
					
				} else if(n % k == 0) {
					long long next = n / k;
					if(y < (n - next) * x) {
						cost += y;
						n = next;
					} else {
						cost += (n - next) * x;
						n = next;
					}
				}
				
//				cout << n << "\n";
			}
			cout << cost << "\n";
		}
	}
	
}