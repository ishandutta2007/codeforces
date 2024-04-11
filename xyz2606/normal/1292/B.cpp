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
const LL LIM = 3 * 1e16;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
	LL x0, y0, ax, ay, bx, by;
	vector<pair<LL, LL> > p;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	do {
		p.push_back({x0, y0});
		x0 = ax * x0 + bx;
		y0 = ay * y0 + by;
	} while(x0 <= LIM && y0 <= LIM);
	LL xs, ys, t;
	cin >> xs >> ys >> t;
	vector<LL> d;
	for(int i(0); i < (int)p.size() - 1; i++) {
		d.push_back(abs(p[i].fi - p[i + 1].fi) + abs(p[i].se - p[i + 1].se));
	}
	//cout << t << endl;
	int ans = 0;
	for(int i(0); i < (int)p.size(); i++) {
		int cnt = 1;
		LL tmp = abs(xs - p[i].first) + abs(ys - p[i].second);
		
		for(int j(i); j >= 0 && tmp <= LIM; j--) {
		//cout << tmp << endl;
			if(tmp <= t) ans = max(ans, cnt);
			if(j > 0) tmp += d[j - 1];
			cnt++;
		}
		//cout << "--" << endl;
		cnt = 1;
		tmp = abs(xs - p[i].first) + abs(ys - p[i].second);
		for(int j(i); j < (int)p.size() && tmp <= LIM; j++) {
			if(tmp <= t) ans = max(ans, cnt);
			if(j < (int)p.size() - 1) tmp += d[j];
			cnt++;
		}
	}
	cout << ans << endl;
}