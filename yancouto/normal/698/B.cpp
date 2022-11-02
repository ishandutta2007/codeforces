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
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif
const int N = 212345;
int p[N], he[N], seen[N], t;

int main() {
	int i, j, n, tot = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
		he[i] = -1;
	}
	for(j = 0; j < n; j++) {
		i = j;
		if(seen[i]) continue;
		t++;
		while(!seen[i]) {
			seen[i] = t;
			i = p[i];
		}
		if(seen[i] < t) continue;
		he[i] = i;
	}
	for(j = 0; j < n; j++)
		if(he[j] == j && p[j] == j)
			break;
	if(j == n) for(j = 0; he[j] != j; j++);
	if(p[j] != j) tot++, p[j] = j;
	for(i = 0; i < n; i++)
		if(i != j && he[i] == i)
			p[i] = j, tot++;
	printf("%d\n", tot);
	for(i = 0; i < n; i++)
		printf("%d ", p[i] + 1);
	putchar('\n');
}