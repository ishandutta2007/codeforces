#include <bits/stdc++.h>
using namespace std;
set<string> T;
char str[25];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", str);
		string s;
		int len = strlen(str);
		for (int j = 0; j < len; ++j) {
			if (str[j] == 'h') {
				while (s.size() && s[s.size() - 1] == 'k') s.pop_back();	
			}
			if (str[j] == 'u') {
				s += "oo";	
			}
			else s.push_back(str[j]);
		}
		T.insert(s);
	}
	cout << T.size() << endl;
}