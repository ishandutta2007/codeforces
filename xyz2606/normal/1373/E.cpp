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
const int LIM = 1000000;
int a[N], s[N];
LL tab[222][22];
int main() {
	/*for(int i = 1; i <= LIM; i++) {
		a[i] = 0;
		int x = i;
		while(x) {
			a[i] += x % 10;
			x /= 10;
		}
		s[i] = s[i - 1] + a[i];
	}
	cout << s[LIM] << endl;
	memset(tab, -1, sizeof(tab));
	for(int n = 1; n <= 150; n++) {
		for(int k = 2; k <= 9; k++) {
			for(int i = 0; i + k <= LIM; i++) {
				if(s[i + k] - (i ? s[i - 1] : 0) == n) {
					tab[n][k] = i;
				}
			}
		}
		LL res = n % 9;
		int x = n - n % 9;
		for(int j = 1; j * 9 <= x; j++) res = res * 10 + 9;
		tab[n][0] = res;

	}
	cout << clock() << endl;*/
	int t;
	cin >> t;
	for(int qq = 1; qq <= t; qq++) {
		int n, k;
		cin >> n >> k;
		LL mn = (inf) * (LL)inf;
		for(int i = 0; i <= 9; i++) {
			int cur = 0;
			int a = 0, b = 0;
			for(int j = 0; j <= k; j++) {
				cur += (i + j) % 10;
				if(i + j < 10) a++;
				else b++;
			}
		//	cout << cur << '?' << n << endl;
			if(cur > n) continue;
			n -= cur;
			for(int j = 0; j <= n; j++) {
				for(int k = j + 1; k >= 0; k -= 9) {
					if(j * a + k * b != n) continue;
					//cout << n << ' ' << j << ' ' << k << endl;
					int n9 = (j + 1 - k) / 9;
					int rmn = j - n9 * 9;
					if(rmn < 0) continue;
					vector<int> v;
					v.pb(rmn % 9);
					LL res = 0;
					for(int l = 1; l * 9 <= rmn; l++) v.pb(9);
					if(v.back() == 9) {
						v.back()--;
						if(v.size() == 1) {
							v.insert(v.begin(), 1);
						}else v[0]++;
					}
					for(int l : v) res = res * 10 + l;
					for(int l = 1; l <= n9; l++) res = res * 10 + 9;
					res = res * 10 + i;
					mn = min(mn, res);
				}
			}
			n += cur;
		}
		if(mn == (inf) * (LL)inf) mn = -1;
		cout << mn << endl;
	}
}