#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, mx = -1;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		mx = max(x, mx);
	}
	cout << mx;
}