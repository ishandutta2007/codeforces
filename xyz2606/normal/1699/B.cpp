#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<chrono>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
#include<type_traits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(chrono::system_clock::now().time_since_epoch().count());
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
template<LL mod> struct Num {
	LL a;
	Num operator + (const Num & b) { return Num{(a + b.a) % mod}; }
	Num operator - (const Num & b) { return Num{(a - b.a + mod) % mod}; }
	Num operator * (const Num & b) { return Num{a * b.a % mod}; }
	Num operator / (const Num & b) { return Num{a * fastpo(b.a, mod - 2, mod) % mod}; }
	void operator += (const Num & b) {if((a += b.a) >= mod) a -= mod;}
	void operator -= (const Num & b) {if((a -= b.a) < 0) a += mod;}
	void operator *= (const Num & b) { a = a * b.a % mod; }
	void operator /= (const Num & b) { a = a * fastpo(b.a, mod - 2, mod) % mod; }
	void operator = (const Num & b) { a = b.a; }
	void operator = (const LL & b) { a = b; }
};
template<LL mod> ostream & operator << (ostream & os, const Num<mod> & a) {
	os << a.a;
	return os;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(LL x, int width = 0) {
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
typedef double C;
struct P {
	C x, y;
	void scan() {
		double _x, _y;
		scanf("%lf%lf", &_x, &_y);
		x = _x; y = _y;
	}
	void print() {
		cout << '(' << x << ' ' << y << ')' << endl;
	}
	P operator + (const P & b) const { return P{x + b.x, y + b.y}; }
	P operator - (const P & b) const { return P{x - b.x, y - b.y}; }
	C operator * (const P & b) const { return x * b.y - y * b.x; }
	C operator % (const P & b) const { return x * b.x + y * b.y; }
};
P operator * (const C & x, const P & b) { return P{x * b.x, x * b.y}; }
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int rela[N];
int getr(int x) {
    int p = x;
    while(rela[p] != p) p = rela[p];
    int p1 = p; p = x;
    while(rela[p] != p) {
        int p2 = rela[p];
        rela[p] = p1;
        p = p2;
    }
    return p1;
}
int a[55][55];
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n / 2; i++) {
			for(int j = 1; j <= m / 2; j++) {
				a[i * 2 - 1][j * 2 - 1] = a[i * 2][j * 2] = (i + j) % 2;
				a[i * 2 - 1][j * 2] = a[i * 2][j * 2 - 1] = (i + j + 1) % 2;
			}
		}
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) printf("%d%c", a[i][j], j == m ? '\n' : ' ');
	}
}