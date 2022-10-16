#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int N = 2e5+7;

int n, k;
char s[N];
int cnt[32];

int get_res() {
	int begin = 0;
	char sym = s[0];
	while(sym == s[begin + 1] && begin + 1 < n) ++begin;

	int end = begin + 1;

	for(int i = end; i < n; ++i) {
		if(s[i] == sym) continue;
		if(!cnt[s[i]-'a']++) ++k;
	}

	for(; end < n; ++end) {
		if(s[end] == sym) continue;
		if(!--cnt[s[end]-'a']) --k;
		if(k == 0) break;
	}

	return ((ll) (begin+2) * (n-end)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;

	int res = get_res();
	if(s[0] != s[n-1]) {
		reverse(&s[0], &s[n]);
		res = ((ll) res + get_res() - 1) % MOD;
	}

	cout << res;
}