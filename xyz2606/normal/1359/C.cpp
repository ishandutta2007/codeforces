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
int main() {
	int te;
	cin >> te;
	for(int i = 0; i < te; i++) {
		LL h, c, t;
		cin >> h >> c >> t;
		LL ans = 0;
		if(2 * t == h + c) {
			ans = 2;
		}else {
		//(h + c) / 2
		//2k+1: (h * (k + 1) + c * k) / (2k + 1)
		//=(h + c) / 2 + 0.5 / (2k+1) * (h - c) >= t
			LL k1 = (h - c) / (2 * t - (h + c));
			if(k1 % 2 == 0) k1--;
			//cout << k1 << endl;
			//cout << (h + c) / 2 + 0.5 / k1 * (h - c) << ' ' << (h + c) / 2 + 0.5 / (k1 + 2) * (h - c) << endl;
			//cout << (h + c) * k1 * (k1 + 2) + (h - c) * (k1 + 2) - 2 * t * k1 * (k1 + 2) << ' ' << 2 * t * k1 * (k1 + 2) - (h + c) * k1 * (k1 + 2) - k1 * (h - c) << endl;
			if((h + c) * k1 * (k1 + 2) + (h - c) * (k1 + 2) - 2 * t * k1 * (k1 + 2) > 2 * t * k1 * (k1 + 2) - (h + c) * k1 * (k1 + 2) - k1 * (h - c)) {
				k1 += 2;
			}
			ans = 2;
			//cout << k1 << endl;
			if(abs((h + c) * k1 + (h - c) - 2 * t * k1) < abs((h + c) - t * 2) * k1) {
				ans = k1;
			}
		}
		cout << ans << endl;
	}
}