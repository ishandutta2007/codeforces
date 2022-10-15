#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	if(k==1)
		cout << n;
	else {
		n|=n>>1;
		n|=n>>2;
		n|=n>>4;
		n|=n>>8;
		n|=n>>16;
		n|=n>>32;
		cout << n;
	}
}