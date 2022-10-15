#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a;
		for(int i=0; i<n; ++i) {
			int ai;
			cin >> ai;
			a.push_back(ai);
		}
		bool ok=0;
		for(int i=0; i<n-1&&!ok; ++i) {
			if(abs(a[i]-a[i+1])>1) {
				ok=1;
				cout << "YES\n";
				cout << i+1 << " " << i+2 << "\n";
			}
		}
		if(!ok)
			cout << "NO\n";
	}
}