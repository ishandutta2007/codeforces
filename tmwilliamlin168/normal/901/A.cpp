#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int h;
	cin >> h;
	int *a = new int[h+1];
	for(int i=0; i<=h; ++i)
		cin >> a[i];
	bool ok=true;
	for(int i=0; i<h; ++i) {
		if(a[i]>1&&a[i+1]>1) {
			ok=false;
			break;
		}
	}
	if(ok) {
		cout << "perfect";
		return 0;
	}
	cout << "ambiguous\n0 ";
	int u=1;
	for(int i=1; i<=h; ++i) {
		for(int j=0; j<a[i]; ++j)
			cout << u << " ";
		u+=a[i];
	}
	cout << "\n0 ";
	u=1;
	for(int i=1; i<=h; ++i) {
		for(int j=0; j<a[i]; ++j)
			cout << (!j&&a[i-1]>1&&a[i]>1?u-1:u) << " ";
		u+=a[i];
	}
}