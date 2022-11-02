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
const int M = 1024 * 1024;

int n, k;
char C[M];
VI V[2];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d%s", &n, &k, C);
	int mi[2] = {n, n}, ma[2] = {0, 0};
	FOR(i, 0, n - 1)
	{
		mini(mi[C[i] - '0'], i);
		maxi(ma[C[i] - '0'], i);
		V[C[i] - '0'].PB(i);
	}
	debug(mi[0], ma[0], mi[1], ma[1]);
	if (mi[0] == n || mi[1] == n || ma[0] - mi[0] < k || ma[1] - mi[1] < k)
	{
		printf("tokitsukaze\n");
		return 0;
	}
	bool boo = false;
	
	FOR(i, 0, 1)
	{
		debug(V[i]);
		if (V[i].back() - V[i][0] > k)
		{
			boo = true;
			break;
		}
		int j = 0;
		while (j < SIZ(V[i]) && V[i][j] < k)
		{
			j++;
		}
		debug(i, j);
		if (j < SIZ(V[i]) && V[i].back() - V[i][j] >= k)
		{
			boo = true;
			break;
		}
		j = SIZ(V[i]) - 1;
		while (j >= 0 && V[i][j] + k >= n)
		{
			j--;
		}
		debug(i, j);
		if (j >= 0 && V[i][j] - V[i][0] >= k)
		{
			boo = true;
			break;
		}
	}
	if (!boo)
	{
		printf("quailty\n");
	}
	else
	{
		printf("once again\n");
	}
	return 0;
}