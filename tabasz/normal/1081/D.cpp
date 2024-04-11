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
const int M = 1024 * 256;

int n, m, k, res;
vector<pair<int, PII>> V;
int T[M], S[M];

int find(int a)
{
	if (T[a] == a)
	{
		return a;
	}
	return T[a] = find(T[a]);
}

void onion(int a, int b, int c)
{
	a = find(a);
	b = find(b);
	if (a == b)
	{
		return;
	}
	debug(a, b, c, S[a], S[b]);
	if (S[a] && S[b])
	{
		maxi(res, c);
	}
	S[b] += S[a];
	S[a] = 0;
	T[a] = b;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 1, n)
	{
		T[i] = i;
	}
	FOR(i, 1, k)
	{
		int a;
		scanf("%d", &a);
		S[a]++;
	}
	FOR(i, 1, m)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		V.PB(MP(c, MP(a, b)));
	}
	sort(ALL(V));
	for (auto e : V)
	{
		onion(e.s.f, e.s.s, e.f);
	}
	FOR(i, 1, k)
	{
		printf("%d ", res);
	}
	printf("\n");
	return 0;
}