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
const int M = 1024 * 256;

int n, m, s;
int W[M], in[M], start[M], done[M];
VI V[M];
LL sum, r1, siz[M], r2, best;
LL bestd;

void DFS(int v, int pr, LL x)
{
	x += W[v];
	maxi(bestd, x);
	for (auto u : V[v])
	{
		if (u != pr)
		{
			DFS(u, v, x);
		}
	}
}

main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%lld%lld", &n, &m);
	FOR(i, 1, n)
	{
		scanf("%lld", W + i);
		sum += W[i];
	}
	FOR(i, 1, m)
	{
		int a, b;
		scanf("%lld%lld", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
		in[a]++;
		in[b]++;
	}
	scanf("%lld", &s);
	
	if (m == n - 1)
	{
		DFS(s, 0, 0);
		printf("%lld\n", bestd);
		return 0;
	}
	
	start[s] = 1;
	VI Q;
	int tmp = 0;
	FOR(i, 1, n)
	{
		if (in[i] == 1)
		{
			Q.PB(i);
		}
	}
	
	debug(s, sum, Q);
	while (!Q.empty())
	{
		tmp++;
		int v = Q.back();
		sum -= W[v];
		Q.pop_back();
		siz[v] += W[v];
		done[v] = 1;
		maxi(best, siz[v]);
		if (v == s)
		{
			r1 = siz[v];
			start[v] = 1;
		}
		if (start[v])
		{
			maxi(r2, siz[v]);
		}
		in[v]--;
		for (auto x : V[v])
		{
			if (!done[x])
			{
				in[x]--;
				if (start[v])
				{
					if (start[x] == 0)
					{
						siz[x] = siz[v];
					}
					start[x] = 1;
				}
				maxi(siz[x], siz[v]);
				if (in[x] == 1)
				{
					Q.PB(x);
				}
			}
		}
	}
	
	assert(tmp < n);
	if (!done[s])
	{
		printf("%lld\n", sum + best);
	}
	else
	{
		LL res = 0;
		LL lol = 0;
		FOR(i, 1, n)
		{
			if (!start[i])
			{
				maxi(lol, siz[i]);
			}
			if (!done[i] || start[i])
			{
				res += W[i];
			}
		}
		printf("%lld\n", res + lol);
	}
	return 0;
}