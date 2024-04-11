#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	cin >> n;
	long long ans(0), a(1), b(1);
	for(;;) {
		if(n < b) {
			ans--;
			break;
		}else {
			a += b;
			swap(a, b);
			ans++;
		}
	}
	cout << ans << endl;
}