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
template<const LL mod> struct MI{
	LL a;
	MI operator + (const MI & b) {
		MI res{a + b.a};
		if(res.a >= mod) res.a -= mod;
		return res;
	}
	MI operator - (const MI & b) {
		MI res{a - b.a};
		if(res.a <= 0) res.a += mod;
		return res;
	}
	MI operator * (const MI & b) {
		return MI{a * b.a % mod};
	}
	MI operator / (const MI & b) {
		return MI{a * fastpo(b.a, mod - 2, mod) % mod};
	}
};
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, x;
		cin >> n >> x;
		int cnt[2] = {0, 0};
		for(int j = 0; j < n; j++) {
			int y;
			cin >> y;
			cnt[y % 2]++;
		}
		if(cnt[1] % 2 == 0) cnt[1]--;
		if(cnt[1] >= 0 && cnt[0] + cnt[1] >= x && !(cnt[0] == 0 && x % 2 == 0)) {
			cout << "Yes" << endl;
		}else cout << "No" << endl;

	}
}