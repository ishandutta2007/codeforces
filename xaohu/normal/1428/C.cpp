#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int T, n;
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> s;
		n = s.size();
		vector<char> v;
		rep(i, 0, n) {
			if (v.size() && s[i] == 'B')
				v.pop_back();
			else
				v.push_back(s[i]);
		}
		cout << v.size() << endl;
	}

	return 0;
}