#include <bits/stdc++.h>

using namespace std;

int main() {  
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
		 	cin >> a[i];
		}
		vector<int> v;	
		while (n > 0) {
			vector<bool> was(n, false);
			for (int i = 0; i < n; i++) {
			 	if (a[i] < n) {
			 		was[a[i]] = true;
			 	}	
			}
			int mex = 0;
			while (mex < n && was[mex] == true) {
			 	mex++;
			}
			if (mex == n) {
				v.push_back(n - 1);
				a[n - 1] = mex;
				n--;  
			} else {
			 	a[mex] = mex;
			 	v.push_back(mex);
			}
		}
		cout << (int) v.size() << endl;
		for (int i = 0; i < (int) v.size(); i++) {
		 	cout << v[i] + 1 << " ";	
  	}
  	cout << endl;
	}
}