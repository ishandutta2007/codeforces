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

const int N = 500055;
const int LOG = 20;
const int mod = 998244353;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int primes[N], isp[N], mnp[N];
//vector<int> fac[N];
int dp[N][LOG];
int fac[N], invfac[N];
int main() {
	int n, k;
	cin >> n >> k;
	fac[0] = 1;
	invfac[0] = 1;
	for(int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * (LL)i % mod;
		invfac[i] = fastpo(fac[i], mod - 2, mod);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(n / i - 1 >= k - 1) ans = (ans + (LL)fac[n / i - 1] * invfac[k - 1] % mod * invfac[n / i - 1 - (k - 1)]) % mod;
	}
	cout << ans << endl;
	/*fill(isp, isp + n + 1, true);
	isp[1] = false;
	primes[0] = inf;
	int np = 0;
	for(int i = 2; i <= n; i++) {
		if(isp[i]) {
			primes[++np] = i;
			mnp[i] = i;
		}
		for(int j = 1; j <= np && primes[j] * i <= n && i % primes[j - 1]; j++) {
			isp[primes[j] * i] = false;
			mnp[primes[j] * i] = primes[j];
		}

	}
	for(int i = 1; i <= n; i++) {
		//cout << i << ' ' << mnp[i] << endl;
		if(i == 1) {
			fac[i].pb(1);
		}else {
			for(int j : fac[i / mnp[i]]) {
				fac[i].pb(j);
				fac[i].pb(j * mnp[i]);
			}
			sort(fac[i].begin(), fac[i].end());
			fac[i].resize(unique(fac[i].begin(), fac[i].end()) - fac[i].begin());
		}
		//cout << i << ' ' << fac[i].size() << endl;
		dp[i][1] = 1;
		for(int l = 2; l <= k; l++) { 
			for(int j : fac[i]) {
				if(j == i) continue;
				dp[i][l] = (dp[i][l] + dp[j][l - 1]) % mod;
				
			}
		}
		for(int l = 1; l <= k; l++) printf("dp[%d][%d] = %d\n", i, l, dp[i][l]);
		ans = (ans + dp[i][k]) % mod;
	}
	cout << ans << endl;*/
}