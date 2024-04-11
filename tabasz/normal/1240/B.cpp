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
const int Ma = 1024 * 1024;

int n, T[Ma], M, L[Ma], R[Ma];
VI D;

void add(int v, int x)
{
	v += M;
	maxi(D[v], x);
	while (v > 1)
	{
		v /= 2;
		D[v] = max(D[2 * v], D[2 * v + 1]);
	}
}

int mxi(int p, int k)
{
	p += M;
	k += M;
	int r = max(D[p], D[k]);
	while (p / 2 != k / 2)
	{
		if (p % 2 == 0)
		{
			maxi(r, D[p + 1]);
		}
		p /= 2;
		if (k % 2 == 1)
		{
			maxi(r, D[k - 1]);
		}
		k /= 2;
	}
	return r;
}

void solve()
{
	scanf("%d", &n);
	D.clear();
	M = 1;
	while (M <= n)
	{
		M *= 2;
	}
	D.resize(2 * M);
	FOR(i, 1, n)
	{
		scanf("%d", T + i);
		L[i] = n + 1;
		R[i] = 0;
	}
	FOR(i, 1, n)
	{
		mini(L[T[i]], i);
		maxi(R[T[i]], i);
	}
	int res = 1, diff = 0, tmp = 0, prv = 0;
	FOR(i, 1, n)
	{
		if (L[i] > R[i])
		{
			continue;
		}
		diff++;
		if (L[i] > prv)
		{
			tmp++;
			prv = R[i];
		}
		else
		{
			tmp = 1;
			prv = R[i];
		}
		maxi(res, tmp);
	}
	printf("%d\n", diff - res);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}