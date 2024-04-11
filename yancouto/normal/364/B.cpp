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

int all[500009], an, n;
int seen[52][500009], c[52];
void solve(int i, int val) {
	if(seen[i][val]) return;
	seen[i][val] = true;
	if(i == n) {
		all[an++] = val;
		return;
	}
	solve(i + 1, val);
	solve(i + 1, val + c[i]);
}


int main() {
	int i, d;
	scanf("%d %d", &n, &d);
	for(i = 0; i < n; i++)
		scanf("%d", &c[i]);
	solve(0, 0);
	sort(all, all + an);
	int pos = 0, st = 0;
	while(true) {
		int p2 = (upper_bound(all + pos, all + an, all[pos] + d) - all) - 1;
		if(p2 == pos) break;
		pos = p2;
		st++;
	}
	printf("%d %d\n", all[pos], st);
}