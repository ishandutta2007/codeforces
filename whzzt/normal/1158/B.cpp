#include <bits/stdc++.h>
using namespace std;
int n, k;
string solve(int n, int k){
	if (k == 1) {
		string s = "1";
		for (int i = 2; i <= n; ++i) s += '0';
		return s;
	}
	string t = "1";
	for (int i = 1; i <= (n - k) / 2; ++i) t += '0';
	string s;
	for (int i = 0; i < n; ++i) s += t[i % t.length()];
	return s;
}
int main(){
	cin >> n >> k;
	cout << solve(n, k) << endl;
}