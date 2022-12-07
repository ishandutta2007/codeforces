#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int n, cnt[555111];
string s;
ll res, sum, ones;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> s;
	for (auto x : s) {
		if (x == '0') {
			rep(i, 0, ones + 1)
				cnt[i]++;
			ones = 0;
		}
		else {
			sum += ones + 1;
			sum += cnt[ones];
			cnt[ones + 1] += cnt[ones];
			cnt[ones] = 0;
			ones++;
		}
		res += sum;
	}
	cout << res << endl;
	return 0;
}