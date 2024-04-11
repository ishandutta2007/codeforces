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
		int a, b;
		cin >> a >> b;
		if(a>b)
			swap(a, b);
		int x=0, pd=(a^b)&1;
		while(a<b||pd) {
			++x;
			a+=x;
			pd^=x&1;
		}
		cout << x << "\n";
	}
}