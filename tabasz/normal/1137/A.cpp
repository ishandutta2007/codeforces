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
const int M = 1024;

int n, m;
vector<pair<int, PII>> V;
int X[2][M], Y[2][M];
PII T[M][M];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			int a;
			scanf("%d", &a);
			V.PB(MP(a, MP(i, j)));
		}
	}
	sort(ALL(V));
	int pr = -1, tmp = 0;
	for (auto x : V)
	{
		if (pr != x.f)
		{
			tmp++;
			pr = x.f;
		}
		if (Y[0][x.s.f] != tmp)
		{
			Y[0][x.s.f] = tmp;
			X[0][x.s.f]++;
		}
		if (Y[1][x.s.s] != tmp)
		{
			Y[1][x.s.s] = tmp;
			X[1][x.s.s]++;
		}
		T[x.s.f][x.s.s] = MP(X[0][x.s.f], X[1][x.s.s]);
	}
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			printf("%d ", max(T[i][j].f, T[i][j].s) + max(X[0][i] - T[i][j].f, X[1][j] - T[i][j].s));
		}
		printf("\n");
	}
	return 0;
}