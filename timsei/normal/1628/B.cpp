#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t, n, m, x, y;
string s[N];

map < string, int> Map;

void rmain() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> s[i];
	Map.clear();
	for(int i = 1; i <= n; ++ i) {
		if(Map.count(s[i])) continue;
		Map[s[i]] = 1;
		if(s[i].length() == 1) {
			puts("YES"); return;
		} else if(s[i].length() == 2) {
			if(s[i][0] == s[i][1]) {
				puts("YES");
				return;
			}
			for(int j = i + 1; j <= n; ++ j) {
				if(s[j].length() == 1) {
					puts("YES");
					return;
				}
				if(s[i][0] == s[j][s[j].length() - 1] && s[i][1] == s[j][s[j].length() - 2]) {
					puts("YES");
					return;
				}
			}
		} else {
			if(s[i][0] == s[i][2]) {
				puts("YES");
				return;
			}
			for(int j = i + 1; j <= n; ++ j) {
				if(s[j].length() == 1) {
					puts("YES");
					return;
				}
				if(s[j].length() == 2) {
					if(s[j][0] == s[i][1]  && s[j][1] == s[i][0]) {
						puts("YES");
						return;
					}
				}
				if(s[j].length() == 3) {
					if(s[j][0] == s[i][2] && s[j][1] == s[i][1] && s[j][2] == s[i][0]) {
						puts("YES");
						return;
					}
				}
			}
		}
	}
	puts("NO");
}

int main() {
	ios::sync_with_stdio(false);
	for(cin >> t; t --;) {
		rmain();
	}
}