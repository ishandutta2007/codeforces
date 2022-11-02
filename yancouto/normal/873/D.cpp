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

map<pii, int> memo;
int mx(int l, int r) {
	if(l >= r - 1) return 1;
	int &re = memo[pii(l, r)];
	if(re != 0) return re;
	int m = (l + r) / 2;
	re = 1 + mx(l, m) + mx(m, r);
	assert(re & 1);
	return re;
}

vector<int> go(int l, int r, int k) {
	assert(k <= mx(l, r) && (k & 1));
	if(k == 1) {
		vector<int> ans;
		for(int i = l; i < r; i++)
			ans.pb(i - l);
		return ans;
	}
	int m = (l + r) / 2; k--;
	int k_ = min(k - 1, mx(l, m));
	vector<int> p1 = go(l, m, k_);
	vector<int> p2 = go(m, r, k - k_);
	for(int &x : p1) x += p2.size();
	for(int x : p2) p1.pb(x);
	return p1;
}

int main() {
	int i, j, k;
	rd(n); rd(k);
	if(mx(0, n) < k || !(k & 1)) { puts("-1"); return 0; }
	vector<int> p = go(0, n, k);
	for(int x : p) printf("%d ", x + 1);
	putchar('\n');
}