#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string s, ans;
	cin >> s;
	for (int i = 1; i + 2 < s.size(); ++i) {
		if (s[i] == 'a' && s[i + 1] == 't') {
			string tmp;
			tmp += s[0];			
			for (int j = 1; j < i; ++j) {
				if (j + 2 < i && s[j] == 'd' && s[j + 1] == 'o' && s[j + 2] == 't') {
					tmp += '.';
					j += 2;
				} else {
					tmp += s[j];
				}
			}
			tmp += '@';
			for (int j = i + 2; j < s.size(); ++j) {
				if (j + 3 < s.size() && s[j] == 'd' && s[j + 1] == 'o' && s[j + 2] == 't') {
					tmp += '.';
					j += 2;
				} else {
					tmp += s[j];
				}
			}
			if (ans == "" || tmp.size() < ans.size() || tmp.size() == ans.size() && tmp < ans) {
				ans = tmp;
			}
		}
	}
	cout << ans << endl;
	return 0;
}