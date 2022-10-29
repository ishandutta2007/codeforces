#include <bits/stdc++.h>
using namespace std;
int n, m, tot, ans, cnt[55];
char t[55], s[55];
bool use[26], bo[26];
int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d", &n);
	scanf("%s", t);
	for (int i = 0; i < n; ++i)
		if (t[i] != '*') use[t[i] - 'a'] = true;
	
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%s", s);
		bool valid = true;
		for (int j = 0; j < n; ++j) {
			if (t[j] != '*' && s[j] != t[j]) valid = false;
			if (t[j] == '*' && use[s[j] - 'a']) valid = false;
		}
		if (valid) {
			++tot;
			memset(bo, false, sizeof bo);
			for (int j = 0; j < n; ++j)
				if (t[j] == '*') bo[s[j] - 'a'] = true;
			for (int j = 0; j < 26; ++j)
				if (bo[j]) ++cnt[j];
		}
	}
	
	for (int i = 0; i < 26; ++i)
		if (cnt[i] == tot) ++ans;
	printf("%d\n", ans);
}