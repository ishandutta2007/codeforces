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

int main() {
	int h1, a1, c1, h2, a2;
	scanf("%d %d %d", &h1, &a1, &c1);
	scanf("%d %d", &h2, &a2);
	vector<int> steps;
	for(int t = 1; ; t++) {
		if(h2 <= a1) {
			steps.pb(1);
			break;
		}
		if(a2 >= h1) {
			h1 += c1 - a2;
			steps.pb(0);
		} else {
			h2 -= a1;
			h1 -= a2;
			steps.pb(1);
		}
	}
	printf("%d\n", int(steps.size()));
	for(int s : steps)
		if(s) puts("STRIKE");
		else puts("HEAL");
}