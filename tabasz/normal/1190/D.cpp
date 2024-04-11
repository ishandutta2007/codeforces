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
const int M = 1024 * 512;

int n;
unordered_map<int, int> mapa;
VPII V;
VI T[M];
int D[2 * M];
LL res;

void add(int v)
{
	v += M;
	D[v] = 1;
	while (v > 1)
	{
		v /= 2;
		D[v] = D[2 * v] + D[2 * v + 1];
	}
}

int sum(int p, int k)
{
	p += M;
	k += M;
	int r = D[p];
	if (p != k)
	{
		r += D[k];
	}
	while (p / 2 != k / 2)
	{
		if (p % 2 == 0)
		{
			r += D[p + 1];
		}
		p /= 2;
		if (k % 2 == 1)
		{
			r += D[k - 1];
		}
		k /= 2;
	}
	return r;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	VI X;
	FOR(i, 1, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		V.PB(MP(x, y));
		X.PB(x);
		X.PB(y);
	}
	sort(ALL(X));
	int prev = -1, tmp = 0;
	for (auto x : X)
	{
		if (x != prev)
		{
			prev = x;
			tmp++;
			mapa[prev] = tmp;
		}
	}
	for (auto& x : V)
	{
		x.f = mapa[x.f];
		x.s = mapa[x.s];
		T[x.s].PB(x.f);
	}
	FORD(i, M - 1, 0)
	{
		sort(ALL(T[i]));
		FOR(j, 0, SIZ(T[i]) - 1)
		{
			add(T[i][j]);
			PII l = MP(0, T[i][j]);
			PII r = MP(T[i][j], M - 1);
			if (j != SIZ(T[i]) - 1)
			{
				r.s = T[i][j + 1] - 1;
			}
			res += (LL)sum(l.f, l.s) * sum(r.f, r.s);
		}
	}
	
	printf("%lld\n", res);
	return 0;
}