#include <iostream>
#include <cmath>
using namespace std;

bool aretwoprimes(int a, long long b);

int main() 
{
	long long X;
	cin >> X;
	
	int j;
	for (int i = sqrt(X); i > 0; --i) {
		if (X % i) continue;
		if (aretwoprimes(i, X / i)) {
			cout << i << ' ' << X / i << '\n';
			return 0;
		}
	}
	return 0;
}

bool aretwoprimes(int a, long long b) 
{
	if (!(b % a) && a != 1) return false;
	int i;
	for (i = 2; i <= sqrt(a) && ((a % i) || (b % i)); ++i);
	if (!(a % i || b % i)) return false;
	return true;
}