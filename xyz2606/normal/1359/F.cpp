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

const int N = 25555;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
typedef long double D;
D eps = 1e-8;
bool equal(const D & x, const D & y) {
	return x + eps > y && y + eps > x;
}
int sign(const D & x) {
	return (x > eps) - (x + eps < 0);
}
D X;
D v[N];
D pi = acos(-1.);
struct P {
	D x, y;
	void scan() {
		double _x, _y;
		scanf("%lf%lf", &_x, &_y);
		x = _x; y = _y;
	}
	P operator - (const P & b) const { return P{x - b.x, y - b.y}; }
	P operator + (const P & b) const { return P{x + b.x, y + b.y}; }
	D operator * (const P & b) const { return x * b.y - y * b.x; }
	D operator % (const P & b) const { return x * b.x + y * b.y; }
	P rot(const D & t) const {
		D si = sin(t), co = cos(t);
		return P{x * co - y * si, y * co + x * si};
	}
	void print() const { printf("%lf %lf\n", (double)x, (double)y); }
	D sqrlen() const { return x * x + y * y; }
	D len() const { return sqrt(max((D)0., sqrlen())); }
} a[N], d[N], bg[N], ed[N];
P operator * (const D & x, const P & b) { return P{x * b.x, x * b.y}; }
bool onSeg(const P & a, const P & b, const P & c) {
	return sign((a - b) % (a - c)) <= 0;
}
D getY(int a, D x) {
	return bg[a].y + (ed[a].y - bg[a].y) / (ed[a].x - bg[a].x) * (x - bg[a].x);
}
bool check(int x, int y) {
	//printf("check %d %d\n", x, y);
	P a = bg[x], b = ed[x], c = bg[y], d = ed[y];
	if(!sign(::d[x] * ::d[y])) {
		//a.print(); c.print(); ::d[x].print(); printf("%.12f %.12f\n", (double)(a * ::d[x]), (double)(c * ::d[x]));
		//cout << equal(a * ::d[x], c * ::d[x]) << ' ' <<  onSeg(a, c, d) << ' ' << onSeg(b, c, d) << ' ' << onSeg(c, a, b) << ' ' << onSeg(d, a, b) << endl;
		return equal(a * ::d[x], c * ::d[x]) && (onSeg(a, c, d) || onSeg(b, c, d) || onSeg(c, a, b) || onSeg(d, a, b));
	}else {
		return sign((c - a) * ::d[x]) * sign((d - a) * ::d[x]) <= 0 && sign((a - c) * ::d[y]) * sign((b - c) * ::d[y]) <= 0;
	}
}
struct Cmp {
	bool operator () (const int & a, const int & b) {
		D ya = getY(a, X);
		D yb = getY(b, X);
		if(!equal(ya, yb)) {
			return ya < yb;
		}else return a < b;
	}
};
set<int, Cmp> mp;
bool check(D mid) {
	vector<pair<D, int> > v;
	//printf("mid = %lf\n", mid);
	for(int k = 1; k <= n; k++) {
		bg[k] = a[k];
		ed[k] = a[k] + mid * ::v[k] / d[k].len() * d[k];
		if(bg[k].x > ed[k].x) swap(bg[k], ed[k]);
		v.pb(make_pair(bg[k].x, k));
		v.pb(make_pair(ed[k].x, -k));
		//bg[k].print(); ed[k].print();
	}
	sort(v.begin(), v.end(), [&](auto & a, auto & b) {
			if(a.se == b.se * -1) return a.se > b.se;
			else return a.fi < b.fi;
			});

	mp.clear();
	for(auto tmp : v) {
		X = tmp.fi;
		int v = abs(tmp.se);
		//printf("!%d\n", tmp.se);
		if(tmp.se > 0) {
			//cout << mp.size() << endl;
			bg[n + 1] = P{X - 1, bg[v].y};
			ed[n + 1] = P{X + 1, bg[v].y};

			auto itr = mp.lower_bound(n + 1);
			if(itr != mp.end()) {
				if(check(*itr, v)) return true;
				auto itr1 = itr;
				itr1++;
				if(itr1 != mp.end()) {
					if(check(*itr1, v)) return true;
				}
			}
			if(itr != mp.begin()) {
				itr--;
				if(check(*itr, v)) return true;
			}
			mp.insert(v);
		}else {
			mp.erase(v);
		}
	}
	//cout << mp.size() << endl;
	return false;
}
int main() {
	scanf("%d", &n);
	D t = gene() % 100000 / 100000. * pi;
	for(int i = 1; i <= n; i++) {
		a[i].scan();
		d[i].scan();
		a[i] = a[i].rot(t);
		d[i] = d[i].rot(t);
		double _v;
		scanf("%lf", &_v);
		v[i] = _v;
	}
	D le = 0, ri = 1e11;
	for(int j = 0; j < 100; j++) {
		D mid = (le + ri) / 2;
		if(check(mid)) {
			ri = mid;
		}else le = mid;
	}
	if(le >= 1e10) {
		printf("No show :(\n");
	}else 
	printf("%.12f\n", (double)((le + ri) / 2));

}