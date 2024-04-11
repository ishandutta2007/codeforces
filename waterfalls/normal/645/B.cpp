#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,k;
	cin >> n >> k;
	k = min(k,n/2);
	cout << n*(n-1)/2-(n-2*k)*(n-2*k-1)/2;

    return 0;
}