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

int dist[2123456];
int *d = dist + 1123456;
int a[1123456];

int main() {
	int i, j, k;
	scanf("%d %d", &n, &k);
	for(i = 0; i < k; i++)
		scanf("%d", &a[i]), a[i] -= n;
	sort(a, a + k);
	k = unique(a, a + k) - a;
	queue<int> q;
	for(i = 0; i < k; i++)
		d[a[i]] = 1, q.push(a[i]);
	while(!q.empty() && clock() < .9 * CLOCKS_PER_SEC) {
		int x = q.front(); q.pop();
		if(x == 0) {
			printf("%d\n", d[0]);
			return 0;
		}
		for(i = 0; i < k; i++)
			if(abs(x + a[i]) < 1100000 && d[x + a[i]] == 0) {
				d[x + a[i]] = d[x] + 1;
				q.push(x + a[i]);
			}
	}
	puts("-1");
}