#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
const int N = 1000010;
int a[N], b[N], G, md, c[N], cl; int m, tot = 0;
bool vis[N];
#define nxt(x) (x == n ? 1 : x + 1)
#define pre(x) (x == 1 ? n : x - 1)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void work(int n) {
	tot++; if (tot > 60) { printf("-1\n"); return; }
	if (m == n) {
		printf("%d %d\n",md,G >= G * m ? 1 : G);
	} else if (m - 1 == n) {
		rep(i,1,n) if (a[i] != i - 1) { printf("%d %d\n",a[i] * G + md,G); return; }
	} else if (n <= 1000) {
		if (n == 1) { printf("%d %d\n", a[1], 1); return; }
		rep(i,2,n) {
			int d = a[i] - a[1]; if (gcd(d, m) != 1) continue;
			int cnt = 0, j = 1; bool haveans = true;
			rep(k,1,n) {
				int x = (a[k] + d) % m, t = j; j = nxt(j);
				while (j != t && a[j] != x) j = nxt(j);
				if (j == t) { cnt++; if (cnt == 2) { haveans = false; break; }}
			}
			if (haveans) {
				int j = n;  n = cl; d *= G, m *= G;
				dep(k,n,1) {
					int x = (c[k] - d + m) % m, t = j; j = pre(j);
					while (j != t && c[j] != x) j = pre(j);
					if (j == t) { printf("%d %d\n",c[k],d); return; }
				}
				printf("%d %d\n",c[1],d); return;
			}
		}
		printf("-1\n");
	} else {
		bool flag = true;
		while (flag) {
			rep(i,1,n) vis[i] = false;
			int x = rand() % n + 1; vis[x] = true; int j = pre(x), k = nxt(x);
			for(;j != k; j = pre(j)) {
				while (k != j && (a[k] + m - a[x]) % m < (a[x] + m - a[j]) % m) k = nxt(k);
				if ((a[j] + a[k]) % m == 2 * a[x] % m) vis[j] = vis[k] = true;
				if (k == j) break;
			} 
			int l = 0; rep(i,1,n) if (!vis[i]) b[++l] = a[i];
			flag = l < 2; if (!flag) { n = l; rep(i,1,n) a[i] = b[i]; } 
		}
		work(n);
	}
}

void init(int n) {
	int g = gcd(m, a[1] + m - a[n]); rep(i,1,n - 1) g = gcd(g, a[i + 1] - a[i]);
	G = g, md = a[1] % g;
	m /= g; rep(i,1,n) a[i] /= g;
}

int main() {
#ifdef LOCAL
	freopen("C.in","r",stdin);//freopen("C.out","w",stdout);
#endif
	srand(233); int n; scanf("%d%d",&m,&n); cl = n;
	rep(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	rep(i,1,n) c[i] = a[i];
	init(n); work(n);
	return 0;
}