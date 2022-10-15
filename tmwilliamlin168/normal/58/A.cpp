#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, match="hello";
	cin >> s;
	int matchI=0;
	for(int i=0; i<s.size(); ++i) {
		if(s[i]==match[matchI]) {
			++matchI;
			if(matchI>=match.size())
				break;
		}
	}
	if(matchI>=match.size())
		cout << "YES";
	else
		cout << "NO";
	return 0;
}