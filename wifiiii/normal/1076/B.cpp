#include <iostream>

typedef long long ll;
using namespace std;

int main() {
	ll n, cnt = 0;
	cin >> n;
	if(n%2==0) cnt = n/2;
	else {
		int val = 0;
		for(ll i=2;i*i<=2*n;++i) {
			if(n%i==0) {
				val = i;
				break;
			}
		}
		if(val) {
			cnt = (n-val) / 2 + 1;
		} else cnt = 1;
	}
	cout << cnt << endl;
}