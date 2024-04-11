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
const int M = 55;

int n, m, A[M][M], B[M][M];
VPII R;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			scanf("%d", A[i] + j);
		}
	}
	FOR(i, 1, n - 1)
	{
		FOR(j, 1, m - 1)
		{
			if (A[i][j] && A[i + 1][j] && A[i][j + 1] && A[i + 1][j + 1])
			{
				R.PB(MP(i, j));
				B[i][j] = 1;
				B[i][j + 1] = 1;
				B[i + 1][j] = 1;
				B[i + 1][j + 1] = 1;
			}
		}
	}
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			if (A[i][j] != B[i][j])
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", SIZ(R));
	for (auto x : R)
	{
		printf("%d %d\n", x.f, x.s);
	}
	return 0;
}