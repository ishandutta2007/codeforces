#include <bits/stdc++.h>
using namespace std;

const int n=1e7;

bool lit[n];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k1, k2, k3, i;
	cin >> k1 >> k2 >> k3;
	if(k2>k3)
	    swap(k2, k3);
	if(k1==1||k2==1||k3==1) {
		cout << "YES";
		return 0;
	}
	for(i=0; i<n; i+=k1)
		lit[i]=true;
	for(i=1; i<n; i+=k2)
		lit[i]=true;
	for(i=2; i<n&&lit[i]; ++i);
	if(i>=n) {
		cout << "YES";
		return 0;
	}
	for(; i<n; i+=k3)
		lit[i]=true;
	for(int i=0; i<n; ++i) {
		if(!lit[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}