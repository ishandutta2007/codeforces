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
int a[100], b[100], p[100];

bool ok() {
	int bm;
	for(bm = 1; bm < (1 << n) - 1; bm++) {
		ll sa = 0, sb = 0;
		for(int i = 0; i < n; i++)
			if((bm >> i) & 1)
				sa += a[i],
				sb += b[i];
		if(sa == sb) break;
	}
	if(bm == (1 << n) - 1) {
		return true;
	}
	return false;
}

int main() {
	srand(time(NULL));
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]), p[i] = i;
	sort(p, p + n, [](int i, int j) { return a[i] < a[j]; });
	for(i = 0; i < n - 1; i++)
		b[p[i]] = a[p[i + 1]];
	b[p[n - 1]] = a[p[0]];
	assert(ok());
	for(i = 0; i < n; i++) printf("%d%c", b[i], " \n"[i == n - 1]);
	return 0;
	for(i = 0; i < n; i++) a[i] = b[i] = i;
	int ct = 0;
	while(true) {
		for(i = 0; i < n; i++) b[i] = a[i];
		if(ct == 0) {
			for(i = 0; i < n - 1; i++) b[i] = a[i + 1];
			b[n - 1] = a[0];
		} else {
			for(i = 0; i < n - 1; i++) {
				int j = (rand() % (n - i - 1)) + i + 1;
				swap(b[i], b[j]);
			}
		}
		if((++ct % 10000) == 0) printf("Tried %d\n", ct);
	}
}