#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n, x;
	cin >> n;
	x = n;
	int c = 0;
	long long a = 1;
	for(int i(2); (long long)i * i <= n; i++) {
		if(x % i == 0) {
			c++;
			while(x % i == 0) x /= i;
			a = i;
		}
	}
	if(x != 1) {
		c++; 
		a = x;
	}
	cout << (c == 0 ? 1ll : c == 1 ? a : 1ll) << endl;
}