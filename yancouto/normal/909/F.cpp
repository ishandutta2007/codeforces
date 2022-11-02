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

void verify1(vector<int> p) {
	for(int i = 1; i < p.size(); i++)
		assert(p[i] != i && ((p[i] & i) == 0));
}

vector<int> solve1(int n) {
	if(!(n & (n + 1))) return vector<int>();
	int k = 1;
	while((1 << (k + 1)) - 1 <= n) k++;
	vector<int> p(n + 1);
	p[(1 << k) - 1] = (1 << k);
	p[(1 << k)] = (1 << k) - 1;
	for(int i = 1; i < (1 << k); i++) {
		int x = i ^ ((1 << k) - 1);
		if((1 << k) + x <= n) p[i] = (1 << k) + x;
		else p[i] = x;
	}
	if(n == (1 << k)) { verify1(p); return p; }
	vector<int> q = solve1(n - (1 << k));
	if(q.empty()) return q;
	for(int i = (1 << k) + 1; i <= n; i++)
		p[i] = q[i - (1 << k)];
	verify1(p);
	return p;
}

void verify2(vector<int> p) {
	for(int i = 1; i < p.size(); i++)
		assert(p[i] != i && ((p[i] & i) != 0));
}

vector<int> solve2(int n) {
	if(n <= 5) return vector<int>();
	vector<int> p(n + 1);
	p[1] = 5;
	p[5] = 1;
	p[2] = 3;
	p[3] = 2;
	for(int i = 4; i <= n; ) {
		vector<int> all;
		int j;
		for(j = i; j <= n && (j & i); j++)
			if(j != 5)
				all.pb(j);
		if(all.size() == 1) return vector<int>();
		for(int i = 0; i < all.size(); i++)
			p[all[i]] = all[(i + 1) % all.size()];
		i = j;
	}
	verify2(p);
	return p;
}

int n;
int main() {
	int i, j;
	scanf("%d", &n);
	vector<int> p = solve1(n);
	if(p.empty()) puts("NO");
	else {
		puts("YES");
		for(int i = 1; i <= n; i++) printf("%d ", p[i]); putchar('\n');
	}
	p = solve2(n);
	if(p.empty()) puts("NO");
	else {
		puts("YES");
		for(int i = 1; i <= n; i++) printf("%d ", p[i]); putchar('\n');
	}
}