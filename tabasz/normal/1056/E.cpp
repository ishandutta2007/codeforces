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
const LL mod = 1e9 + 33;
const int M = 1024 * 1024;
const LL p = 10009;
const LL p2 = 10007;

string s, t;
int x, y, n, res;

LL A[M], H[M], P[M];

bool pierw(int l)
{
	assert(n % l == 0);
	FOR(i, l, n - 1)
	{
		if (t[i] != t[i - l])
		{
			return false;
		}
	}
	return true;
}

LL makeh(int p, int k)
{
	LL h = H[k];
	if (p > 0)
	{
		h -= (H[p - 1] * P[k - p + 1]) % mod;
		if (h < 0)
		{
			h += mod;
		}
	}
	debug("hash", p, k, h);
	return h;
}

void check(int l0, int l1)
{
	assert(l0 * x + l1 * y == n);
	debug("?   ", l0, l1);
	LL h0 = -1;
	LL h1 = -1;
	int tmp = 0;
	for (auto x : s)
	{
		if (x == '0')
		{
			if (h0 == -1)
			{
				h0 = makeh(tmp, tmp + l0 - 1);
			}
			else if (makeh(tmp, tmp + l0 - 1) != h0)
			{
				debug(I(tmp), I(x));
				return;
			}
			tmp += l0;
		}
		else
		{
			if (h1 == -1)
			{
				h1 = makeh(tmp, tmp + l1 - 1);
			}
			else if (makeh(tmp, tmp + l1 - 1) != h1)
			{
				debug(I(tmp), I(x));
				return;
			}
			tmp += l1;
		}
	}
	debug(l0, l1);
	res++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> s >> t;
	
	n = SIZ(t);
	FOR(i, 0, n - 1)
	{
		A[i] = ((LL)t[i] * p2) % mod;
	}
	P[0] = 1;
	FOR(i, 1, n)
	{
		P[i] = (P[i - 1] * p) % mod;
	}
	FOR(i, 0, n - 1)
	{
		if (i > 0)
		{
			H[i] = (H[i - 1] * p) % mod;
		}
		H[i] += A[i];
		if (H[i] >= mod)
		{
			H[i] -= mod;
		}
	}
	for (auto c : s)
	{
		if (c == '0')
		{
			x++;
		}
		else
		{
			y++;
		}
	}
	int gc = __gcd(x, y);
	
	int xx = x / gc;
	int yy = y / gc;
	debug(I(x), I(y), I(gc), I(n));
	if (n % gc != 0)
	{
		cout << "0\n";
		return 0;
	}
	int nn = n / gc;
	
	for (int i = 1; i * xx < nn; i++)
	{
		if ((nn - (i * xx)) % yy == 0)
		{
			check(i, ((nn - (i * xx)) / yy));
		}
	}
	if (nn % (xx + yy) == 0)
	{
		if (pierw(nn / (xx + yy)))
		{
			res--;
		}
	}
	cout << res << "\n";
	return 0;
}