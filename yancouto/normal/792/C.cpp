#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

char s[112345];
int memo[112345][3][2];
int solve(int i, int sum, bool any) {
	if(!s[i]) return sum == 0 && any? 0 : -1e8;
	int &r = memo[i][sum][any];
	if(r != -1) return r;
	r = -1e8;
	if(sum == 0 && any) r = 0;
	if(!any && s[i] == '0') r = 1;
	if(any || s[i] != '0') r = max(r, solve(i + 1, (sum + s[i] - '0') % 3, true) + 1);
	r = max(r, solve(i + 1, sum, any));
	return r;
}

void build(int i, int sum, bool any) {
	if(!s[i]) return;
	int r = solve(i, sum, any);
	if(sum == 0 && any && r == 0) return;
	if(!any && s[i] == '0' && r == 1) { putchar('0'); return; }
	if((any || s[i] != '0') && r == solve(i + 1, (sum + s[i] - '0') % 3, true) + 1) {
		putchar(s[i]);
		build(i + 1, (sum + s[i] - '0') % 3, true);
	} else build(i + 1, sum, any);
}

int main() {
	scanf("%s", s);
	memset(memo, -1, sizeof memo);
	if(solve(0, 0, false) <= 0) puts("-1");
	else { build(0, 0, false); putchar('\n'); }
}