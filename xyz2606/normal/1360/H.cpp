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

const int N = 111;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
LL a[N];
int main() {
	int t;
	cin >> t;
	for(int qq = 1; qq <= t; qq++) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			static char s[111];
			scanf("%s", s);
			LL x = 0;
			for(int i = 0; i < m; i++) {
				x = x * 2 + (s[i] - '0');
			}
			a[i] = x;
		}
		LL le = 0, ri = 1ll << m;
		ri--;
		LL rk = ((1ll << m) - n - 1) / 2 + 1;
		while(le != ri) {
			LL mid = (le + ri) / 2;
			int cnt = 0, ext = 0;
			for(int i = 1; i <= n; i++) cnt += a[i] <= mid, ext |= a[i] == mid;
			if(!ext) {
				if(mid + 1 - cnt >= rk) {
					ri = mid;
				}else le = mid + 1;
			}else {
				if(mid + 1 - cnt >= rk) {
					ri = mid;
				}else le = mid + 1;
			}
		}
		for(int i = 0; i < m; i++) printf("%d", (le >> (m - 1 - i)) & 1);
		printf("\n");
	}
}