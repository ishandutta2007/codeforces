#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string st;
	cin >> st;
	int ans(0);
	for(int i(0); i < n; i++) {
		if(st[i] == '<') {
			ans++;
		}else {
			break;
		}
	}
	for(int i(n - 1); i >= 0; i--) {
		if(st[i] == '>') {
			ans++;
		}else {
			break;
		}
	}
	cout << ans << endl;
}