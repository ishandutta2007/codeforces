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

int n, s;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	VI V;
	int x, s2 = 0;
	scanf("%d", &x);
	s += x;
	s2 += x;
	V.PB(1);
	FOR(i, 2, n)
	{
		int a;
		scanf("%d", &a);
		s += a;
		debug(i, a, x);
		if (2 * a <= x)
		{
			debug(i);
			s2 += a;
			V.PB(i);
		}
	}
	debug(x, s, s2);
	if (s2 * 2 > s)
	{
		printf("%d\n", SIZ(V));
		for (auto x : V)
		{
			printf("%d ", x);
		}
		printf("\n");
	}
	else
	{
		printf("0\n");
	}
	return 0;
}