#include <bits/stdc++.h>
using namespace std;

int n;
char buff[10013];
string s;
bool dp[10013][4];
set<string> ans;

int main() {
	scanf(" %s",&buff);
	s = string(buff);
	n = s.size();
	dp[n][2] = dp[n][3] = 1;
	for (int i=n-2;i>=5;i--) {
		if (dp[i+2][3] || (dp[i+2][2] && s.substr(i,2)!=s.substr(i+2,2))) {
			dp[i][2] = 1;
			ans.insert(s.substr(i,2));
		}
		if (dp[i+3][2] || (dp[i+3][3] && s.substr(i,3)!=s.substr(i+3,3))) {
			dp[i][3] = 1;
			ans.insert(s.substr(i,3));
		}
	}
	printf("%d\n",ans.size());
	for (auto s: ans) printf("%s\n",s.c_str());

	return 0;
}