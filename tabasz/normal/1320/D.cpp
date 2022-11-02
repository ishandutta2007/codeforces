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
#define int LL
const LL p = 10009;
const LL p2 = 10037;
const LL mod = 1e9 + 33;
const LL mod2 = 1e9 + 7;
const int M = 1024 * 256;

struct node
{
	int has, l, lef, rig;
};

ostream & operator << (ostream &pp, node x)
{
	return pp << "<" << x.has << ", " << x.l << ", " << x.lef << ", " << x.rig << ">";
}

bool operator== (node x, node y)
{
	return x.has == y.has && x.l == y.l && x.lef == y.lef && x.rig == y.rig;
}

int n, q;
LL P[M], odw, odw2, P2[M];
node D[2 * M], empt;
char C[M];

LL poww(LL x, LL e, LL modd)
{
	if (e == 0)
	{
		return 1;
	}
	if (e % 2 == 0)
	{
		return poww(x * x % modd, e / 2, modd);
	}
	return poww(x, e - 1, modd) * x % modd;
}

node join(node a, node b)
{
	node res;
	if (a == empt)
	{
		return b;
	}
	if (b == empt)
	{
		return a;
	}
	//debug(a, b);
	if (a.rig == 0 && b.lef == 0)
	{
		a.has *= odw;
		a.has %= mod;
		if (a.l > 1)
		{
			a.l--;
		}
		if (b.l > 1)
		{
			b.l--;
		}
	}
	//debug(a, b);
	res.l = a.l + b.l - 1;
	res.lef = a.lef;
	if (a.l == 1)
	{
		res.lef += b.lef;
	}
	res.has = a.has;
	res.has += b.lef;
	res.has %= mod;
	res.has = ((res.has * P[b.l - 1] + b.has - b.lef * P[b.l - 1]) % mod + mod) % mod;
	res.rig = b.rig;
	if (b.l == 1)
	{
		res.rig += a.rig;
	}
	
	return res;
}

node query(int v, int vp, int vk, int pp, int k)
{
	if (vp > k || vk < pp)
	{
		return empt;
	}
	if (vp >= pp && vk <= k)
	{
		return D[v];
	}
	int mid = (vp + vk) / 2;
	node a = query(2 * v, vp, mid, pp, k);
	node b = query(2 * v + 1, mid + 1, vk, pp, k);
	return join(a, b);
}

int32_t main()
{
	P[0] = 1;
	P2[0] = 1;
	odw = poww(p, mod - 2, mod);
	odw2 = poww(p2, mod2 - 2, mod2);
	FOR(i, 1, M - 1)
	{
		P[i] = P[i - 1] * p % mod;
		P2[i] = P2[i - 1] * p2 % mod2;
	}
	empt = {0, 1, 0, 0};
	scanf("%lld %s", &n, C);
	FOR(i, 0, n - 1)
	{
		if (C[i] == '0')
		{
			D[M + i] = {1, 1, 1, 1};
		}
		else
		{
			D[M + i] = {0, 2, 0, 0};
		}
	}
	FORD(i, M - 1, 1)
	{
		D[i] = join(D[2 * i], D[2 * i + 1]);
	}
	scanf("%lld", &q);
	FOR(i, 1, q)
	{
		int a, b, l;
		scanf("%lld%lld%lld", &a, &b, &l);
		a--;
		b--;
		debug(i, a, b, l);		
		node x = query(1, 0, M - 1, a, a + l - 1);
		node y = query(1, 0, M - 1, b, b + l - 1);
		debug(x, y);
		if (x.has == y.has && x.l == y.l)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}