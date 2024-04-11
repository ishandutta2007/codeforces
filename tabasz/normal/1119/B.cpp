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

vector<int> V;
int n, h;

bool solve(int k)
{
	VI X;
	FOR(i, 0, k - 1)
	{
		X.PB(V[i]);
	}
	sort(ALL(X));
	LL res = 0;
	int tmp = SIZ(X) - 1;
	while (tmp >= 0)
	{
		res += X[tmp];
		tmp -= 2;
	}
	return res <= (LL)h;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &h);
	FOR(i, 1, n)
	{
		int a;
		scanf("%d", &a);
		V.PB(a);
	}
	FORD(i, n, 1)
	{
		if (solve(i))
		{
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}