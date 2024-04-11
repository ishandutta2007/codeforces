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

LL res = 0;
LL a1, b1, t1, a2, b2, t2;

LL check(PLL x, PLL y)
{
	while (y.f < 0)
	{
		y.f += t1;
	}
	y.f %= t1;
	while (y.s < 0)
	{
		y.s += t1;
	}
	y.s %= t1;
	if (y.f > y.s)
	{
		return max(check(x, MP(0, y.s)), check(x, MP(y.f, t1 - 1)));
	}
	LL p = max(x.f, y.f), k = min(x.s, y.s);
	return max(0LL, k - p + 1);
}

int main() 
{
	scanf("%lld%lld%lld%lld%lld%lld", &a1, &b1, &t1, &a2, &b2, &t2);
	if (b1 - a1 < b2 - a2)
	{
		swap(a1, a2);
		swap(b1, b2);
		swap(t1, t2);
	}
	a2 %= t1;
	b2 %= t1;
	LL gc = __gcd(t1, t2);
	LL tmp1 = a2, tmp2 = b2;
	LL il = (t1 + a1 - a2) / gc;
	tmp1 += il * gc;
	tmp2 += il * gc;
	for (LL i = -5; i <= 5; i++)
	{
		res = max(res, check(MP(a1, b1), MP(tmp1 + i * gc, tmp2 + i * gc)));
	}
	printf("%lld\n", res);
	return 0;
}