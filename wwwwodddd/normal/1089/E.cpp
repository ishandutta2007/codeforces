#include <bits/stdc++.h>
using namespace std;
vector<string> s;
int main() {
	int n, m;
	cin >> n;
	m = n + 1;
	char ei = '-';
	char ej = '-';
	for (char i = 'a'; i <= 'f'; i++) {
		if ((i - 'a') % 2 == 0) {
			for (char j = '1'; j <= '8'; j++) {
				string t;
				t += i;
				t += j;
				s.push_back(t);
				m--;
				if (m == 2) {
					ei = i;
					ej = j;
					goto enda;
				}
			}
		} else {
			for (char j = '8'; j >= '1'; j--) {
				string t;
				t += i;
				t += j;
				s.push_back(t);
				m--;
				if (m == 2) {
					ei = i;
					ej = j;
					goto enda;
				}
			}
		}
	}
	enda:;
	if (m == 2) {
		if (ej == '8') {
			s.push_back("g8");
			s.push_back("h8");
		} else {
			s.push_back(((string)"h") + ej);
			s.push_back("h8");
		}
	} else {
		for (char j = '1'; j <= '6'; j++) {
			if ((j - '1') % 2 == 0) {
				for (char i = 'g'; i <= 'h'; i++) {
					string t;
					t += i;
					t += j;
					s.push_back(t);
					m--;
					if (m == 2) {
						ei = i;
						ej = j;
						goto endb;
					}
				}
			} else {
				for (char i = 'h'; i >= 'g'; i--) {
					string t;
					t += i;
					t += j;
					s.push_back(t);
					m--;
					if (m == 2) {
						ei = i;
						ej = j;
						goto endb;
					}
				}
			}
		}
		endb:;
		if (m == 2) {
			if (ei == 'h') {
				s.push_back("h7");
				s.push_back("h8");
			} else {
				s.push_back("g8");
				s.push_back("h8");
			}
		} else if (m == 3) {
			s.push_back("g7");
			s.push_back("g8");
			s.push_back("h8");
		} else if (m == 4) {
			s.push_back("g8");
			s.push_back("g7");
			s.push_back("h7");
			s.push_back("h8");
		}
	}
	for (int i = 0; i <= n; i++) {
		cout << s[i] << (i == n ? '\n' : ' ');
	}
//	assert(s.size() == n + 1);
	return 0;
}