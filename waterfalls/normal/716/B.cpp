#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void solve(string s) {
	if (s.size()<26) {
		cout << -1 << endl;
		return;
	}
	int has[26];
	memset(has,0,sizeof has);
	int bads = 0;
	for (int i=0;i<26;i++) {
		if (s[i]!='?') {
			has[s[i]-'A']+=1;
			bads+=(has[s[i]-'A']==2);
		}
	}
	int r = 25;
	while (true) {
		if (bads==0) {
			int on = 0;
			for (int i=r-25;i<=r;i++) {
				if (s[i]!='?') {
					continue;
				}
				while (has[on]) {
					on+=1;
				}
				s[i] = 'A'+on;
				on+=1;
			}
			for (char& c: s) {
				if (c=='?') c = 'A';
			}
			cout << s << endl;
			return;
		}
		r+=1;
		if (r>=s.size()) {
			cout << -1 << endl;
			return;
		}
		has[s[r]-'A']+=1;
		bads+=(has[s[r]-'A']==2);
		has[s[r-26]-'A']-=1;
		bads-=(has[s[r-26]-'A']==1);
	}
}

int main() {
	string s;
	cin >> s;
	solve(s);

	return 0;
}