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
LL a[N];
int main() {
	int n; LL x;
	cin >> n >> x;
	vector<LL> v;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
		v.push_back(a[i]);
		if(a[i] - x >= 0) v.push_back(a[i] - x);
		v.push_back(a[i] + x);
	}
	for(int i = 1; i <= n; i++) {
		v.push_back(a[i] + a[n]);
		v.push_back(a[i] - x + a[n]);
		v.push_back(a[i] + x + a[n]);
	}
	sort(v.begin(), v.end());
	vector<LL> s;
	int cur = 1;
	for(int i = 0; i < (int)v.size(); i++) {
		if(i == 0) {
			s.pb(0);
			continue;
		}
		LL x = v[i - 1] % a[n];
		while(!(a[cur - 1] <= x && a[cur] > x)) {
			cur = cur % n + 1;
		}
		s.pb(s.back() + (x + v[i] - v[i - 1] - a[cur - 1]) * (x + v[i] - v[i - 1] - a[cur - 1] + 1) / 2 - (x - a[cur - 1]) * (x - a[cur - 1] + 1) / 2);
		//cout << v[i - 1] << ' '  << v[i] << ' ' << s.back() - s[s.size() - 2] << endl;
	}
	int j = 0;
	LL ans = 0;
	for(int i = 0; i < (int)v.size(); i++) {
		while(j + 1 < (int)v.size() && v[j] - v[i] < x) {
			j++;
		}
		if(v[j] - v[i] == x && v[j] <= 2 * a[n]) ans = max(ans, s[j] - s[i]);

	}
	cout << ans << endl;
}