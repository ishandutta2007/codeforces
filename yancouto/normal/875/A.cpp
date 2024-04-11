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

int sum(int x) {
	int s = 0;
	while(x) {
		s += (x % 10);
		x /= 10;
	}
	return s;
}

int main() {
	int i, j;
	scanf("%d", &n);
	vector<int> ans;
	for(i = 1; i <= 100 && i <= n; i++) {
		if(sum(n - i) == i)
			ans.pb(n - i);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", int(ans.size()));
	for(int x : ans)
		printf("%d\n", x);
}