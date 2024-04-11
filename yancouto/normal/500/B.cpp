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

template<class num> inline void read(num &x) {
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
const int N = 1123;

int S[N], sz[N];
vector<int> p[N];
int a[N];

int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

inline void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	S[b] = a;
	for(int x : p[b]) p[a].pb(x);
	sz[a] += sz[b];
}

int main() {
	int i, j;
	char x;
	read(n);
	for(i = 0; i < n; i++) read(a[i]);
	for(i = 0; i < n; i++) S[i] = i, sz[i] = 1, p[i].pb(a[i]);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			scanf(" %c", &x);
			if(x == '1') join(i, j);
		}
	for(i = 0; i < n; i++)
		if(S[i] == i)
			sort(p[i].begin(), p[i].end());
	for(i = n - 1; i >= 0; i--)
		a[i] = p[find(i)].back(), p[find(i)].pop_back();
	for(i = 0; i < n; i++) printf("%d ", a[i]);
	putchar('\n');
}