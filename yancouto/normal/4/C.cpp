#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif

map<string, int> mp;
char s[100], x[100];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", s);
		if(!mp.count(s)) {
			puts("OK");
			mp[s] = 1;
			continue;
		}
		for(j = mp[s]; ; j++) {
			sprintf(x, "%s%d", s, j);
			if(!mp.count(x)) {
				printf("%s\n", x);
				mp[x] = 1;
				break;
			}
		}
		mp[s] = j + 1;
	}
}