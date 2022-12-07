#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, a, b, n;
string s;

int main() { 
	cin >> T;
	while (T--) {
		cin >> a >> b >> s;
		n = s.size();
		int res = 0;
		for (int i = 0; i < n;) {
			if (s[i] == '0') {
				i++;
				continue;
			}
			int j = i - 1;
			while (j >= 0 && s[j] == '0') 
				j--;
			if (j >= 0) 
				res += min((i - j - 1) * b, a);
			else
				res += a;
			while (i < n && s[i] == '1')
				i++;
		}
		cout << res << "\n";
	}
	return 0;
}