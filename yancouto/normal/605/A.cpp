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

int a[100009], pos[100009];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	int cur = pos[1], mx = 1, c = 1;
	for(i = 2; i <= n; i++) {
		if(pos[i] > cur) c++;
		else c = 1;
		cur = pos[i];
		mx = max(mx, c);
	}
	printf("%d\n", n - mx);
}