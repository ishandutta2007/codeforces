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
int n, m, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int x[N], y[N], a[N], mxx[N], mxy[N];
vector<int> e[N];
void calc(int * dis, int v) {
	static vector<int> q;
	q.clear();
	q.push_back(v);
	for(int i(1); i <= n; i++) dis[i] = inf;
	dis[v] = 0;
	for(int op = 0; op < (int)q.size(); op++) {
		int v = q[op];
		for(int y : e[v]) {
			if(dis[y] == inf) {
				dis[y] = dis[v] + 1;
				q.pb(y);
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i(1); i <= k; i++) scanf("%d", &a[i]);
	for(int i(1); i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].pb(y);
		e[y].pb(x);
	}
	calc(x, 1);
	calc(y, n);
	vector<pair<int, int> > vec;
	for(int i(1); i <= k; i++) {
		vec.pb({x[a[i]] - y[a[i]], a[i]});
	}
	sort(vec.begin(), vec.end());
	for(int i(0); i < k; i++) {
		mxx[i] = i ? max(mxx[i - 1], x[vec[i].se]) : x[vec[i].se];
	}
	for(int i(k - 1); i >= 0; i--) 
		mxy[i] = i == k - 1 ?  y[vec[i].se] : max(mxy[i + 1], y[vec[i].se]);
	int p = 0;
	int ans = 0;
	for(int i(0); i < k; i++) {
		if(i) ans = max(ans, mxx[i - 1] + y[vec[i].se]);
		if(i + 1 < k)  ans = max(ans, mxy[i + 1] + x[vec[i].se]);
	}
	cout << min(ans + 1, x[n]) << endl;
}