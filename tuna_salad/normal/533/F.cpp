// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
typedef long long LL; typedef long double LD; typedef unsigned int uint;
typedef pair<int,int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }
template<class T> T fastPow(T x, LL k) {if(k<=0)return 1;T r=1;while(k>0){if(k&1)r*=x;x*=x;k>>=1;}return r;}

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
	bool  operator!=(ModInt that) const { return x != that.x; }
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

const int P1 = 1e9+7;
const int P2 = 1e9+9;
typedef ModInt <int, P1> M1;
typedef ModInt <int, P2> M2;
typedef pair <M1,M2> MM;
typedef tuple<int,int,int> T3;

#define MAXN (200005)

int N, M;
char S[MAXN];
char T[MAXN];

M1 pow1;
M2 pow2;

MM TM[26], SM[26], m0;
T3 TS[26], SS[26];
int tsn;

int A[26];
int V[26];
int rit;

VI sol;

inline MM add(MM &m, int v)
{
	m._1 = (m._1*2) + v;
	m._2 = (m._2*3) + v;
	return m;
}

inline T3 f(MM &m, int a)
{
	return T3(m._1.x, m._2.x, a);
}

inline bool eq(T3 &t1, T3 &t2, int &a, int &b)
{
	int i,j,x,y;
	tie(i,j,a) = t1;
	tie(x,y,b) = t2;
	return x == i && y == j;
}

int check(int a, int b)
{
	if(V[a] != rit)
	{
		V[a] = rit;
		A[a] = b;
	}
	return A[a] == b;
}

int main()
{
	cin >> N >> M;
	scanf("%s %s", S, T);
	pow1 = fastPow<M1>(2,M);
	pow2 = fastPow<M2>(3,M);

	FOR(i,0,M) FOR(j,0,26)
	{
		SM[j] = add(SM[j], (j+'a' == S[i]) ? 1 : 0);
		TM[j] = add(TM[j], (j+'a' == T[i]) ? 1 : 0);
	}
	FOR(i,0,26) if(TM[i] != m0) TS[tsn++] = f(TM[i],i);
	sort(TS,TS+tsn);

/*
	FOR(i,0,tsn)
	{
		T3 t = TS[i];
		int a, b, c;
		tie(a,b,c) = t;
		printf("tsn %d %d %d\n", a, b, c);
	}
*/

	FOR(i,M-1,N)
	{
		if(i >= M)
		{
			FOR(j,0,26) SM[j] = add(SM[j], (j+'a' == S[i]) ? 1 : 0);
			int id = S[i-M]-'a';
			SM[id]._1 -= pow1;
			SM[id]._2 -= pow2;
		}

		int n = 0;
		FOR(j,0,26) if(SM[j] != m0) SS[n++] = f(SM[j],j);
		++rit;
		if(n == tsn)
		{
			sort(SS,SS+n);
			int v = 1, a, b;
			FOR(j,0,n)
			{
				if(eq(SS[j], TS[j], a, b))
				{
					if(!check(a,b) || !check(b,a))
					{
						v = 0;
						break;
					}
				}
				else
				{
					v = 0;
					break;
				}
			}
			if(v) sol.PB(i-M+2);
		}
	}

	printf("%d\n", sol.size());
	for(int s: sol) printf("%d ", s);
	if(sol.size() > 0) cout << endl;

	return 0;
}