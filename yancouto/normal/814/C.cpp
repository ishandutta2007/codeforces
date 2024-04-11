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

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;
const int N = 2123;
char s[N];
int ans[256][N];
int l[256][N], r[256][N];

int main() {
	int i, j, q; char c;
	rd(n);
	scanf(" %s", s);
	for(c = 'a'; c <= 'z'; c++) {
		l[c][0] = 0;
		for(i = 1; i < n; i++)
			if(s[i] != c) l[c][i] = 0;
			else if(s[i - 1] == c) l[c][i] = l[c][i - 1] + 1;
			else l[c][i] = 0;
		for(i = n - 2; i >= 0; i--)
			if(s[i] == c && s[i + 1] == c) r[c][i] = r[c][i + 1] + 1;
		for(i = 0; i < n; i++) {
			int pt = 0;
			for(j = i; j < n; j++) {
				pt += (s[j] != c);
				ans[c][pt] = max(ans[c][pt], j - i + 1 + l[c][i] + r[c][j]);
			}
		}
		for(i = 1; i < N; i++)
			ans[c][i] = max(ans[c][i], ans[c][i - 1]);
	}
	rd(q);
	for(i = 0; i < q; i++) {
		int m;
		rd(m); scanf(" %c", &c);
		printf("%d\n", ans[c][m]);
	}
}