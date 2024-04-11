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
const int M = 1024 * 10;

int n;
LL A[M], B[M], res;
vector<PLL> V;
set<LL> secik;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		scanf("%lld", A + i);
	}
	FOR(i, 1, n)
	{
		scanf("%lld", B + i);
	}
	FOR(i, 1, n)
	{
		V.PB(MP(A[i], B[i]));
	}
	sort(ALL(V));
	FOR(i, 0, n - 1)
	{
		if ((i < n - 1 && V[i + 1].f == V[i].f) || secik.count(V[i].f))
		{
			secik.insert(V[i].f);
			res += V[i].s;
		}
	}
	debug(secik, res);
	FORD(i, n - 1, 0)
	{
		if (secik.count(V[i].f))
		{
			continue;
		}
		bool boo = 0;
		for (auto x : secik)
		{
			debug(x, V[i].f, x & V[i].f);
			if ((x & V[i].f) == V[i].f)
			{
				boo = 1;
				break;
			}
		}
		if (boo)
		{
			res += V[i].s;
			secik.insert(V[i].f);
		}
	}
	printf("%lld\n", res);
	return 0;
}