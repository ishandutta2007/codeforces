// This code was made on 10/8/2020 by Dwight Thompson

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	set<int> vals;
	for(int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		vals.insert(a);
	}
	cout << 4-vals.size();
	return 0;
}