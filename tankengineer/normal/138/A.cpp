#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
char s[4][25005];

string cut(int i) {
	string ret;
	int l = strlen(s[i]);
	int cnt = 0;
	for (int j = l - 1; j >= 0; --j) {
		ret += s[i][j];
		if (s[i][j] == 'a' || s[i][j] == 'e' || s[i][j] == 'i' || s[i][j] == 'o' || s[i][j] == 'u') {
			++cnt;
		}
		if (cnt == k) {
			break;
		}
	}
	if (cnt != k) {
		ret = "";
		ret += char(i + '0');
	}
	return ret;	
}

int cal() {
	string t[4];
	for (int i = 0; i < 4; ++i) {
		t[i] = cut(i);
	}
	if (t[0] == t[1] && t[1] == t[2] && t[2] == t[3]) {
		return 0;
	}
	if (t[0] == t[1] && t[2] == t[3]) {
		return 1;
	}
	if (t[0] == t[2] && t[1] == t[3]) {
		return 2;
	}
	if (t[0] == t[3] && t[1] == t[2]) {
		return 3;
	}
	return 4;
}

int main() {
	scanf("%d%d", &n, &k);
	int ans = 0;	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%s", s[j]);
		}
		int tmp = cal();
		if (ans == 4 || tmp == 4) {
			ans = 4;
		} else if (ans == 0 || tmp == 0) {
			ans = ans + tmp;
		} else if (ans != tmp) {
			ans = 4;
		}
	}
	if (ans == 0) {
		puts("aaaa");
	} else if (ans == 1) {
		puts("aabb");
	} else if (ans == 2) {
		puts("abab");
	} else if (ans == 3) {
		puts("abba");
	} else {
		puts("NO");
	}
	return 0;
}