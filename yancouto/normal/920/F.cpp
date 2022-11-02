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

const int N = 312345;
ll bit[N];
void add(int i, ll x) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] += x;
}
ll get(int i) {
	ll sum = 0;
	for(i += 2; i; i -= (i & - i))
		sum += bit[i];
	return sum;
}

const int M = 1000009;
int ps[M], dvs[M];

int a[N];

int main() {
	int i, j;
	for(i = 1; i < M; i++) dvs[i] = 1;
	for(i = 2; i < M; i++)
		if(ps[i] == 0)
			for(j = i; j < M; j += i) {
				ps[j] = i;
				int x = j, tm = 0;
				while(!(x % i)) x /= i, tm++;
				dvs[j] *= (tm + 1);
			}
	int m;
	rd(n); rd(m);
	set<int> s;
	for(i = 0; i < n; i++) {
		rd(a[i]);
		add(i, a[i]);
		if(a[i] > 2) s.insert(i);
	}
	int t, l, r;
	while(m--) {
		rd(t); rd(l); rd(r); l--; r--;
		if(t == 1) {
			auto it = s.lower_bound(l);
			while(it != s.end() && *it <= r) {
				i = *it;
				add(i, -a[i]);
				a[i] = dvs[a[i]];
				add(i, a[i]);
				if(a[i] > 2) ++it;
				else it = s.erase(it);
			}
		} else {
			printf("%lld\n", get(r) - get(l - 1));
		}
	}
}