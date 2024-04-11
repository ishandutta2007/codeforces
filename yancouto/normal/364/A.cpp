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

int sum[40009];
char s[4009];

int main() {
	int i, j, n, a;
	scanf("%d", &a);
	scanf("%s", s);
	int all = 0;
	for(i = 0; s[i]; i++) {
		int tot = 0;
		for(j = i; s[j]; j++) {
			tot += s[j] - '0';
			sum[tot]++;
			all++;
		}
	}
	if(a == 0) {
		ll ans = 0;
		for(i = 0; s[i]; i++) {
			int tot = 0;
			for(j = i; s[j]; j++) {
				tot += s[j] - '0';
				if(tot) ans += sum[0];
				else ans += all;
			}
		}
		printf("%I64d\n", ans);
		return 0;
	}
	ll ans = 0;
	for(i = 0; s[i]; i++) {
		int tot = 0;
		for(j = i; s[j] && tot <= a; j++) {
			tot += s[j] - '0';
			if(!tot || tot > a) continue;
			if((a % tot) == 0 && (a/tot) < 40009) ans += sum[a / tot];
		}
	}
	printf("%I64d\n", ans);
}