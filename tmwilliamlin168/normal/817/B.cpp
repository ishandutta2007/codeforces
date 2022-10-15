#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	int c=1+(a[2]==a[1])+(a[2]==a[0]), d=upper_bound(a, a+n, a[2])-lower_bound(a, a+n, a[2]);
	ll b=1;
	for(int i=1; i<=c; ++i)
		b*=(d-i+1);
	for(int i=1; i<=c; ++i)
		b/=i;
	cout << b;
}