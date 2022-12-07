#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

ll k;
string t = "codeforces";

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
	cin >> k;
	rep(i, 10, 1111) {
		string s;
		ll x = 1;
		rep(j, 0, 10) {
			ll c = i / 10 + (j < i % 10);
			x *= c;
			while (c--)
				s += t[j];
		}
		if (k <= x) {
			cout << s << endl;
			break;
		}
	}
		
	
	
	return 0;
}