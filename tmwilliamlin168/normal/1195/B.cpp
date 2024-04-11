#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	ll x=0;
	int i=1;
	while(x<k) {
		x+=i++;
		--n;
	}
	while(n>x-k) {
		x+=i++;
		--n;
	}
	cout << n;
}