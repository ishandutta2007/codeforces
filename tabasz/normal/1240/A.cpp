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

int n;
int x, y, a, b, k;
VI V;

bool check(int l)
{
	int xy = 0, xx = 0, yy = 0;
	FOR(i, 1, l)
	{
		if (i % a == 0 && i % b == 0)
		{
			xy++;
		}
		else if (i % a == 0)
		{
			xx++;
		}
		else if (i % b == 0)
		{
			yy++;
		}
	}
	LL res = 0;
	int tmp = SIZ(V) - 1;
	debug(l, xy, xx, yy, V, x, y, a, b);
	while (xy)
	{
		res += (LL)V[tmp] * (x + y);
		xy--;
		tmp--;
	}
	while (xx)
	{
		res += (LL)V[tmp] * x;
		xx--;
		tmp--;
	}
	while (yy)
	{
		res += (LL)V[tmp] * y;
		yy--;
		tmp--;
	}
	debug(res, k);
	return res >= k;
}

void solve()
{
	scanf("%lld", &n);
	V.clear();
	FOR(i, 1, n)
	{
		int a;
		scanf("%lld", &a);
		V.PB(a / 100);
	}
	sort(ALL(V));
	scanf("%lld%lld%lld%lld%lld", &x, &a, &y, &b, &k);
	if (x < y)
	{
		swap(x, y);
		swap(a, b);
	}
	int st = 1, en = n, mid = (st + en) / 2, r = n + 1;
	while (st <= en)
	{
		if (check(mid))
		{
			mini(r, mid);
			en = mid - 1;
		}
		else
		{
			st = mid + 1;
		}
		mid = (st + en) / 2;
	}
	if (r == n + 1)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n", r);
	}
}

main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	int t;
	scanf("%lld", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}