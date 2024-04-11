#include<bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		long long n;
		cin >> n;
		long long ans = 0;
		for(int i = 1; i <= n / 2; i++) {
			ans += pow(2,i);
		}
		cout << ans << endl;
	}
}