#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool tr(int x) {
	int d=0;
	while(x) {
		d+=x%10;
		x/=10;
	}
	return d%4==0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	while(!tr(n))
		++n;
	cout << n;
}