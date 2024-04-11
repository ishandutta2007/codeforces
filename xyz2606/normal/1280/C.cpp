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

const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > e[N];
LL dis[N];
int vst[N], siz[N], fa[N], fl[N];
int main() {
	int t;
	scanf("%d", &t);
	for(int qq = 1; qq <= t; qq++) {
		int n;
		scanf("%d", &n);
		n *= 2;
		for(int i = 1; i < n; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			e[x].pb({y, z});
			e[y].pb({x, z});
		}
		vector<int> q;
		q.push_back(1);
		fill(vst + 1, vst + 1 + n, false);
		fill(siz + 1, siz + 1 + n, 0);
		vst[1] = true;
		for(int op = 0; op < (int)q.size(); op++) {
			int v = q[op];
			for(auto tmp : e[v]) {
				int y = tmp.fi, z = tmp.se;
				if(!vst[y]) {
					vst[y] = true;
					fa[y] = v;
					fl[y] = z;
					q.push_back(y);
				}
			}
		}
		LL ans = 0;
		int center;
		for(int i(n - 1); i >= 0; i--) {
			int v = q[i];
			siz[v]++;
			siz[fa[v]] += siz[v];
			//cout << v << ' ' << siz[v] << ' ' << fl[v] << endl;
			if(siz[v] % 2) ans += fl[v];
			bool flag = n - siz[v] <= n / 2;
			for(auto tmp : e[v]) {
				int y = tmp.fi;
				if(fa[y] == v && siz[y] > n / 2) flag = false;
			}
			if(flag) center = v;
		}
		printf("%I64d ", ans);
		q.clear();
		q.push_back(center);
		fill(vst + 1, vst + 1 + n, false);
		vst[center] = true;
		dis[center] = 0;
		ans = 0;
		for(int op = 0; op < (int)q.size(); op++) {
			int v = q[op];
			for(auto tmp : e[v]) {
				int y = tmp.fi, z = tmp.se;
				if(!vst[y]) {
					vst[y] = true;
					dis[y] = dis[v] + z;
					ans += dis[y];
					q.push_back(y);
				}
			}
		}
		for(int i(1); i <= n; i++) e[i].clear();
		printf("%I64d\n", ans);
	}
	
}