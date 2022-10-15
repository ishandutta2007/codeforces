#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

string s, t, p;
int c[26];

bool solve() {
	cin >> s >> t >> p;
	//s is subseq of t
	memset(c, 0, sizeof(c));
	{
		int i=0, j=0;
		while(i<s.size()&&j<t.size()) {
			if(s[i]==t[j]) {
				++i;
			} else
				++c[t[j]-'a'];
			++j;
		}
		if(i<s.size())
			return 0;
		for(; j<t.size(); ++j)
			++c[t[j]-'a'];
	}
	//chekc p has chars
	for(char d : p)
		--c[d-'a'];
	for(int i=0; i<26; ++i)
		if(c[i]>0)
			return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while(q--)
		cout << (solve()?"YES":"NO") << "\n";
}