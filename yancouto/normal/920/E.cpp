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

vector<int> unseen;
set<pii> es;

int size;
void go(int u) {
	size++;
	vector<int> can;
	for(int i = 0; i < int(unseen.size());) {
		if(!es.count(pii(u, unseen[i]))) {
			can.pb(unseen[i]);
			swap(unseen[i], unseen.back());
			unseen.pop_back();
		} else i++;
	}
	for(int x : can)
		go(x);
}

int main() {
	int m, a, b;
	int i, j;
	rd(n); rd(m);
	for(i = 0; i < m; i++) {
		rd(a); rd(b); a--; b--;
		es.insert(pii(a, b));
		es.insert(pii(b, a));
	}
	for(i = 0; i < n; i++) unseen.pb(i);
	vector<int> cps;
	while(!unseen.empty()) {
		int x = unseen.back(); unseen.pop_back();
		size = 0;
		go(x);
		cps.pb(size);
	}
	sort(cps.begin(), cps.end());
	printf("%d\n", int(cps.size()));
	for(int x : cps) printf("%d ", x);
	putchar('\n');
}