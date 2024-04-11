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
const int MA = 2e5 + 100;
const LL inf = 1e18L;

vector<PII> A[M];
int T[M], n;
LL dp[M];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	vector<int> V;
	FOR(i, 0, 100005)
	{
		V.PB(2 * i + 1);
	}
	FOR(i, 0, SIZ(V) - 1)
	{
		int tmp = V[i];
		A[tmp].PB(MP(i, i + 1));
		FOR(j, i + 1, SIZ(V) - 1)
		{
			tmp += V[j];
			if (tmp > MA)
			{
				break;
			}
			A[tmp].PB(MP(i, j + 1));
		}
	}
	scanf("%d", &n);
	FOR(i, 1, n / 2)
	{
		scanf("%d", T + i);
	}
	
	FOR(i, 1, n / 2)
	{
		dp[i] = inf;
		for (auto p : A[T[i]])
		{
			if ((LL)p.f * p.f > dp[i - 1])
			{
				mini(dp[i], (LL)p.s * p.s);
			}
		}
		
		if (dp[i] == inf)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	FOR(i, 1, n / 2)
	{
		printf("%lld %d ", dp[i] - dp[i - 1] - T[i], T[i]);
	}
	printf("\n");
	return 0;
}