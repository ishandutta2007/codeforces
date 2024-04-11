#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

const int B = 300;

int n;
string s;
vector<int> ones;
ll res;
unordered_map<int, int> m;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> s;
	n = sz(s);
	
	ones.push_back(0);
	rep(i, 0, n)
		if (s[i] == '1')
			ones.push_back(i + 1);
	ones.push_back(n + 1);
	
	rep(i, 1, sz(ones) - 1) {
		rep(j, i + 1, sz(ones)) {
			int s = j - i;
			if (s * B > n)
				break;
			rep(p, ones[i - 1] + 1, ones[i] + 1) {
				int a = max(B, (ones[j - 1] + 1 - p + s - 1) / s);
				int b = (ones[j] - p) / s;
				if (a <= b)
					res += b - a + 1;
			}
		}
	}
	
	rep(d, 1, B) {
		m.clear();
		m[0]++;
		int sum = 0;
		rep(i, 0, n) {
			if (s[i] == '1') sum++;
			res += m[sum * d - (i + 1)]++;
		}
	}
	
	cout << res << endl;
	return 0;
}