#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define pb pop_back
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)

#define Sim template<class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
Sim> auto operator << (ostream &p, n y) -> 
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
Sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
Sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
Sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "
#define int LL
const LL M = 1024 * 1024;

map<LL, LL> cnt;
unordered_set<LL> done;
LL n, res, st;
VPII T;
VI P, V, fact[M];
bool B[M];

void sito()
{
	FOR(i, 2, M - 1)
	{
		if (!B[i])
		{
			P.PB(i);
			for (int j = i * i; j < M; j += i)
			{
				B[j] = 1;
			}
		}
	}
}


void jebaj(int val)
{
	for (auto p : fact[val - st])
	{
		if (done.count(p))
		{
			continue;
		}
		int tmp = 0;
		for (auto x : T)
		{
			int mo = p - (x.f % p);
			if (x.f >= p)
			{
				mini(mo, p - mo);
			}
			tmp += mo * x.s;
			if (tmp > res)
			{
				break;
			}
		}
		debug(val, p, tmp);
		mini(res, tmp);
		done.insert(p);
	}
}

void factorize(int p, int k)
{
	st = p;
	VI X;
	FOR(i, p, k)
	{
		X.PB(i);
	}
	for (auto x : P)
	{
		int pocz = p + (x - p % x);
		if (p % x == 0)
		{
			pocz = p;
		}
		for (int i = pocz; i <= k; i += x)
		{
			if (X[i - st] % x == 0)
			{
				fact[i - st].PB(x);
				while (X[i - st] % x == 0)
				{
					X[i - st] /= x;
				}
			}
		}
	}
	FOR(i, 0, SIZ(X) - 1)
	{
		if (X[i] != 1)
		{
			fact[i].PB(X[i]);
		}
		debug(i, i + st, fact[i]);
	}
}

int32_t main()
{
	sito();
	scanf("%lld", &n);
	res = n;
	FOR(i, 1, n)
	{
		int a;
		scanf("%lld", &a);
		if (a % 2 == 0)
		{
			res--;
		}
		cnt[a]++;
	}
	for (auto x : cnt)
	{
		T.PB(x);
	}
	//random_shuffle(ALL(T));
	factorize(max(1LL, T[0].f - res), T[0].f + res);
	FOR(i, 0, res)
	{
		jebaj(T[0].f + i);
		if (T[0].f - i > 0 && i != 0)
		{
			jebaj(T[0].f - i);
		}
	}
	printf("%lld\n", res);
}