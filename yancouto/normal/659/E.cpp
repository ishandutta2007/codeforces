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
const int N = 112345;
int S[N], sz[N], ok[N];

int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

void join(int a, int b) {
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
	ok[a] |= ok[b];
}

int main() {
	int i, n, m, a, b;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) S[i] = i, sz[i] = 1;
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if((a = find(a)) != (b = find(b))) join(a, b);
		else ok[a] = true;
	}
	int tot = 0;
	for(i = 1; i <= n; i++)
		if(S[i] == i && !ok[i])
			tot++;
	printf("%d\n", tot);
}