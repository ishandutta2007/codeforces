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
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
const int N = 11234;
int oc[N], a[N], b[N];

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 0; i < n; i++) scanf("%d", &b[i]);
	int ok = 0;
	vector<int> w;
	for(i = 0; i < n; i++)
		if(a[i] == b[i])
			ok++, oc[a[i]]++;
		else
			w.pb(i);
	assert(w.size() < 3 && !w.empty());
	if(w.size() == 1) {
		for(i = 1; i <= n && oc[i]; i++);
		a[w[0]] = i;
	} else {
		if(!oc[a[w[0]]] && !oc[b[w[1]]]) a[w[1]] = b[w[1]];
		else {
			assert(!oc[b[w[0]]] && !oc[a[w[1]]]);
			a[w[0]] = b[w[0]];
		}
	}
	for(i = 0; i < n; i++) printf("%d ", a[i]);
	putchar('\n');

}