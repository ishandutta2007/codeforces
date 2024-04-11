#include <bits/stdc++.h>
using namespace std;
string ss, s[105];
int n;
bool flag;
int main() {
	cin >> ss;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		if (s[i] == ss) flag = true;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (s[i][1] == ss[0] && s[j][0] == ss[1]) flag = true;
	puts(flag ? "YES" : "NO");
}