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

int n, m, k;
int a[1123][1123];

int main() {
	int i, j;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	int tot = 0, totrm = 0;
	for(j = 0; j < m; j++) {
		set<int> nx;
		int best = 0, br = 0;
		int all = 0;
		for(i = 0; i < n; i++) all += a[i][j];
		for(i = n - 1; i >= 0; i--) {
			if(!nx.empty() && *nx.rbegin() == i + k) nx.erase(*nx.rbegin());
			if(a[i][j]) all--, nx.insert(i);
			if(nx.size() > best) best = nx.size(), br = all;
			else if(nx.size() == best) br = min(br, all);
		}
		tot += best; totrm += br;
	}
	printf("%d %d\n", tot, totrm);
}