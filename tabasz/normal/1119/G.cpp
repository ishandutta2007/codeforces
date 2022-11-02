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

int n, m, s, res;
int T[M], TT[M];
int S[M];
vector<VI> R;
int inds[M];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &m);
	FOR(i, 1, m)
	{
		scanf("%d", TT + i);
		s += TT[i];
	}
	res = (s + n - 1) / n;
	R.resize(res, VI(m));
	int ind = 1, tmps = 0, now = n;
	VPII prefs;
	FOR(i, 1, m)
	{
		T[i] = TT[i];
	}
	FOR(i, 1, m - 1)
	{
		while (T[i] > now)
		{
			T[i] -= now;
			tmps = 0;
			now = n;
		}
		now -= T[i];
		tmps += T[i];
		prefs.PB(MP(tmps, ind));
		ind++;
	}
	sort(ALL(prefs));
	prefs.PB(MP(n, m));
	debug(prefs);
	FOR(i, 0, SIZ(prefs) - 1)
	{
		inds[prefs[i].s] = i;
		S[i] = prefs[i].f;
		if (i > 0)
		{
			S[i] -= prefs[i - 1].f;
		}
		debug(i, S[i]);
	}
	
	int turn = 0;
	ind = 1;
	now = n;
	int typ = 0;
	FOR(i, 1, m)
	{
		T[i] = TT[i];
	}
	FOR(i, 1, m)
	{
		while (T[i] > now || (i == m && T[i] > 0))
		{
			debug(i, T[i], now, turn, typ, m - 1);
			FOR(j, typ, m - 1)
			{
				R[turn][j] = i;
			}
			T[i] -= now;
			now = n;
			turn++;
			typ = 0;
		}
		if (i == m && T[i] <= 0)
		{
			break;
		}
		now -= T[i];
		debug(i, now, turn, typ, inds[ind]);
		FOR(j, typ, inds[ind])
		{
			R[turn][j] = i;
		}
		typ = inds[ind] + 1;
		
		ind++;
	}
	
	printf("%d\n", res);
	FOR(i, 0, m - 1)
	{
		printf("%d ", S[i]);
	}
	printf("\n");
	FOR(i, 0, res - 1)
	{
		FOR(j, 0, m - 1)
		{
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}
	return 0;
}