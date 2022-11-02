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
const int M = 1024 * 256;

int n, T[2 * M], A[2 * M];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	FOR(i, 1, 2 * n)
	{
		scanf("%d", T + i);
		A[T[i]] = i;
	}
	int ind = A[1];
	bool boo = true;
	FOR(i, ind + 1, 2 * n)
	{
		if (T[i] != T[i - 1] + 1)
		{
			boo = false;
			break;
		}
	}
	if (!boo)
	{
		ind = 2 * n + 1;
	}
	if (ind == n + 1)
	{
		printf("0\n");
		return 0;
	}
	int lol = 0, lol2;
	FOR(i, n + 1, 2 * n)
	{
		if (T[i] != 0)
		{
			maxi(lol, i + 1 - T[i]);
			debug(i, lol);
		}
		if (i == ind - 1)
		{
			lol2 = lol;
		}
	}
	debug(lol, lol2, ind);
	if (lol2 <= ind - n - 1)
	{
		printf("%d\n", ind - n - 1);
	}
	else
	{
		printf("%d\n", lol);
	}
	return 0;
}