#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
	cin >> t;
	while(t--) {
		ll s, a, b, c;
		cin >> s >> a >> b >> c;
		cout << s/c+s/c/a*b << "\n";
	}
}