#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	int x = 1;
	if (n % 2 == 1) {
	 	x *= -1;
	}
	n += n % 2;
	n /= 2;    
	cout << n * x;       
}