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
const int M = 1024 * 2;
const int inf = 1e9 + 7;

int n, s, m, k, T[M], X[M], Y[M];
PII A[M];
int dp[M][M], best[M], D[2 * M];

void add(int p, int k, int x)
{
	p += M;
	k += M;
	mini(D[p], x);
	mini(D[k], x);
	while (p / 2 != k / 2)
	{
		if (p % 2 == 0)
		{
			mini(D[p + 1], x);
		}
		p /= 2;
		if (k % 2 == 1)
		{
			mini(D[k - 1], x);
		}
		k /= 2;
	}
}

int query(int v)
{
	v += M;
	int r = D[v];
	while (v > 1)
	{
		v /= 2;
		mini(r, D[v]);
	}
	return r;
}

bool check(int x)
{
	int nn = 0;
	int tmp1 = 1, tmp2 = 0;
	FOR(i, 1, n)
	{
		if (T[i] <= x)
		{
			tmp2++;
		}
		Y[i] = tmp2;
		X[i] = tmp1;
		if (T[i] <= x)
		{
			tmp1++;
			nn++;
		}
	}
	if (k > nn)
	{
		return false;
	}
	FOR(i, 0, nn)
	{
		FOR(j, 1, nn)
		{
			dp[i][j] = inf;
		}
		dp[i][0] = 0;
	}
	FOR(i, 0, M - 1)
	{
		D[M + i] = i + 1;
		D[i] = inf;
	}
	FOR(i, 1, s)
	{
		if (X[A[i].f] <= Y[A[i].s])
		{
			add(X[A[i].f], Y[A[i].s], X[A[i].f]);
		}
	}
	FOR(i, 1, nn)
	{
		best[i] = query(i);
	}
	
	FOR(i, 1, nn)
	{
		FOR(j, 1, i)
		{
			dp[i][j] = inf;
			if (j < i)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			dp[i][j] = min(dp[i][j], dp[best[i] - 1][max(j - i + best[i] - 1, 0)] + 1);
		}
		FORD(j, i - 1, 0)
		{
			dp[i][j] = min(dp[i][j], dp[i][j + 1]);
		}
	}
	
	return dp[nn][k] <= m;
}

int main() 
{
	scanf("%d%d%d%d", &n, &s, &m, &k);
	FOR(i, 1, n)
	{
		scanf("%d", T + i);
	}
	FOR(i, 1, s)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		A[i] = MP(a, b);
	}
	int st = 1, en = 1e9, mid = (st + en) / 2, r = inf;
	while (st <= en)
	{
		if (check(mid))
		{
			r = min(r, mid);
			en = mid - 1;
		}
		else
		{
			st = mid + 1;
		}
		mid = (st + en) / 2;
	}
	if (r == inf)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", r);
	}
	return 0;
}