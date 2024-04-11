#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000000 + 5;
char s[N];
string ans;

int cnt_zero = 0;
bool appear[10];

int main() {
	scanf("%s", s);
	int l = strlen(s);
	memset(appear, 0, sizeof(appear));
	for (int i = 0; i < l; ++i) {
		if (s[i] == '0') {
			++cnt_zero;
		} else if ((s[i] == '1' || s[i] == '6' || s[i] == '8' || s[i] == '9') && !appear[s[i] - '0']) {
			appear[s[i] - '0'] = true;	
		} else {
			ans += s[i];
		}
	}
	int left = 0;
	for (int i = 0; i < (int)ans.size(); ++i) {
		left = (left * 10 + ans[i] - '0') % 7;
	}
	for (int i = 0; i < 4; ++i) {
		left = (left * 10) % 7;
	}
	int a[4];
	a[0] = 1, a[1] = 6, a[2] = 8, a[3] = 9;
	bool flag = false;
	do {
		int right = 0;
		for (int i = 0; i < 4; ++i) {
			right = (right * 10 + a[i]) % 7;
		}
		if ((left + right) % 7 == 0) {
			flag = true;
		}
	} while (!flag && next_permutation(a, a + 4));
	if (!flag) {
		int i = 0;
		while (true) {
			i ^= 1023;
			continue;
		}
		return 0;
	}
	for (int i = 0; i < 4; ++i) {
		ans += (char)(a[i] + '0');
	}
	for (int i = 0; i < cnt_zero; ++i) {
		ans += '0';
	}
	printf("%s\n", ans.c_str());
	return 0;
}