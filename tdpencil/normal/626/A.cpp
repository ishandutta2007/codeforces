#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector
const int mxN = 2e5;
int n, a[mxN];
void solve() {
	cin >> n;
	string s;
	cin >> s;

	pair<int, int> cur(0, 0);
	multiset<pair<int, int>> re;
	int ans = 0;
	re.insert({0, 0});
	for(int i =0; i < int(n); i++) {
		if(s[i] == 'L') cur.first--;
		if(s[i] == 'R') cur.first++;
		if(s[i] == 'U') cur.second++;
		if(s[i] == 'D') cur.second--;
		if(re.find(cur) != re.end()) {
			ans += re.count(cur);
		}
		re.insert(cur);

	}

	cout << ans << "\n";
}
int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(0);

	int T = 1;
	while(T--)
		solve();
}