#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++) {
		if (i+7>s.size()) return printf("NO\n"), 0;
		string t = s.substr(i,7);
		sort(t.begin(),t.end());
		if (t[0]==t[6]) return printf("YES\n"), 0;
	}

	return 0;
}