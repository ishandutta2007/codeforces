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
		string a, b;
		cin >> a >> b;
		sort(a.begin(), a.end());

		bool ok=0;
		for(int i=0; i+a.size()<=b.size(); ++i) {
			string c=b.substr(i, a.size());
			sort(c.begin(), c.end());
			if(a==c)
				ok=1;
		}
		cout << (ok?"YES":"NO") << "\n";
	}
}