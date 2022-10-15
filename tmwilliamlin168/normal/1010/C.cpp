#include <bits/stdc++.h>
using namespace std;

int n, k, b, a[100000];

inline int gcd(int a, int b) {
	while((a%=b)&&(b%=a));
	return a^b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	b=k;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		b=gcd(b, a[i]);
	}
	cout << k/b << "\n";
	for(int i=0; i<k; i+=b)
		cout << i << " ";
}