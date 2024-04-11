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
const int M = 1024 * 128;

int n, m, q;
VPII in[M], out[M];
LL res;

void rem(int v, int ind)
{
	if (ind != SIZ(out[v]) - 1)
	{
		in[out[v].back().f][out[v].back().s] = MP(v, ind);
		swap(out[v][ind], out[v].back());
	}
	
	out[v].pb();
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &m);
	FOR(i, 1, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b)
		{
			swap(a, b);
		}
		in[a].PB(MP(b, SIZ(out[b])));
		out[b].PB(MP(a, SIZ(in[a]) - 1));
	}
	FOR(i, 1, n)
	{
		res += (LL)SIZ(in[i]) * SIZ(out[i]);
	}
	printf("%lld\n", res);
	scanf("%d", &q);
	FOR(i, 1, q)
	{
		int v;
		scanf("%d", &v);
		res -= (LL)SIZ(in[v]) * SIZ(out[v]);
		for (auto x : in[v])
		{
			res -= (LL)SIZ(in[x.f]) * SIZ(out[x.f]);
			out[v].PB(MP(x.f, SIZ(in[x.f])));
			in[x.f].PB(MP(v, SIZ(out[v]) - 1));
			
			rem(x.f, x.s);
			
			res += (LL)SIZ(in[x.f]) * SIZ(out[x.f]);
		}
		in[v].clear();
		printf("%lld\n", res);
	}
	return 0;
}