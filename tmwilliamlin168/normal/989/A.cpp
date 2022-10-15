#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	s="."+s+".";
	for(int i=1; i<s.size()-2; ++i) {
		int m=0;
		for(int j=i-1; j<=i+1; ++j)
			if(s[j]!='.')
				m|=1<<(s[j]-'a');
		if(m==7) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}