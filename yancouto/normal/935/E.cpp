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

const int N = 11234;
char E[N];
int P, M;
char sm;
int op[N], spl[N];

int mn(int a, int b) { return a < b? a : b; }
int mx(int a, int b) { return a > b? a : b; }

#define left asdasd

int (*func[2])(int, int) = {mn, mx};

int memo[N][112][2];
bool seen[N][112][2];
int solve(int i, int left, bool mx) {
	if(E[i] != '(') return left? (mx? -1e8 : 1e8) : E[i] - '0';
	int &r = memo[i][left][mx];
	if(seen[i][left][mx]) return r;
	seen[i][left][mx] = 1;
	r = mx? -1e8 : 1e8;
	{ // add '-'
		int nleft = left - (sm == '-');
		for(int x = 0; x <= nleft; x++)
			r = func[mx](r, solve(i + 1, x, mx) - solve(spl[i] + 1, nleft - x, !mx));
	}
	{ // add '+'
		int nleft = left - (sm == '+');
		for(int x = 0; x <= nleft; x++)
			r = func[mx](r, solve(i + 1, x, mx) + solve(spl[i] + 1, nleft - x, mx));
	}
	return r;
}

int st[N], sn;
vector<int> adj[N];
vector<int> ord;

void go(int u) {
	if(E[u] == '(') {
		go(u + 1);
		go(spl[u] + 1);
	}
	ord.pb(u);
}

int main() {
	int i, j;
	scanf("%s", E);
	scanf("%d %d", &P, &M);
	if(E[1] == 0) {
		puts(E);
		return 0;
	}
	if(P <= M) sm = '+';
	else sm = '-';
	for(i = 0; E[i]; i++) {
		if(E[i] == '(') {
			st[sn++] = i;
		} else if(E[i] == ')') {
			op[i] = st[--sn];
			op[st[sn]] = i;
		} else if(E[i] == '?')
			spl[st[sn - 1]] = i;
	}
	go(0);
	for(int i : ord) {
		if(isdigit(E[i])) {
			memo[i][0][0] = memo[i][0][1] = E[i] - '0';
			for(int left = 1; left <= 100; left++)
				memo[i][left][0] = 1e8,
				memo[i][left][1] = -1e8;
		} else {
			for(int left = 0; left <= 100; left++) {
				for(int mx = 0; mx < 2; mx++) {
					int &r = memo[i][left][mx];
					if(mx) r = -1e8;
					else r = 1e8;
					if(sm == '+' || left) {
						int nleft = left - (sm == '-');
						for(int x = 0; x <= nleft; x++)
							r = func[mx](r, memo[i + 1][x][mx] - memo[spl[i] + 1][nleft - x][!mx]);
					}
					if(sm == '-' || left) {
						int nleft = left - (sm == '+');
						for(int x = 0; x <= nleft; x++)
							r = func[mx](r, memo[i + 1][x][mx] + memo[spl[i] + 1][nleft - x][mx]);
					}
				}
			}
		}
	}
	printf("%d\n", memo[0][min(P, M)][1]);
	//printf("%d\n", solve(0, min(P, M), 1));
}