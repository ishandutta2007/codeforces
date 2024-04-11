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
const int M = 1024;

const LL inf = 1e18;
int n, L, T[M], tmp;
PII R[M];

int query(int f, int x)
{
	printf("? %lld %lld\n", f, x);
	fflush(stdout);
	int a;
	scanf("%lld", &a);
	return a;
}

int getind(int f, int val, int st, int en)
{
	int mid = (st + en) / 2, r = st;
	while (st <= en)
	{
		if (query(f, mid) <= val)
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
	return r;
}

pair<VI, VI> split(VI V, int l, int r, int s1, int s2, int ask)
{
	debug(V, l, r, s1, s2, ask);
	swap(V[0], V[rand() % SIZ(V)]);
	
	int ind = getind(V[0], ask, l, r);
	VI V1, V2, V3;
	V3.PB(V[0]);
	FOR(i, 1, SIZ(V) - 1)
	{
		int ile = query(V[i], ind);
		if (ile > ask)
		{
			V1.PB(V[i]);
		}
		else if (ile < ask)
		{
			V2.PB(V[i]);
		}
		else
		{
			V3.PB(V[i]);
		}
	}
	while (!V3.empty() && SIZ(V1) < s1)
	{
		V1.PB(V3.back());
		V3.pb();
	}
	while (!V3.empty() && SIZ(V2) < s2)
	{
		V2.PB(V3.back());
		V3.pb();
	}
	
	if (SIZ(V1) < s1)
	{
		pair<VI, VI> x = split(V2, l, r, s1 - SIZ(V1), s2, ask);
		for (auto y : x.f)
		{
			V1.PB(y);
		}
		V2 = x.s;
	}
	else if (SIZ(V2) < s2)
	{
		pair<VI, VI> x = split(V1, l, r, s1, s2 - SIZ(V2), ask);
		for (auto y : x.s)
		{
			V2.PB(y);
		}
		V1 = x.f;
	}
	else
	{
		tmp = ind;
	}
	
	return MP(V1, V2);
}

void solve(int p, int k, int l, int r, int mi, int ma)
{
	if (p == k)
	{
		R[T[p]] = MP(l, r);
		return;
	}
	
	VI V;
	FOR(i, p, k)
	{
		V.PB(T[i]);
	}
	int mid = (p + k) / 2;
	int len = (ma - mi) / (k - p + 1);
	int ask = mi + len * (mid - p + 1);
	tmp = -1;
	pair<VI, VI> x = split(V, l, r, mid - p + 1, k - mid, ask);
	int spl = tmp;
	FOR(i, 0, SIZ(x.f) - 1)
	{
		T[p + i] = x.f[i];
	}
	FOR(i, 0, SIZ(x.s) - 1)
	{
		T[mid + 1 + i] = x.s[i];
	}
	
	solve(p, mid, l, spl, mi, ask);
	solve(mid + 1, k, spl, r, ask, ma);
}

main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%lld%lld", &n, &L);
	FOR(i, 1, n)
	{
		T[i] = i;
	}
	solve(1, n, 0, inf, 0, L);
	printf("!\n");
	FOR(i, 1, n)
	{
		printf("%lld %lld\n", R[i].f, R[i].s);
	}
	return 0;
}