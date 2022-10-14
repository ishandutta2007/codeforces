// This code was made on 10/8/2020 by Dwight Thompson

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int a[3], b[3];
	for(int i = 0; i < 3; i++) cin >> a[i];
	for(int i = 0; i < 3; i++) cin >> b[i];
	int mx = min(a[0], b[1]) + min(a[1],  b[2]) + min(a[2], b[0]);
	int mn = max(0, a[0] + b[1] - N) + max(0, a[1] + b[2] - N) + max(0, a[2] + b[0]-N);
	cout << mn << " " << mx;


	return 0;
}