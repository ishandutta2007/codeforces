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

int n;
int T[M];

int ask()
{
	int k[2] = {0, 0};
	VI V[2];
	FOR(i, 1, n)
	{
		k[T[i]]++;
		V[T[i]].PB(i);
	}
	debug(k[0], k[1], V[0], V[1]);
	if (k[0] == 0 || k[1] == 0)
	{
		return 0;
	}
	printf("%d %d ", k[0], k[1]);
	for (auto x : V[0])
	{
		printf("%d ", x);
	}
	for (auto x : V[1])
	{
		printf("%d ", x);
	}
	printf("\n");
	fflush(stdout);
	int a;
	scanf("%d", &a);
	return a;
}

void solve()
{
	scanf("%d", &n);
	int res = 0;
	FORD(i, 8, 0)
	{
		FOR(j, 1, n)
		{
			T[j] = (j / (1<<i)) % 2;
		}
		maxi(res, ask());
	}
	printf("-1 %d\n", res);
	fflush(stdout);
}


int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}