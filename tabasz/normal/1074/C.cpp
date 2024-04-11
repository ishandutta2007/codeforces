#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
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

int n;
int mmx = -1e9, mix = 1e9, mmy = -1e9, miy = 1e9;
vector<PII> V, X;


int abs(int x)
{
	return max(-x, x);
}

int dist(PII x, PII y)
{
	return abs(x.f - y.f) + abs(x.s - y.s);
}

int main()
{
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(MP(a, b));
		mmx = max(mmx, a);
		mix = min(mix, a);
		mmy = max(mmy, b);
		miy = min(miy, b);
	}
	for (auto p : V)
	{
		if (p.f == mmx || p.f == mix || p.s == mmy || p.s == miy)
		{
			X.PB(p);
		}
	}
	LL res = 0, res2 = 0;
	V.PB(V[0]);
	FOR(i, 1, n)
	{
		res += dist(V[i - 1], V[i]);
	}
	for (auto p : V)
	{
		for (auto a : X)
		{
			for (auto b : X)
			{
				res2 = max(res2, (LL)dist(p, a) + dist(p, b) + dist(a, b));
			}
		}
	}
	/*if (SIZ(X) > 2)
	{
		sort(ALL(X));
		do
		{
			LL r = dist(X[0], X[1]) + dist(X[1], X[2]) + dist(X[0], X[2]);
			res2 = max(res2, r);
		} while (next_permutation(ALL(X)));
	}
	else
	{
		res2 = res;
	}*/
	printf("%lld ", res2);
	FOR(i, 4, n)
	{
		printf("%lld ", res);
	}
	printf("\n");
	return 0;
}