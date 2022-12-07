#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int n;
string s;
vector<int> ans;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> s;
	n = s.size();

	int l = 0, r = n - 1;
	while (1) {
		while (l < n && s[l] == ')')
			l++;
		while (r >= 0 && s[r] == '(')
			r--;
		if (l > r) 
			break;
		ans.push_back(l);
		ans.push_back(r);
		l++;
		r--;
	}

	if (ans.empty()) 
		cout << 0 << endl;
	else {
		cout << 1 << endl << ans.size() << endl;
		sort(ans.begin(), ans.end());
		for (auto x : ans)
			cout << x + 1 << " ";
		cout << endl;
	}
	return 0;
}