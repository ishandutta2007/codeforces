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

const int N = 3033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> e[N];
int vst[N], dis[N][N], siz[N][N];
LL dp[N][N];
int fa[N];
int main() {
	int n;
	cin >> n;
	for(int i(1); i < n; i++) {
		int x, y;
		cin >> x >> y;
		e[x].pb(y);
		e[y].pb(x);
	}
	for(int i(n); i >= 1; i--) {
		
		vector<int> q;
		q.push_back(i);
		memset(vst, 0, sizeof(vst));
		memset(fa, 0, sizeof(fa));
		vst[i] = true;
		dis[i][i] = 0;
		for(int op(0); op < (int)q.size(); op++) {
			int v = q[op];
			for(int y : e[v]) {
				if(!vst[y]) {
					dis[i][y] = dis[i][v] + 1;
					q.push_back(y);
					vst[y] = true;
					fa[y] = v;
				}
			}
		}
		
		for(int j(n - 1); j >= 0; j--) {
			int v = q[j];
			siz[i][v]++;
			siz[i][fa[v]] += siz[i][v];
			//printf("siz[%d][%d] = %d\n", i, v, siz[i][v]);
		}
	}
	vector<pair<int, int> > qdp;
	memset(dp, -1, sizeof(dp));
	for(int i(1); i <= n; i++) {
		for(int y : e[i]) {
			dp[i][y] = (LL)siz[i][y] * siz[y][i];
			qdp.push_back({i, y});
		}
	}
	for(int op(0); op < (int)qdp.size(); op++) {
		int v = qdp[op].fi, y = qdp[op].se;
		for(int z : e[v]) {
			if(dis[z][y] > dis[v][y]) {
				if(dp[z][y] == -1) qdp.pb({z, y});

				dp[z][y] = max(dp[z][y], dp[v][y] + (LL)siz[z][y] * siz[y][z]);
			}
		}
		for(int z : e[y]) {
			if(dis[v][z] > dis[v][y]) {
				if(dp[v][z] == -1) qdp.pb({v, z});
				dp[v][z] = max(dp[v][z], dp[v][y] + (LL)siz[v][z] * siz[z][v]);
			}
		}
	}
	LL ans = 0;
	for(int i(1); i <= n; i++) for(int j = 0; j <= n; j++) ans = max(ans, dp[i][j]);
	cout << ans << endl;
}