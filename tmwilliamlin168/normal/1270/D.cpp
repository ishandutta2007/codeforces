#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	for(int i=0; i<k+1; ++i) {
		cout << "? ";
		for(int j=0; j<k; ++j)
			cout << (i+j)%(k+1)+1 << " ";
		cout << endl;
		int a, b;
		cin >> a >> b;
		++mp[b];
	}
	cout << "! " << k-(mp.begin()->second)+1;
}