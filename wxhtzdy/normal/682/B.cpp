#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int mex = 1;
	for(int i = 0; i < n; i++) {
		if(mex <= a[i])mex++;
		else mex = min(mex, a[i] + 1);
	}
	cout << mex << '\n';
}