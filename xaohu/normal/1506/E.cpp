#include <bits/stdc++.h>

using namespace std;

int t, n, q[222000], a[222000], b[222000];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> q[i];
		set<int> A, B;
		for (int i = 1; i <= n; i++) {
			for (int j = q[i - 1] + 1; j < q[i]; j++) {
				A.insert(j); 
				B.insert(j);
			}
			if (q[i - 1] < q[i]) 
				a[i] = b[i] = q[i];
			else {
				a[i] = *A.begin();
				b[i] = *B.rbegin();
				A.erase(a[i]);
				B.erase(b[i]);
			}
		}
		for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
		for (int i = 1; i <= n; i++) cout << b[i] << " "; cout << "\n";
	}
	
	return 0;					
}