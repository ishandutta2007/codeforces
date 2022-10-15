#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	stack<char> brackets;
	int t=0;
	for(char c : s) {
		if(c=='>'||c=='}'||c==']'||c==')') {
			if(brackets.empty()) {
				cout << "Impossible";
				return 0;
			}
			char lastC=brackets.top();
			brackets.pop();
			if(!(lastC=='<'&&c=='>'||lastC=='{'&&c=='}'||lastC=='['&&c==']'||lastC=='('&&c==')'))
				++t;
		} else
			brackets.push(c);
	}
	if(!brackets.empty()) {
		cout << "Impossible";
		return 0;
	}
	cout << t;
	return 0;
}