#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

char s[212345];
int pos[256], cur[256];
int main() {
	int i, j, n, m; char c1, c2;
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	for(i = 'a'; i <= 'z'; i++)
		pos[i] = i;
	for(i = 0; i < m; i++) {
		scanf(" %c %c", &c1, &c2);
		swap(pos[c1], pos[c2]);
	}
	for(i = 'a'; i <= 'z'; i++)
		cur[pos[i]] = i;
	for(i = 0; i < n; i++)
		putchar(cur[s[i]]);
	putchar('\n');
}