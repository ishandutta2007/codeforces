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

vector<PII> V;
set<PII> secik;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	FOR(i, 1, 3)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		
		V.PB(MP(a, b));
		secik.insert(MP(a, b));
	}
	sort(ALL(V));
	
	while (V[0].f < V[1].f)
	{
		V[0].f++;
		secik.insert(V[0]);
	}
	while (V[2].f > V[1].f)
	{
		V[2].f--;
		secik.insert(V[2]);
	}
	sort(ALL(V));
	while (V[0].s < V[1].s)
	{
		V[0].s++;
		secik.insert(V[0]);
	}
	while (V[2].s > V[1].s)
	{
		V[2].s--;
		secik.insert(V[2]);
	}
	
	printf("%d\n", SIZ(secik));
	for (auto p : secik)
	{
		printf("%d %d\n", p.f, p.s);
	}
	return 0;
}