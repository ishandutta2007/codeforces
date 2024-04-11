#include <bits/stdc++.h>
using namespace std;
char s[10005];
set<string> T;
int g[10005][2];
int n;
inline string cut(int l, int r) {
	char buffer[5];
	for (int i = l; i <= r; ++i)
		buffer[i - l] = s[i];
	buffer[r - l + 1] = 0; 
	string s = buffer;
	return s;
}
int main() {
	std::ios::sync_with_stdio(false);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	g[n + 1][0] = g[n + 1][1] = true;
	for (int i = n; i >= 6; --i) {
		g[i][0] = g[i + 2][1];
		if (g[i + 2][0] && strncmp(s + i, s + i + 2, 2)) g[i][0] |= g[i + 2][0];
		g[i][1] = g[i + 3][0];
		if (g[i + 3][1] && strncmp(s + i, s + i + 3, 3)) g[i][1] |= g[i + 3][1]; 
	}
	
	for (int i = 6; i <= n; ++i) {
		if (i + 1 <= n) {
			if (g[i + 2][1] || (strncmp(s + i, s + i + 2, 2) && g[i + 2][0])) {
				string str = cut(i, i + 1);
				T.insert(str);
			}
		}
		if (i + 2 <= n) {
			if (g[i + 3][0] || (strncmp(s + i, s + i + 3, 3) && g[i + 3][1])) {
				string str = cut(i, i + 2);
				T.insert(str);
			}
		}
	}
	
	cout << T.size() << endl;
	for (auto v : T) {
		cout << v << endl;
	}
}