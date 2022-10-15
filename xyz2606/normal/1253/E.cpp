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
int p[N], l[N], o[N], dp[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(0); i < n; i++) {
		scanf("%d%d", &p[i], &l[i]);
		o[i] = i;
	}
	sort(o, o + n, [&](int x, int y) { return p[x] < p[y]; });
	int op = 0;
	memset(dp, 0x7f, sizeof(dp));
	int ans = inf;
	dp[0] = 0;
	for(int i(1); i <= m; i++) {
		ans = min(ans, dp[i - 1] + m - i + 1);
		while(op < n && p[o[op]] < i) {
			op++;
		}
	
		for(int j(op); j < n; j++) {
			int delta = max(0, p[o[j]] - l[o[j]] - i);
			int nxt = p[o[j]] + l[o[j]] + delta;
			for(int k(op); k < n; k++) {
				if(p[o[k]] <= nxt) {
					nxt = max(nxt, p[o[k]] + l[o[k]]);
				}
			}
			nxt = min(nxt, m);
			dp[nxt] = min(dp[nxt], dp[i - 1] + delta);
			//cout << i << ' ' << delta << ' ' << nxt << endl;
			//cout << dp[i - 1] << endl;
		}
	}
	ans = min(ans, dp[m]);
	cout << ans << endl;

}