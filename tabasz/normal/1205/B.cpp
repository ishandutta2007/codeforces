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
const int M = 1024 * 128;
const LL inf = 1e18;

int n, T[M], vis[M], res = inf;
VI V[M];

void cycle(int v)
{
	vis[v] = 0;
	queue<int> Q;
	Q.push(v);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (auto x : V[u])
		{
			if (vis[x] == inf)
			{
				vis[x] = vis[u] + 1;
				Q.push(x);
			}
			else if (vis[x] >= vis[u])
			{
				mini(res, vis[x] + vis[u] + 1);
			}
		}
	}
}

main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%lld", &n);
	int tmp = 0;
	FOR(i, 1, n)
	{
		LL a;
		scanf("%lld", &a);
		if (a != 0)
		{
			tmp++;
			T[tmp] = a;
		}
	}
	if (tmp > 130)
	{
		printf("3\n");
		return 0;
	}
	
	FOR(i, 1, tmp)
	{
		FOR(j, i + 1, tmp)
		{
			if (T[i] & T[j])
			{
				V[i].PB(j);
				V[j].PB(i);
			}
		}
	}

	FOR(i, 1, tmp)
	{
		FOR(j, 1, tmp)
		{
			vis[j] = inf;
		}
		cycle(i);
	}
	
	if (res == inf)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n", res);
	}
	return 0;
}