#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10005;

int n;

char s[N];

bool valid[N][2];

int main() {
	scanf("%s", s);
	n = strlen(s);
	vector<string> ans;
	valid[n][0] = valid[n][1] = true;
	for (int i = n - 2; i >= 5; --i) {
		if (i == n - 2) {
			valid[i][0] = true;
		} else if (i == n - 3) {
			valid[i][1] = true;
		} else {
			valid[i][0] = valid[i + 2][1] || (valid[i + 2][0] && !(s[i] == s[i + 2] && s[i + 1] == s[i + 3]));
			valid[i][1] = valid[i + 3][0] || (valid[i + 3][1] && !(s[i] == s[i + 3] && s[i + 1] == s[i + 4] && s[i + 2] == s[i + 5]));
		}
		if (valid[i][0]) {
			string s = "";
			s += ::s[i];
			s += ::s[i + 1];
			ans.push_back(s);
		}
		if (valid[i][1]) {
			string s = "";
			s += ::s[i];
			s += ::s[i + 1];
			s += ::s[i + 2];
			ans.push_back(s);
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	printf("%d\n", (int)ans.size());
	if (ans.size()) {
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf("%s\n", ans[i].c_str());
		}
	}
	return 0;
}