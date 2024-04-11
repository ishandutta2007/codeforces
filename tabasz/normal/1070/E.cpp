#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
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
#define ll long long
#define st first
#define nd second
#define pb push_back
#define eb emplace_back
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define Sim template<class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.st << ", " << x.nd << ">";}
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
const int M = 1024 * 256;


LL n, m, t;
int T[M];
vector<int> V;

PII check(int val)
{
	if (val == 0)
	{
		return MP(0, 1);
	}
	int ma = V[val - 1];
	vector<int> X;
	for (int i = 0; i < n; i++)
	{
		if (T[i] <= ma)
		{
			X.PB(T[i]);
		}
	}
	int res = 0;
	LL tmp = 0, il = 0, cz = 0;
	for (auto x : X)
	{
		il++;
		tmp += x;
		cz += x;
		if (tmp > t)
		{
			return MP(res, ma);
		}
		res++;
		if (il == m)
		{
			il = 0;
			tmp += cz;
			cz = 0;
			if (tmp >= t)
			{
				return MP(res, ma);
			}
		}
	}
	return MP(res, ma);
	
}

void solve()
{
	V.clear();
	scanf("%lld%lld%lld", &n, &m, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", T + i);
		V.PB(T[i]);
	}
	sort(ALL(V));
	
	int d = 1;
	int st = 0, en = n, mid = (st + en) / 2, r = 0;
	while (st <= en)
	{
		PII x = check(mid);
		if (x.f >= mid)
		{
			if (mid > r)
			{
				r = max(r, mid);
				d = x.s;
			}
			st = mid + 1;
		}
		else
		{
			en = mid - 1;
		}
		mid = (st + en) / 2;
	}
	printf("%d %d\n", r, d);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	
	return 0;
}