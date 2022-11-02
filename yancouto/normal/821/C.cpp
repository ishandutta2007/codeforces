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

const int N = 312345;
int st[N], sn;
bool ord[N];
char op[100];
int main() {
	int i, x;
	scanf("%d", &n);
	int tot = 0; int nx = 0;
	for(i = 0; i < 2 * n; i++) {
		scanf("%s", op);
		if(op[0] == 'a') {
			scanf("%d", &x);
			ord[sn] = false;
			st[sn++] = x;
		} else {
			nx++;
			sn--;
			if(!ord[sn] && st[sn] != nx) { tot++; ord[sn] = true; }
			if(sn) ord[sn - 1] |= ord[sn];
		}
	}
	printf("%d\n", tot);
}