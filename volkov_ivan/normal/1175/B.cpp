#include <bits/stdc++.h>
#define int long long

using namespace std;

const long long INF = (1ll << 32) - 1;

int f(int &n) {
	int sum = 0;
	while (n > 0) {
		if (sum > INF) {
			cout << "OVERFLOW!!!" << endl;
			exit(0);
		}
		n--;
		string s;
		getline(cin, s);
		if (s == "end") return sum;
		if (s[0] == 'f') {
			stringstream ss;
			ss << s;
			string t;
			int x;
			ss >> t >> x;
			int res = f(n); 
			sum = sum + res * x;
		} else {
			sum++;
		}
	}
	if (sum > INF) {
		cout << "OVERFLOW!!!" << endl;
		exit(0);
	}
	return sum;	
}

signed main() {
	//freopen("Desktop/input.txt", "r", stdin); 
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int l;
	cin >> l;
	string s;
	getline(cin, s);
	int t = f(l);
	cout << t << endl;
	return 0;
}