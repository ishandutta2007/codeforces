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

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

const int N = 1123456;
int a[N], p[N], st[N], sn, mrk[N];


int main() {
	int i, j, n, k;
	rd(n); rd(k);
	for(i = 0; i < n; i++)
		rd(a[i]);
	p[sn] = n;
	st[sn++] = -1;
	bool any = false;
	for(i = n - 1; i >= 0; i--) {
		while(st[sn - 1] >= a[i])
			mrk[p[--sn]] = 0;
		if(p[sn - 1] - i > k) {
			int r = i + k, l = p[sn - 1] - k;
			if(any || p[sn - 1] == n || l > r) {
				puts("NO");
				return 0;
			}
			//printf("%d->%d[%d]\n", i, p[sn - 1], sn - 1);
			for(j = sn - 2; j > 0; j--)
				if(p[j - 1] - p[j + 1] <= k)
					break;
			if(j > 0) {
				//printf("rm [%d] = %d\n", p[j], st[j]);
				int sst = st[j];
				for(int g = j; g < sn - 1; g++) {
					st[g] = st[g + 1];
					p[g] = p[g + 1];
				}
				sn--;
				//printf("add [%d] = %d\n", xi, sst);
				p[sn] = l;
				st[sn++] = sst;
			} else {
				for(j = p[sn - 1] + 1; j < n; j++)
					if(!mrk[j] && a[j] < a[i])
						break;
				if(j == n) {
					int d = p[sn - 2] - p[sn - 1];
					//printf("ext [%d] by %d\n", p[sn - 1], k -d);
					p[sn - 1] -= (k - d);
				} else {
					//printf("[%d] to-> [%d]\n", j, xi);
					p[sn] = l;
					st[sn++] = a[j];
				}
			}
			if(p[sn - 1] - i > k) {
				puts("NO");
				return 0;
			}
			any = true;
		}
		mrk[i] = 1;
		p[sn] = i;
		st[sn++] = a[i];
	}
	puts("YES");
}