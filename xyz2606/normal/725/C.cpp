#include<bits/stdc++.h>
using namespace std;
char a[2][99];
int pi[555], pj[555];
int main() {
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	string st;
	cin >> st;
	vector<char> st1;
	for(int i(0); i < 27; i++) {
		cnt[st[i] - 'A']++;
		if(cnt[st[i] - 'A'] == 1) {
			st1.push_back(st[i]);
		}
		if(i > 0 && st[i] == st[i - 1]) {
			printf("Impossible\n");
			return 0;
		}
	}
	for(int i(0); i < 26; i++) {
		for(int j(0); j < 13; j++) {
			a[0][j] = st1[j];
			pi[a[0][j]] = 0;
			pj[a[0][j]] = j;
		}
		for(int j(12); j >= 0; j--) {
			a[1][j] = st1[25 - j];
			pi[a[1][j]] = 1;
			pj[a[1][j]] = j;
		}
		bool flag(true);
		for(int j(1); j < 27; j++) {
			if(abs(pi[st[j]] - pi[st[j - 1]]) <= 1 && abs(pj[st[j]] - pj[st[j - 1]]) <= 1) {
				
			}else {
				flag = false;
				break;
			}
		}
		if(flag) {
			a[0][13] = a[1][13] = 0;
			printf("%s\n%s\n", a[0], a[1]);
			return 0;
		}
		st1.insert(st1.begin(), st1.back());
		st1.pop_back();
	}
}