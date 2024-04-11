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

int n;
int T[M], one[M], dp[M];
map<int, int> nxt[M];
LL res;

void solve()
{
	scanf("%d", &n);
	res = 0;
	one[n + 1] = 0;
	dp[n + 1] = 0;
	nxt[n + 1].clear();
	FOR(i, 1, n)
	{
		scanf("%d", T + i);
		one[i] = 0;
		dp[i] = 0;
		nxt[i].clear();
	}
	
	FORD(i, n - 1, 1)
	{
		if (T[i + 1] == T[i])
		{
			one[i] = i + 1;
			swap(nxt[i + 2], nxt[i]);
			if (i + 2 <= n)
			{
				nxt[i][T[i + 2]] = i + 1;
			}
		}
		else
		{
			if (nxt[i + 1].count(T[i]))
			{
				one[i] = nxt[i + 1][T[i]] + 1;
				swap(nxt[i], nxt[one[i] + 1]);
				if (one[i] < n)
				{
					nxt[i][T[one[i] + 1]] = one[i];
				}
			}
		}
	}
	
	FORD(i, n, 1)
	{
		if (one[i] <= 0)
		{
			continue;
		}
		dp[i] = dp[one[i] + 1] + 1;
		res += dp[i];
	}
	printf("%lld\n", res);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}