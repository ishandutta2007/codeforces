#include<bits/stdc++.h>
using namespace std;
bool check(int x) {
	for(int i(2); i * i <= x; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	if(check(n)) {
		cout << 1 << endl;
	}else if(n % 2 == 0) {
		cout << 2 << endl;
	}else {
		if(check(n - 2)) {
			cout << 2 << endl;
		}else {
			cout << 3 << endl;
		}
	}
}