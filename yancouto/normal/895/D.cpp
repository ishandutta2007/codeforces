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

int n;

int ct[256];
const int N = 1123456;
char a[N], b[N];

ll fat[N], ifat[N];

inline ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

#define div dv
ll div = 1;
int tot = 0;

ll qualquer_merda() {
	return mod(fat[tot] * div);
}

inline void add(int i) {
	div = mod(div * fat[ct[i]]);
	ct[i]++;
	div = mod(div * ifat[ct[i]]);
	tot++;
}

inline void rm(int i) {
	div = mod(div * fat[ct[i]]);
	ct[i]--;
	div = mod(div * ifat[ct[i]]);
	tot--;
}

int main() {
	int i, j;
	fat[0] = 1;
	for(i = 1; i < N; i++)
		fat[i] = mod(ll(i) * fat[i - 1]);
	ifat[N - 1] = fexp(fat[N - 1], modn - 2);
	for(i = N - 2; i >= 0; i--)
		ifat[i] = mod(ifat[i + 1] * ll(i + 1));
	scanf("%s %s", a, b);
	for(i = 0; a[i] == b[i]; i++);
	int n = strlen(a);
	if(i)
		for(j = 0; j < n - i; j++)
			a[j] = a[j + i],
			b[j] = b[j + i];
	n -= i;
	assert(a[0] < b[0]);
	for(i = 0; i < n; i++)
		add(a[i]);
	ll tot = 0;
	for(i = a[0] + 1; i < b[0]; i++) {
		if(!ct[i]) continue;
		rm(i);
		tot += qualquer_merda();
		add(i);
	}
	for(i = 0; i < n - 1; i++) {
		rm(a[i]);
		for(j = a[i + 1] + 1; j <= 'z'; j++) {
			if(!ct[j]) continue;
			rm(j);
			tot += qualquer_merda();
			add(j);
		}
	}
	for(i = 0; i < n - 1; i++) add(a[i]);
	for(i = 0; i < n - 1; i++) {
		if(ct[b[i]] == 0) break;
		rm(b[i]);
		for(j = 'a'; j < b[i + 1]; j++) {
			if(!ct[j]) continue;
			rm(j);
			tot += qualquer_merda();
			add(j);
		}
	}
	printf("%lld\n", mod(tot));
}