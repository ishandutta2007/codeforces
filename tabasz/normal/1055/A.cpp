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
const int M = 1024;

int n, k;
int T[2][M], vis[M];
vector<int> V[M];

void DFS(int v)
{
	vis[v] = true;
	for (auto x : V[v])
	{
		if (!vis[x])
		{
			DFS(x);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	FOR(i, 0, 1)
	{
		FOR(j, 1, n)
		{
			scanf("%d", T[i] + j);
		}
	}
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			if (i < j && T[0][i] && T[0][j])
			{
				V[i].PB(j);
			}
			if (i > j && T[1][i] && T[1][j])
			{
				V[i].PB(j);
			}
		}
	}
	DFS(1);
	
	if (vis[k])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}