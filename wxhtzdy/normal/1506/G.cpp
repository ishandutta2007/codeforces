#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

char s[200005];
bool have[26], tmp[26];

bool check(string str)
{
	int len = strlen(s), n = str.size();
	int ptr = 0, idx = 0;
	while(ptr < n && idx < len) {
		if(str[ptr] == s[idx]) ptr ++;
		if(ptr == n) break;
		idx ++;
	}
	if(idx == len) return false;
	rep(i, 26) tmp[i] = false;
	for(int i = idx; i < len; i ++) tmp[s[i] - 'a'] = true;
	rep(i, 26) if(have[i] && !tmp[i]) return false;
	return true;
}

void solve()
{
	scanf("%s", s);
	int n = strlen(s);
	rep(i, 26) have[i] = false;
	rep(i, n) have[s[i] - 'a'] = true;
	string ans = "";
	rep(i, 26) {
		for(int j = 25; j >= 0; j--) {
			if(!have[j]) continue;
			string nans = ans + (char)('a' + j);
			if(check(nans)) { have[j] = false; ans += (char)('a' + j); break; }
		}
	}
	rep(i, ans.size()) printf("%c", ans[i]); printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}