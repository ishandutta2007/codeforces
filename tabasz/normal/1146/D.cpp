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
const int M = 1024 * 512;

int gcd(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}

int dist[M];

PII solve(int m, int a, int b)
{
	int mx = 2 * (a + b);
	//int mx = max(2 * a, 2 * b);
	debug(m, a, b, mx);
	priority_queue<PII> Q;
	Q.push(MP(0, 0));
	dist[0] = 0;
	FOR(i, 1, mx)
	{
		dist[i] = 1e9;
	}
	while (!Q.empty())
	{
		PII x = Q.top();
		Q.pop();
		x.f *= -1;
		if (x.f != dist[x.s])
		{
			continue;
		}
		if (mx >= x.s + a && dist[x.s + a] > max(x.s + a, x.f))
		{
			dist[x.s + a] = max(x.s + a, x.f);
			Q.push(MP(-dist[x.s + a], x.s + a));
		}
		if (x.s >= b && dist[x.s - b] > x.f)
		{
			dist[x.s - b] = x.f;
			Q.push(MP(-dist[x.s - b], x.s - b));
		}
	}
	assert(dist[mx] == mx);
	FOR(i, 0, mx)
	{
		assert(dist[i] != 1e9);
		debug(i, dist[i]);
	}
	PII res;
	if (m > mx)
	{
		res.s = m + 1;
		res.f += (mx + m + 3) * (m - mx) / 2;
	}
	VI V;
	FOR(i, 0, mx)
	{
		V.PB(dist[i]);
	}
	sort(ALL(V));
	int tmp = 0;
	FOR(i, 0, min(mx, m))
	{
		while (tmp < SIZ(V) && V[tmp] <= i)
		{
			tmp++;
		}
		if (i == m)
		{
			res.s = tmp;
		}
		res.f += tmp;
	}
	return res;
}

main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	int m, a, b;
	scanf("%lld%lld%lld", &m, &a, &b);
	int gc = gcd(a, b);
	a /= gc;
	b /= gc;
	int rest = (m + 1) % gc;
	rest = (gc - rest) % gc;
	m /= gc;
	PII res = solve(m, a, b);
	debug(res, gc, rest);
	printf("%lld\n", res.f * gc - rest * res.s);
	return 0;
}