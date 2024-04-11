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

#define int LL
#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "
const int M = 1024 * 128;
const int m = 11;

int n, res;
int dp[M][2][m], T[M];//1->9 = 0; 10->0 = 1
char C[M];

int calc(int lev, int mo, int dig)
{
	int st = 0, st2 = 10;
	if (lev == 1)
	{
		swap(st, st2);
	}
	while (st != mo)
	{
		st2 += st;
		st++;
		if (st2 >= m)
		{
			st2 -= m;
		}
		if (st >= m)
		{
			st -= m;
		}
	}
	return (st2 + dig) % m;
}

main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	debug(calc(1, 6, 4));
	scanf("%s", C);
	n = strlen(C);
	FOR(i, 0, n - 1)
	{
		T[i + 1] = C[i] - '0';
	}
	FOR(i, 1, n)
	{
		if (T[i] != 0)
		{
			dp[i][0][T[i]]++;
		}
		FOR(j, 0, 1)
		{
			FOR(k, 0, m - 1)
			{
				res += dp[i][j][k];
				if (dp[i][j][k] != 0)
				{
					debug(i, j, k, dp[i][j][k]);
				}
				if (T[i + 1] < k)
				{
					//debug("    ", i, j, k, calc(j, k, T[i + 1]));
					dp[i + 1][1 - j][calc(j, k, T[i + 1])] += dp[i][j][k];
				}
			}
		}
	}
	
	printf("%lld\n", res);
	return 0;
}