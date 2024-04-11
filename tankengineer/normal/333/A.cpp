#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;
	while (n % 3 == 0) n /= 3;
	if (n % 3 == 1) {
		n += 2;
	} else {
		n += 1;
	}
	n /= 3;
	cout << n << endl;
	return 0;
}