#include <bits/stdc++.h>
using namespace std;

int n;
string ss[113];

int main() {
	cin >> n;
	for (int i=0;i<n;i++) cin >> ss[i];
	int ans = 0;
	for (char a='a';a<='z';a++) for (char b='a';b<='z';b++) {
		int cur = 0;
		for (string s: ss) {
			bool ok = 1;
			for (char c: s) if (c!=a && c!=b) ok = 0;
			if (ok) cur+=s.size();
		}
		ans = max(ans,cur);
	}
	cout << ans << '\n';

	return 0;
}