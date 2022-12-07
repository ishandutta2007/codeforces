#include <bits/stdc++.h>

using namespace std;

int t, n, r[26], vis[26];
string s;

int main() {
	cin >> t;
	while (t--) {
		cin >> s;
		n = s.size();
		memset(r, -1, sizeof r);
		memset(vis, 0, sizeof vis);
		string ans;
		for (int i = 0; i < n; i++) r[s[i] - 'a'] = i;
		int last = -1;
		while (true) {
			int foo = n;
			for (int i = 0; i < 26; i++)
				if (!vis[i] && r[i] != -1) 
					foo = min(foo, r[i]);
			if (foo == n) break;
			for (int i = 25; 0 <= i; i--) {
				if (vis[i]) continue;
				bool done = false;
				for (int j = last + 1; j < n; j++)
					if ((s[j] - 'a') == i && foo >= j) {
						done = true;
						ans.push_back((char) ('a' + i));
						vis[i] = true;
						last = j;
						break;
					}
				if (done) break;
			}	
		}
		cout << ans << "\n";
	}
	
	return 0;					
}