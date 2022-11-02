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

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int mn;
	mn = min(a * 2 + b * 2, a + b + c);
	mn = min(mn, 2 * a + 2 * c);
	mn = min(mn, 2 * b + 2 * c);
	printf("%d\n", mn);
}