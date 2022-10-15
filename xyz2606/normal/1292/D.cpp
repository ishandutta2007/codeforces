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

const int N = 10055;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int bak[N], cnt[N], dep[N], fa[N], lca[N], dis[N][N], wt[N];
int main() {
	vector<int> primes;
	for(int i(2); i <= 5000; i++) {
		bool flag = true;
		for(int j(2); j * j <= i; j++) {
			if(i % j == 0) flag = false;
		}
		if(flag) primes.pb(i);
	}
	int n = 10000;
	int tot = 0;
	for(int i(1); i <= 5000; i++) {
		memcpy(bak, cnt, sizeof(cnt));
		if(i >= 2) {
			int x = i;
			for(int j(0); j < (int)primes.size(); j++) {
				while(x % primes[j] == 0) {
					cnt[j]++;
					tot++;
					x /= primes[j];
				}
			}
		}
		dep[i * 2] = tot;
		int cur = 0;
		for(int j(primes.size() - 1); j >= 0; j--) {
			if(cnt[j] != bak[j]) {
				cur += bak[j];
				break;
			}else {
				cur += cnt[j];
			}
		}
		if(i == 1) continue;
		int p = i * 2 - 2;
		while(p != 2) {
			//cout << p << endl;
			int f = fa[p];
			if(dep[f] >= cur) {
				p = f;
			}else {
				p = f;
				break;
			}
		}
		//if(dep[p] > cur) {
			fa[i * 2 - 1] = p;
			dep[i * 2 - 1] = cur;
			fa[i * 2] = i * 2 - 1;
		//}else {
		//	fa[i] = p;
		//}
		lca[i * 2 - 1] = cur;
		lca[i * 2] = cur;
	}
	for(int i(2); i <= n; i++) {
		int l = 9999999;
		for(int j(i + 1); j <= n; j++) {
			l = min(l, lca[j]);
			dis[i][j] = dep[i] + dep[j] - 2 * l;
			dis[j][i] = dis[i][j];
		}
	}
	int Q;
	scanf("%d", &Q);
	for(int i(1); i <= Q; i++) {
		int x;
		scanf("%d", &x);
		if(x == 0) x = 1;
		wt[x * 2]++;
	}
	LL ans = 1e18;
	for(int i(2); i <= n; i++) {
		LL tmp = 0;
		for(int j(1); j <= 5000; j++) {
			tmp = tmp + (LL)dis[i][j * 2] * wt[j * 2];
		}
		ans = min(ans, tmp);
	}
//	cout << n << endl;
	cout << ans << endl;
}