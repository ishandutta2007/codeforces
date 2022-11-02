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
const int M = 1024 * 1024;

int n, q;
VPII X;
int T[M];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &q);
	int ma = -1, ind = -1;
	FOR(i, 1, n)
	{
		scanf("%d", T + i);
		if (T[i] > ma)
		{
			ma = T[i];
			ind = i;
		}
	}
	int last = T[1];
	FOR(i, 2, ind)
	{
		X.PB(MP(last, T[i]));
		T[n + i - 1] = min(last, T[i]);
		last = max(last, T[i]);
	}
	debug(ind);
	FOR(i, ind, ind + n)
	{
		debug(i, T[i]);
	}
	FOR(i, 1, q)
	{
		LL a;
		scanf("%lld", &a);
		if (a < ind)
		{
			printf("%d %d\n", X[a - 1].f, X[a - 1].s);
		}
		else
		{
			a -= ind;
			a %= (n - 1);
			printf("%d %d\n", T[ind], T[ind + 1 + a]);
		}
	}
	return 0;
}