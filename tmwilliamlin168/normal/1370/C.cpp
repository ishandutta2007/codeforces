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
		if(n==1) {
			cout << "FastestFinger\n";
		} else if(n%2==1) {
			cout << "Ashishgup\n";
		} else {
			//cout << "FastestFinger\n";
			if(n%4==0) {
				if(__builtin_popcount(n)>1) {
					cout << "Ashishgup\n";
				} else {
					cout << "FastestFinger\n";
				}
			} else {
				int x=0;
				for(int i=2; i*i<=n; ++i) {
					if(n%i)
						continue;
					while(n%i==0) {
						++x;
						n/=i;
					}
				}
				if(n>1)
					++x;
				if(x^2)
					cout << "Ashishgup\n";
				else
					cout << "FastestFinger\n";
			}
		}
	}
}