#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}

inline string itoa(int x, int width = 0) {
  string res;
  if(x == 0) res.push_back('0');
  while(x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  while((int)res.size() < width) res.push_back('0');
  reverse(res.begin(), res.end());
  return res;
}

const int N = 100011;
const int LOG = 17;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
LL a[N];
vector<int> e[N];
int fa[N], dep[N], go[N][LOG];
LL g[N][LOG];
LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i(1); i <= n; i++) cin >> a[i];
	for(int i(1); i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	vector<int> q;
	q.push_back(1);
	fa[1] = 0;
	dep[1] = 0;
	for(int op(0); op < (int)q.size(); op++) {
		int v = q[op];
		for(int u : e[v]) {
			if(u != fa[v]) {
				q.push_back(u);
				fa[u] = v;
				dep[u] = dep[v] + 1;
			}
		}
	}
	int ans = 0;
	for(int i(0); i < n; i++) {
		int v = q[i];
		g[v][0] = gcd(a[v], a[fa[v]]);
		go[v][0] = fa[v];
		for(int j(1); j < LOG; j++) {
			go[v][j] = go[go[v][j - 1]][j - 1];
			g[v][j] = gcd(g[v][j - 1], g[go[v][j - 1]][j - 1]);
		}
		int u = v;
		LL cur = a[v];
		for(; u != 0;) {
			int len = 1;
			for(int j(LOG - 1); j >= 0; j--) {
				if(dep[u] - (1 << j) >= 0 && gcd(cur, g[u][j]) == cur) {
					len += 1 << j;
					u = go[u][j];
				}
			}
			ans = (ans + (LL)len * cur % mod) % mod;
			u = fa[u];
			cur = gcd(cur, a[u]);
		}
	}
	printf("%d\n", ans);
}