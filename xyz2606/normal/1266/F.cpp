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
#include<chrono>
using namespace std;
typedef long long LL;
mt19937 gene(233);
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

const int N = 500033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> e[N];
vector<int> vv[N], nxt[N];
int vst[N], fa[N], ans[N], a1[N], fl[999][999], siz[N], dep[N], d2[N], up[N];
int debug = 0;
int main() {
	if(debug) {
		n = 500000;
		/*for(int i(1); i <= n; i++) {
			for(int j(1); j <= n; j++) if(i != j) fl[i][j] = inf;
		}*/
	}else{
		scanf("%d", &n);
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator (seed);
	for(int i(1); i < n; i++) {
		int x, y;
		if(debug) {
			x = 1; y = i + 1;
			//x = i + 1;
			//y = generator() % i + 1;
			//printf("%d %d\n", x, y);
		}else {
			scanf("%d%d", &x, &y);
		}
		e[x].pb(y);
		e[y].pb(x);
		/*if(debug) {
			fl[x][y] = 1;
			fl[y][x] = 1;
		}*/
	}
	vector<int> q;
	q.pb(1);
	vst[1] = 1;
	for(int op = 0; op < n; op++) {
		int v = q[op];
		for(int y : e[v]) {
			if(!vst[y]) {
				fa[y] = v;
				vst[y] = 1;
				q.pb(y);
			}
		}
	}
	for(int i(n - 1); i >= 0; i--) {
		int v = q[i];
		int nw = dep[v] + 1;
		siz[v] ++;
		siz[fa[v]] += siz[v];
		if(nw > dep[fa[v]]) {
			d2[fa[v]] = dep[fa[v]];
			dep[fa[v]] = nw;
		}else if(nw > d2[fa[v]]) d2[fa[v]] = nw;
	}
	ans[n] = 1;
	for(int v : q) {
		up[v] = v == 1 ? 0 : up[fa[v]] + 1;
		if(v != 1) up[v] = max(up[v], dep[v] + 1 == dep[fa[v]] ? d2[fa[v]] + 1 : dep[fa[v]] + 1);
		vector<int> vec;
		vec.push_back(up[v]);
		for(int y : e[v]) {
			if(fa[y] == v) vec.push_back(dep[y] + 1);
		}
		if(up[v] != 0) {
			vec.push_back(0);
		}
		sort(vec.begin(), vec.end());
		for(int i(0); i < (int)vec.size(); i++) {
			//printf("%d ", vec[i]);
			ans[vec[i] * 2] = max(ans[vec[i] * 2], (int)vec.size() - i);
			if(i && vec[i - 1] < vec[i]) {
				ans[vec[i - 1] * 2 + 1] = max(ans[vec[i - 1] * 2 + 1], (int)vec.size() - i + 1);
			}
		}
		//printf("\n");
		vv[v] = vec;
	}
	for(int i(n - 1);  i>= 1; i--) ans[i] = max(ans[i], ans[i + 1]);
	for(int i(1); i <= n; i++) {
		nxt[i] = vv[i];
		for(int j(0), k; j < (int)vv[i].size(); j = k) {
			for(k = j; k < (int)vv[i].size() && vv[i][j] == vv[i][k]; k++);
			for(int l = j; l < k; l++) nxt[i][l] = k;
		}
	}
	for(int v : q) {
		if(!fa[v]) continue;
		for(int i(0), p(0); i < (int)vv[v].size(); i = nxt[v][i]) {
			int cnt = vv[v].size() - i;
			int lb = vv[v][i];
			if(lb > siz[v] || lb > n - siz[v]) break;
			if(lb == 0) continue;
			if(up[v] - 1 >= lb) cnt--;
			if(cnt <= 0) continue;
			while(p < (int)vv[fa[v]].size() && vv[fa[v]][p] < lb) p++;
			cnt += (int)vv[fa[v]].size() - p;
			cnt--;
			ans[lb * 2] = max(ans[lb * 2], cnt);
		}
		for(int i(0), p(0); i < (int)vv[fa[v]].size(); i = nxt[fa[v]][i]) {
			int cnt = vv[fa[v]].size() - i;
			int lb = vv[fa[v]][i];
			if(lb > siz[v] || lb > n - siz[v]) break;
			if(lb == 0) continue;
			if(dep[v] >= lb) cnt--;
			while(p < (int)vv[v].size() && vv[v][p] < lb) p++;
			cnt += (int)vv[v].size() - p;
			cnt--;
			ans[lb * 2] = max(ans[lb * 2], cnt);
		}
	}
	for(int i = (n - 1) / 2 * 2; i >= 0; i -= 2) ans[i] = max(ans[i], ans[i + 2]);
	for(int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');

	/*if(debug) {
	  for(int k(1); k <= n; k++) {
	  a1[k] = 1;
	  for(int i(1); i <= n; i++) {
	  for(int j(1); j <= n; j++) {
	  fl[i][j] = min(fl[i][j], fl[i][k] + fl[k][j]);
	  }
	  }
	  }
	  for(int msk = 1; msk < (1 << n); msk++) {
	  int mn = inf, mx = -1;
	//cout << msk << endl;
	for(int i(1); i <= n; i++) {
	if(!((msk >> (i - 1)) & 1)) continue;
	for(int j(1); j <= n; j++) {
	if(!((msk >> (j - 1)) & 1)) continue;
	if(i == j) continue;
	mn = min(mn, fl[i][j]);
	mx = max(mx, fl[i][j]);
	}
	}
	int cc = __builtin_popcount(msk);
	if(cc <= 1) continue;
	//cout << mn << ' ' << mx << endl;
	if(mn == mx) {
	a1[mn] = max(a1[mn], cc);
	a1[mn - 1] = max(a1[mn - 1], cc);
	}else if(mn == mx - 1) {
	a1[mn] = max(a1[mn], cc);
	}
	}
	for(int i(1); i <= n; i++) printf("%d%c", a1[i], i == n ? '\n' : ' ');
	for(int i(1); i <= n; i++) assert(a1[i] == ans[i]);
	}*/
}