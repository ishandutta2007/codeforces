#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[3];
	for(int i=0; i<3; ++i)
		cin >> a[i];
	int d;
	cin >> d;
	sort(a, a+3);
	cout << d-min(a[1]-a[0], d)+d-min(a[2]-a[1], d);
}