// WAAAAAAAAAAAAAA
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const ll modn2 = 1000000009;
inline ll mod2(ll x) { return x % modn2; }

const int MAX = 1000009;

int p[MAX]; ull h[MAX], h2[MAX], h3[MAX];
ull x[MAX], x2[MAX], x3[MAX];
bool cmp(int i, int j) {
	if(h[i] == h[j]) {
		if(h2[i] == h2[j]) return h3[i] < h3[j];
		return h2[i] < h2[j];
	}
	return h[i] < h[j];
}
int main() {
	int i, j, n, m, a, b;
	scanf("%d %d", &n, &m);
	srand(time(NULL)); rand(); rand();
	for(i = 0; i < n; i++) {
		x[i] = (ull(rand()) << 15) ^ ull(rand()) ^ (ull(rand()) << 5);
		x2[i] = (ull(rand()) << 5) ^ (ull(rand()) << 13) ^ ull(rand());
		x3[i] = ull(rand()) * ull(rand()) + rand();
		p[i] = i;
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		//a = (rand() % n) + 1;
		//b = (rand() % n) + 1;
		//if(b == a) b = (b + 1) % n + 1;
		h[--a] ^= x[--b];
		h3[a] ^= x3[b];
		h2[a] ^= x2[b];
		h[b] ^= x[a];
		h2[b] ^= x2[a];
		h3[b] ^= x3[a];
	}
	sort(p, p + n, cmp);
	ll tot = 0;
	for(i = 0; i < n; ) {
		ll t = 1;
		while(i + t < n && h[p[i]] == h[p[i+t]] && h2[p[i]] == h2[p[i+t]] && h3[p[i]] == h3[p[i+t]]) t++;
		tot += (t * t - t) / 2;
		i += t;
	}
	for(i = 0; i < n; i++) {
		h[i] ^= x[i];
		h2[i] ^= x2[i];
		h3[i] ^= x3[i];
	}
	sort(p, p + n, cmp);
	for(i = 0; i < n; ) {
		ll t = 1;
		while(i + t < n && h[p[i]] == h[p[i+t]] && h2[p[i]] == h2[p[i+t]] && h3[p[i]] == h3[p[i+t]]) t++;
		tot += (t * t - t) / 2;
		i += t;
	}
	printf("%I64d\n", tot);
}