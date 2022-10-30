#include <bits/stdc++.h>
using namespace std;

bool isprime(int x) {
	for (int i=2;i*i<=x;i++) {
		if (x%i==0) return false;
	}
	return true;
}

int n;

int main() {
	scanf("%d",&n);
	for (int m=1;m<=1000;m++) {
		if (!isprime(n*m+1)) {
			printf("%d\n",m);
			return 0;
		}
	}

	return 0;
}