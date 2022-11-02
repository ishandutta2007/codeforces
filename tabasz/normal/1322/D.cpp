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
const int M = 1024 * 5;
const int inf = 1e9 + 7;

int n, m;
int L[M], S[M], C[M];
int dp[M][M], res;

void getRes(int r, int l, int ile)
{
	debug(r, l, ile);
	while (ile > 1)
	{
		ile /= 2;
		l++;
		r += ile * C[l];
	}
	maxi(res, r);
}

int32_t main()
{
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	{
		scanf("%d", L + i);
	}
	FOR(i, 1, n)
	{
		scanf("%d", S + i);
	}
	FOR(i, 1, n + m)
	{
		scanf("%d", C + i);
	}
	FOR(i, 0, M - 1)
	{
		FOR(j, 1, M - 1)
		{
			dp[i][j] = -inf;
		}
	}
	FORD(i, n, 1)
	{
		int j = 0;
		while (dp[L[i]][j] > -inf)
		{
			j++;
		}
		debug(i, j);
		FORD(k, j, 1)
		{
			getRes(dp[L[i]][k - 1] - S[i] + C[L[i]], L[i], k);
			maxi(dp[L[i]][k], dp[L[i]][k - 1] - S[i] + C[L[i]]);
		}
		FOR(k, L[i] + 1, M - 1)
		{
			FOR(l, 0, j)
			{
				maxi(dp[k][l / 2], dp[k - 1][l] + (l / 2) * C[k]);
			}
			j /= 2;
		}
	}
	printf("%d\n", res);
}