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
		if(a==b)
			cout << "0\n";
		else if((a&1)^(b&1)&&a<b)
			cout << "1\n";
		else if((a&1)==(b&1)&&a>b)
			cout << "1\n";
		else
			cout << "2\n";
	}
}