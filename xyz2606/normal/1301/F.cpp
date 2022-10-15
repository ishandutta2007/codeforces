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

const int N = 1000011;
const int K = 44;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
inline int id(int x, int y) {
	return x * m + y;
}
vector<int> vec[44];
int dis[K][N];
int adj[N][4];
int col[N], done[K];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n * m; i++) {
		scanf("%d", &col[i]);
		vec[col[i]].pb(i);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int d =0; d < 4; d++) {
				int x = i + dx[d], y = j + dy[d];
				if(x >= 0 && x < n && y >= 0 && y < m) {
					adj[id(i, j)][d] = id(x, y);
				}else adj[id(i, j)][d] = -1;
				
			}
		}
	}
	memset(dis, 0x7f, sizeof(dis));
	for(int i = 1; i <= k; i++) {
		static vector<int> q;
		q.clear();
		for(int v : vec[i]) {
			dis[i][v] = 0;
			q.pb(v);
		}
		memset(done, false, sizeof(done));
		done[i] = 1;
		for(int op = 0; op < (int)q.size(); op++) {
			int v = q[op];
				//printf("%d !\n", i);
	for(int p = 0; p < 4; p++) {
				int y = adj[v][p];
				if(y != -1 && dis[i][y] > inf) {
					//printf("%d->%d\n", v, y);
					dis[i][y] = dis[i][v] + 1;
					q.pb(y);
				}
			}
			if(!done[col[v]]) {
				for(int y : vec[col[v]]) {
					if(dis[i][y] > inf) {
						dis[i][y] = dis[i][v] + 1;
						q.pb(y);
					}
				}
				done[col[v]] = 1;
			}
		}
	}
	int Q;
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int ans = abs(x1 -x2) + abs(y1 - y2);
		x1--; y1--; x2--; y2--;
		int v = id(x1, y1), u = id(x2, y2);
		for(int j = 1; j <= k; j++) {
			ans = min(ans, dis[j][v] + dis[j][u] + 1);
		}
		printf("%d\n", ans);
	}
}