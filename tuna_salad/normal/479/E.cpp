#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
typedef long long LL; typedef long double LD; typedef unsigned int uint;
typedef pair<int,int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

// More templates here

template<typename Int,Int mod>
class ModInt {
public:
	Int x; static const Int Mod = mod;
	ModInt(): x(0) {}
	ModInt(int a) { Int t = a % mod; if(t < 0) t += mod; x = t; }
	ModInt(LL  a) { Int t = a % mod; if(t < 0) t += mod; x = t; }
	Int get() const { return x; }

	ModInt &operator+=(ModInt that) { if((x += that.x) >= mod) x -= mod; return *this; }
	ModInt &operator-=(ModInt that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	ModInt &operator*=(ModInt that) { x = LL(x) * that.x % mod; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
	bool  operator==(ModInt that) const { return x == that.x; }
	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
	ModInt operator-() const { return ModInt(-this->x); }
	inline friend ostream& operator << (ostream &out, ModInt m) {return out << m.x;}

	ModInt inverse() const {
		LL a = x, b = mod, u = 1, v = 0;
		while(b) {
			LL t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		return ModInt(u);
	}
};

const int moder = 1e9+7;
typedef ModInt <int, moder> Mint;

#define MAXN (5004)

int N, K, A, B;

Mint S[MAXN];
Mint T[MAXN];

inline Mint sum(int a, int b)
{
	maxa(a,0);
	mina(b,N);
	if(a >= b) return 0;
	else return T[b] - T[a];
}

int main()
{
	cin >> N >> A >> B >> K;

	FOR(i,1,N+1) S[i] = i != B;
	FOR(i,0,K)
	{
		FOR(j,1,N+1) T[j] = T[j-1] + S[j];
		FOR(j,1,N+1) if(j != B)
		{
			int d = abs(j - B);
			S[j] = sum(j-d, j+d-1) - S[j];
		}
	}
	cout << S[A] << endl;

	return 0;
}