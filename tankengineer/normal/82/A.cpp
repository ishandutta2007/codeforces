#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

const char *name[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main() {
	long long n, a;
	cin >> n;
	--n;
	a = 1;
	while (n >= a * 5) {
		n -= a * 5;
		a *= 2;
	}
	cout << name[n / a] << endl;
	return 0;
}