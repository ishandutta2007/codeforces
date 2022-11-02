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
const int M = 10000001;

int n;
int res;

int get(VI& V, int x)
{
	int st = 0, en = SIZ(V) - 1, mid = (st + en) / 2, r = -1;
	while (st <= en)
	{
		if (V[mid] < x)
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
	return r + 1;
}

void jebaj(VI V, int ind)
{
	LL ile = 0;
	int pocz = (1<<ind), kon = (1<<(ind + 1)) - 1, pocz2 = (1<<(ind + 1)) + (1<<(ind));
	for (auto x : V)
	{
		if ((x + x >= pocz && x + x <= kon) || x + x >= pocz2)
		{
			ile--;
		}
		ile += SIZ(V);
		ile -= get(V, pocz2 - x);
		ile += get(V, kon + 1 - x);
		ile -= get(V, pocz - x);
		//debug(x, ile, pocz, kon, pocz2);
	}
	
	ile /= 2;
	//debug(V, ind, ile);
	if (ile % 2 == 1)
	{
		res += (1<<ind);
	}
	if (ind > 0)
	{
		for (auto &x : V)
		{
			x %= (1<<ind);
		}
		sort(ALL(V));
		jebaj(V, ind - 1);
	}
}

int32_t main()
{
	VI V;
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		int a;
		scanf("%d", &a);
		V.PB(a);
	}
	sort(ALL(V));
	jebaj(V, 24);
	
	printf("%d\n", res);
}