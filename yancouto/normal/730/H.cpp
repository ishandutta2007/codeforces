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

int n, m;
char s[112][112];
char cur[112];
int mrk[112];

int main() {
	int i, j, x;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%s", s[i]);
	scanf("%d", &x); x--;
	strcpy(cur, s[x]);
	int len = strlen(cur);
	mrk[x] = 1;
	for(i = 1; i < m; i++) {
		scanf("%d", &x); x--;
		if(len != strlen(s[x])) { puts("No"); return 0; }
		for(j = 0; j < len; j++)
			if(cur[j] != s[x][j])
				cur[j] = '?';
		mrk[x] = 1;
	}
	for(i = 0; i < n; i++) {
		if(mrk[i]) continue;
		if(len != strlen(s[i])) continue;
		for(j = 0; j < len; j++)
			if(cur[j] != '?' && cur[j] != s[i][j])
				break;
		if(j == len) { puts("No"); return 0; }
	}
	puts("Yes");
	puts(cur);
}