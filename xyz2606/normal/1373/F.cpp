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

inline LL fastpo(LL x, LL n, LL mod) {
	LL res(1);
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
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
	fwrite(buf, 1, _bl, stdout);
	_bl = 0;
}
__inline void _putchar(char c) {
	if(_bl == _B) flush();
	buf[_bl++] = c;
}
inline void print(LL x, char c) {
	static char tmp[20];
	int l = 0;
	if(!x) tmp[l++] = '0';
	else {
		while(x) {
			tmp[l++] = x % 10 + '0';
			x /= 10;
		}
	}
	for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
	_putchar(c);
}
const int N = 1000033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N], b[N];
int main() {
	int t;
	t = getInt();
	for(int qq = 1; qq <= t; qq++) {
		int n;
		n = getInt();
		for(int i = 1; i<= n; i++) {
			a[i] = getInt();
		}
		for(int i = 1; i  <= n; i++) {
			b[i] = getInt();
		}
		int le = -1, ri = min(a[1], b[1]);
		bool ans = false;
		while(le != ri) {
			int mid = (le + ri + 1) / 2;
			int rmn = b[1] - mid;
			bool brk = false;
			for(int i = 2; i <= n; i++) {
				if(rmn + b[i] < a[i]) {
					brk = 1;
					break;
				}else {
					rmn = b[i] - max(0, (a[i] - rmn));
				}
			}
		//	printf("%d %d\n", mid, rmn);
			if(brk) {
				ri = mid - 1;
			}else {
				le = mid;
				if(mid + rmn >= a[1]) {
					ans = true;
				}
			}
		}
		printf("%s\n", ans ? "YES" : "NO");

	}
}