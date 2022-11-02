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
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)

#define Sim template<class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.st << ", " << x.nd << ">";}
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

vector<int> V[3];

main() 
{
	int a, b;
	scanf("%lld%lld", &a, &b);
	int tmp = 0, il = 0;
	for (int i = 1; i <= 1e9; i++)
	{
		if (tmp + i > a + b)
		{
			break;
		}
		tmp += i;
		V[0].PB(i);
	}
	for (int i = SIZ(V[0]) - 1; i >= 0; i--)
	{
		if (V[0][i] <= a)
		{
			V[1].PB(V[0][i]);
			a -= V[0][i];
		}
		else
		{
			V[2].PB(V[0][i]);
			b -= V[0][i];
		}
	}
	for (int i = 1; i < 3; i++)
	{
		printf("%lld\n", SIZ(V[i]));
		for (auto x : V[i])
		{
			printf("%lld ", x);
		}
		printf("\n");
	}
	return 0;
}