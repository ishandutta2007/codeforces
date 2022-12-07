#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, n;
string s;
string t = "2020";

int main() { 
	cin >> T;
	while (T--) {
		cin >> n >> s;
		bool res = 0;
		rep(a, 0, 5) {
			int b = 4 - a;
			if (s.substr(0, a) == t.substr(0, a) && s.substr(n - b, b) == t.substr(4 - b, b))
				res = 1;
		}
		cout << (res ? "YES\n" : "NO\n");
	}
	return 0;
}