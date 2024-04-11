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
#	define debug(args...) ((void) 0)
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

void imp() {
	puts("No");
	exit(0);
}

const int N = 212345;
int sm[N];
int seen[N];
vector<int> adj[N], a[N];
void go(int u) {
	if(seen[u]) return;
	if(sm[u] == -1) imp();
	sm[u] = 1;
	for(int v : adj[u])
		go(v);
}

int lcp(int x) {
	int l = 0;
	while(l < a[x].size() && l < a[x + 1].size() && a[x][l] == a[x + 1][l])
		l++;
	return l;
}

int main() {
	int i, j;
	int n, m;
	rd(n); rd(m);
	for(i = 0; i < n; i++) {
		int l;
		rd(l);
		a[i].resize(l);
		for(j = 0; j < l; j++) rd(a[i][j]);
	}
	for(i = 0; i < n - 1; i++) {
		int l = lcp(i);
		if(l == int(a[i].size())) continue;
		if(l == int(a[i + 1].size())) imp();
		if(a[i + 1][l] > a[i][l]) adj[a[i + 1][l]].pb(a[i][l]);
		else sm[a[i + 1][l]] = -1, sm[a[i][l]] = 1;
	}
	for(i = 1; i <= m; i++)
		if(sm[i] == 1)
			go(i);
	for(i = 0; i < n - 1; i ++) {
		int l = lcp(i);
		if(l == int(a[i].size())) continue;
		if((sm[a[i][l]] == 1) == (sm[a[i + 1][l]] == 1)) {
			if(a[i + 1][l] > a[i][l]) continue;
			else imp();
		} else {
			if(sm[a[i][l]] == 1) continue;
			else imp();
		}
	}
	vector<int> ans;
	for(i = 1; i <= m; i++)
		if(sm[i] == 1)
			ans.pb(i);
	printf("Yes\n%d\n", int(ans.size()));
	for(int x : ans) printf("%d ", x);
	if(!ans.empty()) putchar('\n');
}