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

const int N = 112345, L = 42;
int oc[L+10], ex[L+10]; ll a[N];

int n;

void rem1(int &i) {
	while(!ex[i]) i--;
	ex[i]--;
}

int main() {
	int i, j;
	rd(n);
	vector<ll> extra;
	for(i = 0; i < n; i++) {
		rd(a[i]);
		if(a[i] & (a[i] - 1ll)) { extra.pb(a[i]); continue; }
		oc[__builtin_ctzll(a[i])]++;
	}
	for(i = 1; i < L; i++)
		while(oc[i] > oc[i - 1]) {
			oc[i]--;
			extra.pb(1ll << i);
		}
	for(i = 0; i < L; i++)
		ex[i] = oc[i] - oc[i + 1];
	sort(extra.begin(), extra.end());
	for(i = L - 1; i >= 0 && !extra.empty(); i--) {
		for(; ex[i] && !extra.empty(); ex[i]--) {
			if(extra.back() > (1ll << (i + 1))) { puts("-1"); return 0; }
			extra.pop_back();
		}
	}
	if(!extra.empty()) { puts("-1"); return 0; }
	deque<int> ans;
	ans.pb(oc[0]);
	int tot = accumulate(ex, ex + L, 0);
	int ri = L - 1;
	for(i = 0; i < L && (tot - 1) >= (i + 1); i++) {
		while(ex[i] && (tot - 1) >= (i + 1)) {
			//printf("ex[%d] = %d tot %d\n", i, ex[i], tot);
			tot -= (i + 1) + 1;
			ex[i]--;
			for(j = 0; j < i + 1; j++) rem1(ri);
			ans.push_front(--oc[0]);
		}
	}
	for(int x : ans) printf("%d ", x);
	putchar('\n');
}