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
const int M = 1024;
const int mod = 998244353;

int n, k, mx;
int dp[M][M][2], P[M][M][2], T[M];
LL res;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &k);
	FOR(i, 1, n)
	{
		scanf("%d", T + i);
		maxi(mx, T[i]);
	}
	sort(T + 1, T + n + 1);
	T[0] = -1e6;
	FOR(i, 0, mx / (k - 1))
	{
		int tmp1 = 0, tmp2 = 0;
		FOR(j, 1, n)
		{
			while (tmp1 + 1 < j && T[j] - T[tmp1 + 1] > i)
			{
				tmp1++;
			}
			while (tmp2 + 1 < j && T[j] - T[tmp2 + 1] >= i)
			{
				tmp2++;
			}
			dp[j][1][0] = 1;
			P[j][1][0] = P[j - 1][1][0] + dp[j][1][0];
			if (P[j][1][0] >= mod)
			{
				P[j][1][0] -= mod;
			}
			P[j][1][1] = P[j - 1][1][1] + dp[j][1][1];
			if (P[j][1][1] >= mod)
			{
				P[j][1][1] -= mod;
			}
			
			FOR(l, 2, k)
			{
				dp[j][l][0] = P[tmp1][l - 1][0];
				dp[j][l][1] = P[tmp2][l - 1][0] - P[tmp1][l - 1][0];
				if (dp[j][l][1] < 0)
				{
					dp[j][l][1] += mod;
				}
				dp[j][l][1] += P[tmp2][l - 1][1];
				if (dp[j][l][1] >= mod)
				{
					dp[j][l][1] -= mod;
				}
				P[j][l][0] = P[j - 1][l][0] + dp[j][l][0];
				if (P[j][l][0] >= mod)
				{
					P[j][l][0] -= mod;
				}
				P[j][l][1] = P[j - 1][l][1] + dp[j][l][1];
				if (P[j][l][1] >= mod)
				{
					P[j][l][1] -= mod;
				}
				//debug(i, j, l, dp[j][l][0], dp[j][l][1], P[j][l][0], P[j][l][1]);
			}
		}
		res = (res + (LL)	P[n][k][1] * i) % mod;
	}
	
	printf("%lld\n", res);
	return 0;
}