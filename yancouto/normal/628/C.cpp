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

char s[100009];
int main() {
	int i, n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for(i = 0; i < n; i++) {
		if(k <= 27 && (s[i] + k <= 'z' || s[i] - k >= 'a')) {
			if(s[i] + k <= 'z') s[i] += k;
			else s[i] -= k;
			k = 0;
		} else if('z' - s[i] >= s[i] - 'a')
			k -= 'z' - s[i], s[i] = 'z';
		else
			k -= s[i] - 'a', s[i] = 'a';
	}
	if(k) puts("-1");
	else puts(s);
}