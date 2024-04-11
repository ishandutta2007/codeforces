#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxv = 4184304;
const db pi = acos(-1);

class Complex{
public:
	db a, b;
	Complex(){}
	Complex(db _a, db _b): a(_a), b(_b){}
	inline Complex operator + (const Complex &oth)const{ return Complex(a + oth.a, b + oth.b); }
	inline Complex operator - (const Complex &oth)const{ return Complex(a - oth.a, b - oth.b); }
	inline Complex operator * (const Complex &oth)const{ return Complex(a * oth.a - b * oth.b, a * oth.b + b * oth.a); }
	inline Complex operator / (const db &oth)const{ return Complex(a / oth, b / oth); }
	inline void operator *= (const Complex &oth){ (*this) = (*this) * oth; return; }
	inline void operator /= (const db &oth){ (*this) = (*this) / oth; return; }
	inline ll round(){ return (ll)(a + 0.5); }
}p[maxv], q[maxv];

inline void fft(Complex *coe, int len, int IDFT = 1){
	for(int i = 0, j = 0; i < len; ++i){
		if(i < j)
			swap(coe[i], coe[j]);
		for(int l = len / 2; (j ^= l) < l; l >>= 1);
	}
	for(int step = 1; step < len; step <<= 1){
		Complex w = Complex(cos(pi / step), IDFT * sin(pi / step));
		for(int i = 0; i < len; i += step << 1){
			Complex cur = Complex(1, 0);
			FOR(j, 0, step){
				Complex x = coe[i + j], y = cur * coe[i + j + step];
				coe[i + j] = x + y;
				coe[i + j + step] = x - y;
				cur *= w;
			}
		}
	}
	if(!~IDFT)
		FOR(i, 0, len)
			coe[i] /= len;
	return;
}

class Polynomial{
public:
	int deg;
	int coe[maxv];
	inline void operator *= (Polynomial oth){
		int len;
		for(len = 1; len <= deg + oth.deg; len <<= 1);
		FOR(i, 0, len){
			p[i] = Complex(coe[i], 0);
			q[i] = Complex(oth.coe[i], 0);
		}
		fft(p, len);
		fft(q, len);
		FOR(i, 0, len)
			p[i] *= q[i];
		fft(p, len, -1);
		FOR(i, 0, len)
			coe[i] = min(1ll, p[i].round());
		deg += oth.deg;
		return;
	}
}A;

inline Polynomial qpow(Polynomial P, int y){
	Polynomial Q = P;
	for(--y; y; y >>= 1){
		if(y & 1)
			Q *= P;
		P *= P;
	}
	return Q;
}

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	FOR(i, 0, n){
		int x; scanf("%d", &x);
		A.coe[x] = 1;
		A.deg = max(A.deg, x);
	}
	++A.deg;
	A = qpow(A, k);
	FOR(i, 0, maxv) if(A.coe[i])
		printf("%d ", i);
	puts("");
	return 0;
}