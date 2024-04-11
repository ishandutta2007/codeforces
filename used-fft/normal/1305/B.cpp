#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s; cin >> s;
	int n = size(s);
	vector<int> l, r;

	for(int i = 0, j = n - 1; i < j; ) {
		if(s[i] == ')') {
			++i;
		} else if(s[j] == '(') {
			--j;
		} else {
			l.push_back(i++);
			r.push_back(j--);
		}
	}

	cout << !empty(l) << '\n';
	if(!empty(l)) cout << 2*l.size() << '\n';
	for(int i : l) cout << i+1 << ' ';
	for(int i = size(r); i--; )
		cout << r[i]+1 << ' ';
}