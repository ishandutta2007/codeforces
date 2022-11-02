#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	while (b--) {
		a = -a;
		--a;
		a = -a;
	}
	cout << a ;
	return 0;
}