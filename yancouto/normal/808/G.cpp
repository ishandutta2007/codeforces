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

int n;
char s[112345], t[112345];
int f[112345], go[112345][26];
int ns, nt;
int memo[11234567];
int solve(int i, int j) {
	int &r = memo[i * (nt + 1) + j];
	if(r != -1) return r;
	if(j == nt) r = 1, j = f[j];
	else r = 0;
	if(i == ns) return r;
	int nr = 0;
	if(s[i + 1] != '?') nr = solve(i + 1, go[j][s[i + 1] - 'a']);
	else for(int a = 0; a < 26; a++)
		nr = max(nr, solve(i + 1, go[j][a]));
	return r += nr;
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, j;
	scanf("%s %s", s + 1, t + 1);
	ns = strlen(s + 1); nt = strlen(t + 1);
	if(nt > ns) { puts("0"); return 0; }
	go[0][t[1] - 'a'] = 1;
	for(i = 1; i <= nt; i++) {
		f[i] = f[i - 1];
		while(f[i] > 0 && t[f[i] + 1] != t[i])
			f[i] = f[f[i]];
		if(t[f[i] + 1] == t[i]) f[i]++;
		if(i == 1) f[i] = 0;
		for(int a = 0; a < 26; a++)
			go[i][a] = go[f[i]][a];
		if(i + 1 <= nt) go[i][t[i + 1] - 'a'] = i + 1;
	}
	printf("%d\n", solve(0, 0));
}