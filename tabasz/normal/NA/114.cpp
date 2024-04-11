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
const int M = 1024 * 1024;

int n;

PII dziel(LL x)
{
	vector<LL> X;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			X.PB(i);
			while (x % i == 0)
			{
				x /= i;
			}
		}
	}
	if (x != 1)
	{
		X.PB(x);
	}
	if (SIZ(X) < 2)
	{
		return MP(-1, -1);
	}
	return MP(X[0], X[1]);
}

main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%lld", &n);
	PII x = dziel(n);
	if (x.s == -1)
	{
		printf("NO\n");
		return 0;
	}
	LL p1 = x.f, p2 = x.s;
	LL b = 1;
	while ((n - 1 - b * p2) % p1 != 0)
	{
		b++;
	}
	LL a = (n - 1 - b * p2) / p1;
	printf("YES\n2\n%lld %lld\n%lld %lld\n", a, n / p1, b, n / p2);
}