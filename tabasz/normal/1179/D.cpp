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
const int M = 1024 * 1024;

int n, S[M];
VI V[M];
LL dp[M], res = 1e18;

VPII A;
VI nxt, prv, on;
set<PII> secik;

bool better(PII x, PII y, int t)
{
	return (LL)(t - x.f) * (t - x.f - 1) / 2 + x.s < (LL)(t - y.f) * (t - y.f - 1) / 2 + y.s;
}

void check(int ind)
{
	int ind2 = nxt[ind];
	if (ind2 == -1 || !on[ind] || !on[ind2])
	{
		return;
	}
	PII a = A[ind];
	PII b = A[ind2];
	
	if (!better(a, b, b.f))
	{
		return;
	}
	
	int st = b.f, en = n, mid = (st + en) / 2, r = st;
	
	while (st <= en)
	{
		if (better(a, b, mid))
		{
			maxi(r, mid);
			st = mid + 1;
		}
		else
		{
			en = mid - 1;
		}
		mid = (st + en) / 2;
	}
	secik.insert(MP(-r, ind));
}

void rem(int ind, int t)
{
	int ind2 = nxt[ind];
	
	if (ind2 != -1 && on[ind] && on[ind2] && better(A[ind], A[ind2], t))
	{
		nxt[ind] = nxt[ind2];
		if (nxt[ind2] != -1)
		{
			prv[nxt[ind2]] = ind;
		}
		else
		{
			A.pb();
			nxt.pb();
			prv.pb();
		}
	
		if (nxt[ind] != -1)
		{
			check(ind);
		}
	}
}

void solve(int s, VPII X)
{
	debug(s, X);
	A.clear();
	nxt.clear();
	prv.clear();
	secik.clear();
	on.clear();
	A.PB(X[0]);
	nxt.PB(-1);
	prv.PB(-1);
	on.PB(1);
	
	FOR(i, 1, SIZ(X) - 1)
	{
		while (!secik.empty() && -secik.begin()->f >= s - X[i].f)
		{
			PII x = *secik.begin();
			secik.erase(secik.begin());
			rem(x.s, s - X[i].f);
		}
		
		LL kw = (LL)(s - X[i].f - A.back().f) * (s - X[i].f - A.back().f - 1) / 2;
		mini(res, kw + X[i].s + A.back().s);
		
		on.PB(1);
		nxt.back() = SIZ(A);
		prv.PB(SIZ(A) - 1);
		nxt.PB(-1);
		A.PB(X[i]);
		check(SIZ(A) - 2);
	}
}

void DFS(int v, int pre)
{
	S[v] = 1;
	int sons = 0;
	for (auto x : V[v])
	{
		if (x != pre)
		{
			sons++;
			DFS(x, v);
			S[v] += S[x];
		}
	}
	dp[v] = (LL)S[v] * (S[v] - 1) / 2;
	VPII X;
	for (auto x : V[v])
	{
		if (x != pre)
		{
			mini(dp[v], dp[x] + (LL)(S[v] - S[x]) * (S[v] - S[x] - 1) / 2);
			X.PB(MP(S[x], dp[x]));
		}
	}
	
	if (sons > 1)
	{
		sort(ALL(X));
		debug(v);
		solve(n, X);
	}
}

main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%lld", &n);
	FOR(i, 2, n)
	{
		int a, b;
		scanf("%lld%lld", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	if (n == 2)
	{
		printf("2\n");
		return 0;
	}
	int root = 1;
	FOR(i, 1, n)
	{
		if (SIZ(V[i]) > 1)
		{
			root = i;
			break;
		}
	}
	debug(root);
	DFS(root, 0);
	printf("%lld\n", (LL)n * (n - 1) - res);
	return 0;
}