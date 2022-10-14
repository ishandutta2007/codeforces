#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;
int n, q, ok[300005];

bool good(int i)
{
	return i > 0 && i < n && s[i] == '.' && s[i - 1] == '.';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q >> s;
	int ans = 0;
	for(int i = 1; i < n; i++) if(good(i)) ok[i] = 1, ans ++;
	while(q --) {
		int i; cin >> i;
		char c; cin >> c;
		-- i;
		if(good(i)) ans --;
		if(good(i + 1)) ans --;
		s[i] = c;
		if(good(i)) ans ++;
		if(good(i + 1)) ans ++;
		cout << ans << "\n";
	}
	return 0;
}