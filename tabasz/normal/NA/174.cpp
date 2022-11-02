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

vector<PLL> V[M];
LL T[M], n, kk;
PII P[M];

void DFS(int v, LL x)
{
	T[v] = x;
	for (auto u : V[v])
	{
		DFS(u.f, x ^ u.s);
	}
}

LL solve(LL pref, int dep, LL k)
{
	debug(pref, dep, k);
	if (dep == -1)
	{
		return pref;
	}
	LL tmp = 0, pril = 0;
	FOR(i, 1, n)
	{
		if (i > 1 && (T[i]>>dep) == (T[i - 1]>>dep))
		{
			tmp += pril;
			debug(i, P[i].f, P[i].s, tmp);
			continue;
		}
		PII x = P[i];
		while (x.f <= x.s && ((T[i] ^ T[x.f])>>dep) != (pref>>dep))
		{
			x.f++;
		}
		while (x.f <= x.s && ((T[i] ^ T[x.s])>>dep) != (pref>>dep))
		{
			x.s--;
		}
		pril = x.s - x.f + 1;
		tmp += pril;
		debug(i, x.f, x.s, tmp);
	}
	debug("ololololol", k, tmp);
	if (tmp < k)
	{
		k -= tmp;
		pref += (1LL<<dep);
	}
	FOR(i, 1, n)
	{
		if (i > 1 && (T[i]>>dep) == (T[i - 1]>>dep))
		{
			P[i] = P[i - 1];
			continue;
		}
		while (P[i].f <= P[i].s && ((T[i] ^ T[P[i].f])>>dep) != (pref>>dep))
		{
			P[i].f++;
		}
		while (P[i].f <= P[i].s && ((T[i] ^ T[P[i].s])>>dep) != (pref>>dep))
		{
			P[i].s--;
		}
	}
	return solve(pref, dep - 1, k);
}

int main() 
{
	scanf("%lld%lld", &n, &kk);
	FOR(i, 1, n - 1)
	{
		LL a, b;
		scanf("%lld%lld", &a, &b);
		V[a].PB(MP(i + 1, b));
	}
	DFS(1, 0);
	
	FOR(i, 1, n)
	{
		debug(i, T[i]);
	}
	sort(T + 1, T + n + 1);
	
	FOR(i, 1, n)
	{
		P[i] = MP(1, n);
	}
	
	printf("%lld\n", solve(0, 61, kk));
	return 0;
}