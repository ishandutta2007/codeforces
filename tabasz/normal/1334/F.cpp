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
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

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
const int M = 1024 * 512;

int n, m;
int T[M], P[M], A[M];
LL sum, D[2 * M];
set<PII> secik;

LL get(int v)
{
	v += M;
	LL r = D[v];
	while (v > 1)
	{
		v /= 2;
		r += D[v];
	}
	return r;
}

void add(int p, int k, LL val)
{
	p += M;
	k += M;
	D[p] += val;
	if (p != k)
	{
		D[k] += val;
	}
	while (p / 2 != k / 2)
	{
		if (p % 2 == 0)
		{
			D[p + 1] += val; 
		}
		p /= 2;
		if (k % 2 == 1)
		{
			D[k - 1] += val; 
		}
		k /= 2;
	}
	return;
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		scanf("%d", T + i);
	}
	FOR(i, 1, n)
	{
		scanf("%d", P + i);
		sum += P[i];
	}
	scanf("%d", &m);
	FOR(i, 1, m)
	{
		scanf("%d", A + i);
		secik.insert(MP(A[i], i));
		D[i + M] = -INF;
	}
	FOR(i, 1, n)
	{
		auto it = secik.lower_bound(MP(T[i], 0));
		if (it == secik.end())
		{
			continue;
		}
		int ind = (*it).s;
		int val = (*it).f;
		if (P[i] > 0)
		{
			add(ind, n, P[i]);
		}
		if (val == T[i])
		{
			LL prv = get(ind - 1), here = get(ind);
			add(ind, ind, max(0LL, prv + P[i] - here));
		}
	}
	LL x = get(m);
	if (x < -1e16L)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n%lld\n", sum - x);
	}
}