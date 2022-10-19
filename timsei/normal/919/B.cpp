#include <bits/stdc++.h>
using namespace std;

const int N = 2e7 + 5;

int n , m , k , B[N] , p;

int main(void) {
	cin >> k;
	B[0] = 0;
	for(int i = 1;i <= 20000000; ++ i) {
		B[i] = B[i / 10] + i % 10;
		if(B[i] == 10) {
			++ p;
			if(p == k) {
				cout << i << endl;
				return 0;
			}
		}
	}
}