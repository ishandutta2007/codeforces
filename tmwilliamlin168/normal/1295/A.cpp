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
		if(n%2==1) {
			n-=3;
			cout << 7;
		}
		for(int i=0; i<n; i+=2)
			cout << 1;
		cout << "\n";
	}
}