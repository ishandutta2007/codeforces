#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		stack<char> v;
		int turns = 0;
		cin >> s;
		int n = s.size();
		for(int i=0; i < n; i++) {
			if(v.empty()) v.push(s[i]);
			else {
				if(v.top() != s[i]) {
					v.pop();
					turns++;
				} else  {
					v.push(s[i]);
				}
			}
		}

		if(turns % 2 == 0) {
			cout << "NET\n";
		} else {
			cout << "DA\n";
		}
	}
}