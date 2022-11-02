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
map<int, int> mp;
set<pii> inv;

void dec(int x) {
	inv.erase(pii(mp[x], x));
	mp[x]--;
	if(mp[x] == 0) mp.erase(x);
	else inv.insert(pii(mp[x], x));
}

const int N = 212345;
int a[N][3];

int main() {
	int i, j, x, k = 0;
	read(n);
	for(i = 0; i < n; i++) {
		read(x);
		mp[x]++;
	}
	for(auto e : mp) inv.insert(pii(e.snd, e.fst));
	while(mp.size() >= 3) {
		int v1 = inv.rbegin()->snd;
		int v2 = next(inv.rbegin())->snd;
		int v3 = next(inv.rbegin(),2)->snd;
		a[k][0] = v1; a[k][1] = v2; a[k][2] = v3;
		sort(a[k], a[k] + 3);
		k++;
		dec(v1); dec(v2); dec(v3);
	}
	printf("%d\n", k);
	for(i = 0; i < k; i++)
		printf("%d %d %d\n", a[i][2], a[i][1], a[i][0]);
}