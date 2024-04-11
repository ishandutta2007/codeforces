#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long cal(long long a, long long b) {
	if (a == 0) {
		return 0;
	}
	long long g = __gcd(a, b);
	a /= g;
	b /= g;
	if (a >= b) {
		return a / b + cal(a % b, b);
	} else {
		long long r = (b - 1) / a;
		return r + cal(a, b - a * r);
	}
}
int main() {
	long long a, b;
	cin >> a >> b;
	cout << cal(a, b) << endl;
	return 0;
}