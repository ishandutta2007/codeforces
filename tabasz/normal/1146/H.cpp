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
const int M = 303;

int n;
bitset<M> B[M][M];
VPII V;

LL wek(PII a, PII b, PII c)
{
	return (LL)(b.f - a.f) * (c.s - a.s) - (LL)(b.s - a.s) * (c.f - a.f);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(MP(a, b));
	}
	FOR(i, 0, n - 1)
	{
		FOR(j, i + 1, n - 1)
		{
			FOR(k, 0, n - 1)
			{
				if (k == i || k == j)
				{
					continue;
				}
				if (wek(V[i], V[j], V[k]) < 0)
				{
					B[i][j][k] = 1;
				}
				else
				{
					B[j][i][k] = 1;
				}
			}
		}
	}
	LL res = 0;
	FOR(i, 0, n - 1)
	{
		FOR(j, 0, n - 1)
		{
			FOR(k, 0, n - 1)
			{
				if (i == j || i == k || j == k || B[i][k][j])
				{
					continue;
				}
				auto b = B[i][j] & B[j][k];
				int all = b.count();
				int in = (b & B[k][i]).count();
				int out = all - in;
				res += out * (out - 1) / 2 - in * out;
			}
		}
	}
	debug(res);
	printf("%lld\n", res / 5);
	return 0;
}