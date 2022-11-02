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

int a[502];
int main() {
	int i, j, n, x;
	multiset<int> s;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			scanf("%d", &x);
			s.insert(x);
		}
	for(int i = 0; i < n; i++) {
		a[i] = *s.rbegin();
		s.erase(s.find(a[i]));
		for(int j = 0; j < i; j++) {
			s.erase(s.find(__gcd(a[i], a[j])));
			s.erase(s.find(__gcd(a[i], a[j])));
		}
		printf("%d ", a[i]);
	}
	putchar('\n');
}