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
const int M = 1025;

int n;
bool B[2][M];
vector<int> V[M], X, Y;

int get(char c, int x)
{
	printf("%c %d\n", c, x);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

int DFS(int v, int pr)
{
	if (B[0][v])
	{
		return v;
	}
	for (auto u : V[v])
	{
		if (u != pr)
		{
			int x = DFS(u, v);
			if (x != -1)
			{
				return x;
			}
		}
	}
	return -1;
}

void solve()
{
	FOR(i, 0, M - 1)
	{
		B[0][i] = 0;
		B[1][i] = 0;
		V[i].clear();
	}
	X.clear();
	Y.clear();
	scanf("%d", &n);
	FOR(i, 1, n - 1)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	int x, y;
	scanf("%d", &x);
	FOR(i, 1, x)
	{
		int a;
		scanf("%d", &a);
		X.PB(a);
		B[0][a] = true;
	}
	scanf("%d", &y);
	FOR(i, 1, y)
	{
		int a;
		scanf("%d", &a);
		Y.PB(a);
		B[1][a] = true;
	}
	int v = get('B', Y[0]);
	int u = DFS(v, 0);
	int qwe = get('A', u);
	if (B[1][qwe])
	{
		printf("C %d\n", u);
		fflush(stdout);
	}
	else
	{
		printf("C -1\n");
		fflush(stdout);
	}
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