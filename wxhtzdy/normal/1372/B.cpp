#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
	 	long long n;
	 	cin >> n;
	 	long long ans = n;
	 	pair<long long, long long> p;
	 	p.first = 1;
	 	p.second = n - 1;
	 	for (long long i = 2; i <= sqrt(n); i++) {
	 		if (n % i != 0) {
	 		 	continue; 
	 		}
	 	 	long long curr = min(ans, (long long) (n / i * (n - n / i)) / __gcd(n / i, n - (n / i)));
	 	 	if (curr < ans) {
	 	 	 	ans = curr;
	 	 	 	p.first = n / i;
	 	 	 	p.second = n - n / i;
	 	 	}
	 	}
	 	cout << p.first << " " << p.second << endl;                   
	}
}