#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld",&n);
	long long num = 0;
	for (int i=1;i<2520;i++) {
		bool ok = 1;
		for (int j=2;j<=10;j++) if (i%j==0) ok = 0;
		if (ok) num+=(n+2520-i)/2520;
	}
	printf("%lld\n",num);

	return 0;
}