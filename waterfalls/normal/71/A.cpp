#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		string s;
		cin >> s;
		if (s.size()<=10) cout << s << endl;
		else cout << s[0] << s.size()-2 << s.back() << endl;
	}

	return 0;
}