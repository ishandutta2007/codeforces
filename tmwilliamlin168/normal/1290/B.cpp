#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

string s;
int c[26][200001], q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> q;
	for(int i=0; i<s.size(); ++i) {
		++c[s[i]-'a'][i+1];
		for(int j=0; j<26; ++j)
			c[j][i+1]+=c[j][i];
	}
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		int d=0;
		for(int i=0; i<26; ++i)
			d+=c[i][r+1]-c[i][l]>0;
		if(d==1) {
			cout << (r-l+1==1?"Yes":"No") << "\n";
		} else if(d==2) {
			cout << (s[l]==s[r]?"No":"Yes") << "\n";
		} else {
			cout << "Yes\n";
		}
	}
}