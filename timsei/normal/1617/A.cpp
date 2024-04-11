#include <bits/stdc++.h>
using namespace std;


const int N = 1e6 + 5;

int cnt[26], n, m, x, y;
char s[N], t[N];

void out(int c) {
	for(int i = 0; i < cnt[c]; ++ i)
	putchar(c + 'a');
}

int main() {
	int tt;
	for(cin >> tt; tt --;) {
		scanf("%s", s + 1); n = strlen(s + 1);
		scanf("%s", t + 1); m = strlen(t + 1);
		// abc or acb
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; ++ i) ++ cnt[s[i] - 'a'];
		if(t[1] < t[2] && t[2] < t[3]) {
			if(cnt[0] && cnt[1] && cnt[2]) {
				out(0); out(2); out(1);
				for(int j = 3; j < 26; ++ j) out(j);
				puts("");
				continue;
			}
		}  {
			for(int i = 0; i < 26; ++ i) out(i);
			puts("");
		}
	}
}