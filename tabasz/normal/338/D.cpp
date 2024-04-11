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
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define LL long long
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define PLL pair<LL, LL>
#define I(x) #x " =", (x), " "
#define A(a, i) #a "[" #i " =", i, "] =", a[i], " "

LL nwdr(LL a, LL b, LL &x, LL &y) {
	if (b == 0) {
		x = y = 1;
		return a;
	}
	LL xx, yy;
	LL ret = nwdr(b, a % b, xx, yy);
	x = yy;
	y = xx- yy * (a / b);
	return ret;
}

#define NONE make_pair(0LL, 0LL)

LL mul(LL a,LL b, LL m)
{
	 LL q=(LL)((LD)a*(LD)b/(LD)m);
	 LL r=a*b-q*m; // ma si przekrca
	 return (r%m+m)%m;
}

//para (a, b) reprezentuje rwnanie x === a (mod b)
//para (0, 0) reprezentuje rwnanie sprzeczne
PLL CRT(PLL p, PLL q)
{
	if (p == NONE || q == NONE)
		return NONE;
	LL k, l;
	LL g = nwdr(p.s, q.s, k, l);
	if ((p.f - q.f) % g)
		return NONE;
	LL mod = p.s / g * q.s;
	//LL ans = p.f + p.s * ((q.f - p.f) / g) % mod * k % mod; //Jeli tu grozi overflow,
	LL ans = p.f + mul(mul(p.s, ((q.f - p.f) / g), mod),  k, mod);
	if (ans < 0)
		ans += mod;
	return make_pair(ans, mod);
}
//to zastpi to przez LL ans = p.f + mul(mul(p.s, ((q.f - p.f) / g), mod),  k, mod);

LL n, m, k;
vector<LL> V;
vector<PLL> X;

int main()
{
	scanf("%lld%lld%lld", &n, &m, &k);
	LL lcm = 1;
	FOR(i, 1, k)
	{
		LL a;
		scanf("%lld", &a);
		V.PB(a);
		LL gc = __gcd(lcm, a);
		a /= gc;
		if ((LD)lcm * a > n)
		{
			debug(n, a, lcm);
			printf("NO\n");
			return 0;
		}
		lcm *= a;
		if (lcm > n)
		{
			printf("NO\n");
			return 0;
		}
	}
	FOR(i, 0, k - 1)
	{
		X.PB(MP((V[i] - i % V[i]) % V[i], V[i]));
	}
	PLL tmp = X[0];
	FOR(i, 1, k - 1)
	{
		tmp = CRT(tmp, X[i]);
		if (tmp == NONE)
		{
			printf("NO\n");
			return 0;
		}
	}
	if (tmp.f == 0)
	{
		tmp.f = tmp.s;
	}
	if (tmp.f + k - 1 > m)
	{
		debug("b");
		printf("NO\n");
		return 0;
	}
	debug(tmp);
	FOR(i, 0, k - 1)
	{
		if (__gcd(tmp.f + i, lcm) != V[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}