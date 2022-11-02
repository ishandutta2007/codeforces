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
const int M = 1024 * 10;

int n, m;
int T[M];
int B[M];
vector<PII> V;
set<PII> secik;

void put(int a)
{
	printf("%d\n", a);
	fflush(stdout);
}

int get()
{
	int a;
	scanf("%d", &a);
	return a;
}

int main()
{
	scanf("%d%d", &n, &m);
	int nn = 2 * n;
	FOR(i, 1, 2 * n)
	{
		scanf("%d", T + i);
	}
	FOR(i, 1, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (T[a] < T[b])
		{
			swap(a, b);
		}
		B[a] = 1;
		B[b] = 1;
		V.PB(MP(a, b));
	}
	FOR(i, 1, 2 * n)
	{
		if (!B[i])
		{
			secik.insert(MP(-T[i], i));
		}
	}
	int t;
	scanf("%d", &t);
	t--;
	while (nn)
	{
		debug(I(nn), V, secik, I(t));
		if (t == 0)
		{
			if (!V.empty())
			{
				put(V.back().f);
				V.pop_back();
				nn -= 2;
				get();
			}
			else
			{
				PII x = *(secik.begin());
				secik.erase(secik.begin());
				put(x.s);
				nn--;
				t = 1 - t;
			}
		}
		else
		{
			int x = get();
			if (B[x])
			{
				for(int i = 0; i < SIZ(V); i++)
				{
					if (V[i].f == x)
					{
						put(V[i].s);
						swap(V[i], V[SIZ(V) - 1]);
						V.pop_back();
						break;
					}
					if (V[i].s == x)
					{
						put(V[i].f);
						swap(V[i], V[SIZ(V) - 1]);
						V.pop_back();
						break;
					}
				}
				nn -= 2;
			}
			else
			{
				secik.erase(MP(-T[x], x));
				nn--;
				t = 1 - t;
			}
		}
	}
	return 0;
}