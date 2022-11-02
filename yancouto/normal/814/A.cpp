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
int a[1123], b[1123];

int main() {
	int i, j = 0, k;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 0; i < k; i++) scanf("%d", &b[i]);
	sort(b, b + n, greater<int>());
	for(i = 0; i < n; i++)
		if(!a[i])
			a[i] = b[j++];
	for(i = 0; i < n - 1; i++)
		if(a[i] >= a[i + 1])
			break;
	if(i < n - 1) puts("Yes");
	else puts("No");
}