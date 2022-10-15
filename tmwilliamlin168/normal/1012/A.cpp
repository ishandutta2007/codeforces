#include <bits/stdc++.h>
using namespace std;

long long a[200000], b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=0; i<2*n; ++i)
		cin >> a[i];
	sort(a, a+2*n);
	b=(a[n-1]-a[0])*(a[2*n-1]-a[n]);
	for(int i=1; i<n; ++i)
		b=min((a[n+i-1]-a[i])*(a[2*n-1]-a[0]), b);
	cout << b;
}