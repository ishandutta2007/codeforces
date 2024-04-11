#include <iostream>
using namespace std;

long long max_amount(long long n);

int main() 
{
	int t;
	long long n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << max_amount(n) << '\n';
	}
	return 0;
}

long long max_amount(long long n) 
{
	int total = n;
	while (n >= 10) {
		total += n / 10;
		n = n / 10 + n % 10;
	}
	return total;
}