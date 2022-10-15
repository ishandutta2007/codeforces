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
		int n, d;
		cin >> n >> d;
		int l=d, ans=d;
		for(int i=1; i<min(d, 100000); ++i) {
			if(l>i+(d+i)/(i+1)) {
				l=i+(d+i)/(i+1);
			}
		}
		cout << (l<=n?"YES":"NO") << "\n";
	}
}