#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;


const int N = 105;
char s[N], t[N];

const int L = 26;
int cnt[L];

int main() {
	scanf("%s%s", s, t);
	int l0 = strlen(s), l1 = strlen(t);
	for (int i = 0; i < l0; ++i) {
		++cnt[s[i] - 'a'];
	}
	for (int i = 0; i < l1; ++i) {
		--cnt[t[i] - 'a'];
	}
	bool automation = true, array = true, both = true;
	for (int i = 0; i < L; ++i) {
		array = array && cnt[i] == 0;
		both = both && cnt[i] >= 0;
	}
	int j = 0;
	for (int i = 0; i < l0; ++i) {
		if (j < l1 && t[j] == s[i]) {
			++j;
		}
	}
	automation = j == l1;
	string ans;
	if (automation) {
		ans = "automaton";
	} else if (array) {
		ans = "array";
	} else if (both) {
		ans = "both";
	} else {
		ans = "need tree";
	}
	printf("%s\n", ans.c_str());
	return 0;
}