//tabasz
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
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
const int inf = 1e9+7;
const LL INF = 1e18L+7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "
#define int LL
const int M = 1024 * 1024 * 2;

int n;
int T[2][M], D[2 * M], P[M], s[2];

void add(int v, int x)
{
	v += M;
	D[v] = x;
	while (v > 1)
	{
		v /= 2;
		D[v] = max(D[2 * v], D[2 * v + 1]);
	}
}

int mxi(int p, int k)
{
	p += M;
	k += M;
	int r = max(D[p], D[k]);
	while (p / 2 != k / 2)
	{
		if (p % 2 == 0)
		{
			maxi(r, D[p + 1]);
		}
		p /= 2;
		if (k % 2 == 1)
		{
			maxi(r, D[k - 1]);
		}
		k /= 2;
	}
	return r;
}

void solve()
{
	scanf("%lld", &n);
	FOR(i, 0, 1)
	{
		s[i] = 0;
		FOR(j, 1, n)
		{
			scanf("%lld", T[i] + j);
			s[i] += T[i][j];
		}
	}
	if (s[0] > s[1])
	{
		printf("NO\n");
		return;
	}
	FOR(i, 1, n)
	{
		P[i] = T[0][i] - T[1][i];
		P[n + i] = P[i];
	}
	FOR(i, 1, 2 * n)
	{
		P[i] += P[i - 1];
		debug(i, P[i]);
		add(i, P[i]);
	}
	bool good = 1;
	FOR(i, 1, n)
	{
		int start = T[0][i] - T[1][i];
		if (i == 1)
		{
			start -= T[1][n];
		}
		else
		{
			start -= T[1][i - 1];
		}
		int mx = mxi(i + 1, i + n - 1);
		mx -= P[i];
		maxi(mx, 0);
		
		debug(i, start, mx);
		if (start + mx > 0)
		{
			good = false;
			break;
		}
	}
	if (good)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	int t;
	scanf("%lld", &t);
	while (t--)
	{
		solve();
	}
}