#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int BASE = 7;
const int MOD = 998244343;

int n, m;
char str[600005];
LL h[600005], pw[600005];

bool has(LL x)
{
	int l = 0, r = n - 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(h[mid] == x) return true;
		if(h[mid] < x) l = mid + 1; else r = mid - 1;
	}
	return false;
}

bool check()
{
	int len = strlen(str);
	LL hsh = 0;
	rep(i, len) hsh += (str[i] - 'a' + 1) * pw[i];
	rep(i, len) {
		int cs = (str[i] - 'a' + 1);
		hsh -= pw[i] * cs;
		rep1(j, 3) if(j != cs && has(hsh + j * pw[i])) return true;
		hsh += pw[i] * cs;
	}
	return false;
}

int main()
{
	pw[0] = 1; rep1(i, 600000) pw[i] = (pw[i - 1] * BASE) % MOD;
	scanf("%d%d", &n, &m);
	rep(i, n) {
		scanf("%s", str);
		int len = strlen(str);
		rep(j, len) h[i] += (str[j] - 'a' + 1) * pw[j];
	}
	sort(h, h + n);
	rep(i, m) {
		scanf("%s", str);
		puts(check() ? "YES" : "NO");
	}

	return 0;
}