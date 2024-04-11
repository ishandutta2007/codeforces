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
const LL mod = 998244353;
const int MM = 1024 * 1024;

LL dp[M][M];
int n, m, A[M * M], ile[2][M], tim[2][M], tt[2], bad[2];
PII T[M];
VI V[M];
int D[2 * MM];

int gett(int i, int x)
{
	if (tt[i] == tim[i][x])
	{
		return ile[i][x];
	}
	tim[i][x] = tt[i];
	return ile[i][x] = 0;
}

void add(int i, int x)
{
	if (tim[i][x] != tt[i])
	{
		tim[i][x] = tt[i];
		ile[i][x] = 1;
	}
	else
	{
		ile[i][x]++;
	}
	int lol = gett(1 - i, x);
	if (ile[i][x] == lol && lol == 2)
	{
		bad[i]--;
	}
	else if (ile[i][x] == 1 && lol == 2)
	{
		bad[i]++;
	}
}

int minind(int a, int b)
{
	tt[0]++;
	int r = a, val = T[a].f;
	FOR(i, a, b)
	{
		add(0, T[i].f);
		if (T[i].f < val)
		{
			val = T[i].f;
			r = i;
		}
	}
	return r;
}

int mi(int p, int k)
{
	p += MM;
	k += MM;
	int r = min(D[p], D[k]);
	while (p / 2 != k / 2)
	{
		if (p % 2 == 0)
		{
			mini(r, D[p + 1]);
		}
		p /= 2;
		if (k % 2 == 1)
		{
			mini(r, D[k - 1]);
		}
		k /= 2;
	}
	return r;
}

void addD(int v, int x)
{
	v += MM;
	D[v] = x;
	while (v > 1)
	{
		v /= 2;
		D[v] = min(D[2 * v], D[2 * v + 1]);
	}
}

LL solve(int p, int k)
{
	if (dp[p][k] != -1)
	{
		return dp[p][k];
	}
	if (p == k)
	{
		return dp[p][k] = 1;
	}
	dp[p][k] = 0;
	
	
	int ind = minind(p, k);
	
	if (mi(T[p].s, T[k].s) < T[ind].f)
	{
		return dp[p][k] = 0;
	}
	
	if (ind != k && T[k].f == T[ind].f)
	{
		return dp[p][k] = solve(p, k - 1);
	}
	
	tt[1]++;
	bad[1] = 0;
	vector<pair<PII, PII>> V;
	if (ind == p)
	{
		for (int l = k; l > ind; l--)
		{
			add(1, T[l].f);
			if (bad[1] == 0)
			{
				//debug("   ", p, k, l, solve(p, l - 1), solve(l, k));
				V.PB(MP(MP(p, l - 1), MP(l, k)));
				//dp[p][k] = (dp[p][k] + solve(p, l - 1) * solve(l, k)) % mod;
			}
		}
	}
	else
	{
		for (int l = p; l < ind; l++)
		{
			add(1, T[l].f);
			if (bad[1] == 0)
			{
				V.PB(MP(MP(p, l), MP(l + 1, k)));
				//dp[p][k] = (dp[p][k] + solve(p, l) * solve(l + 1, k)) % mod;
			}
		}
	}
	for (auto x : V)
	{
		dp[p][k] = (dp[p][k] + solve(x.f.f, x.f.s) * solve(x.s.f, x.s.s)) % mod;
		if (p == 1 && k == 11)
		{
			debug("                    ", p, k, x, dp[p][k]);
		}
	}
	
	debug(p, k, dp[p][k]);
	return dp[p][k];
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &m);
	FOR(i, 1, m)
	{
		scanf("%d", A + i);
		V[A[i]].PB(i);
		addD(i, A[i]);
	}
	VPII X;
	FOR(i, 1, n)
	{
		X.PB(MP(V[i][0], i));
		if (SIZ(V[i]) > 1)
		{
			X.PB(MP(V[i].back(), i));
		}
	}
	X.PB(MP(0, 0));
	sort(ALL(X));
	debug(X);
	m = SIZ(X) - 1;
	FOR(i, 0, m)
	{
		T[i] = MP(X[i].s, X[i].f);
		FOR(j, i, m)
		{
			dp[i][j] = -1;
		}
	}
	
	printf("%lld\n", solve(0, m));
	return 0;
}