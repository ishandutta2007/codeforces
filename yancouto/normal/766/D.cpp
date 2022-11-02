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

int n, m, q;

const int N = 112345;
int S[N], c[N], sz[N];
vector<int> l[N];
char s[100], t[100];
map<string, int> mp;

int main() {
	int i, j, tp;
	rd(n); rd(m); rd(q);
	for(i = 0; i < n; i++) {
		scanf("%s", s);
		mp[s] = i;
	}
	for(i = 0; i < n; i++) S[i] = i, sz[i] = 1, l[i].pb(i);
	for(i = 0; i < m; i++) {
		scanf("%d %s %s", &tp, s, t); tp--;
		int a = mp[s], b = mp[t];
		if(S[a] == S[b]) {
			if((c[a] != c[b]) != tp) puts("NO");
			else puts("YES");
		} else {
			int ch = ((c[a] != c[b]) != tp);
			if(sz[S[a]] < sz[S[b]]) swap(a, b);
			for(int x : l[S[b]])
				S[x] = S[a], l[S[a]].pb(x), c[x] ^= ch, sz[S[a]]++;
			puts("YES");
		}
	}
	for(i = 0; i < q; i++) {
		scanf("%s %s", s, t);
		int a = mp[s], b = mp[t];
		if(S[a] != S[b]) puts("3");
		else if(c[a] != c[b]) puts("2");
		else puts("1");
	}

}