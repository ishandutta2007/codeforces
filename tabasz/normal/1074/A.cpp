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

int n, m, res = 1e9;
vector<int> V, X;

int main() 
{
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	{
	  int a;
	  scanf("%d", &a);
	  V.PB(a);
	}
	FOR(i, 1, m)
	{
	  int a, b, c;
	  scanf("%d%d%d", &a, &b, &c);
	  if (a != 1)
	  {
	    continue;
	  }
	  X.PB(b);
	}
	V.PB(1000000000);
	sort(ALL(V));
	sort(ALL(X));
	int tmp = 0, r = 0;
	FOR(i, 0, SIZ(V) - 1)
	{
	  while (tmp < SIZ(X) && X[tmp] < V[i])
	  {
	    tmp++;
	  }
	  res = min(res, r + SIZ(X) - tmp);
	  r++;
	}
	printf("%d\n", res);
	return 0;
}