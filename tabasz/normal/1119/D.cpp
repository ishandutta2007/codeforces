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

#define int LL
#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "
const int M = 1024 * 128;

int n, q;
VI V;
VPII Q;
int R[M];
VPII difs;
int T[M], sp, sumlen;
PII L[M];
set<int> secik;

int find(int a)
{
	if (T[a] == a)
	{
		return a;
	}
	return T[a] = find(T[a]);
}

void join(int i)
{
	sp--;
	int x = find(i);
	int y = find(i + 1);
	sumlen -= L[x].s - L[x].f + 1;
	sumlen -= L[y].s - L[y].f + 1;
	debug(i, x, y, L[x], L[y]);
	L[x] = MP(L[x].f, L[y].s);
	sumlen += L[x].s - L[x].f + 1;
	T[y] = x;
}

main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%lld", &n);
	FOR(i, 1, n)
	{
		int a;
		scanf("%lld", &a);
		if (!secik.count(a))
		{
			V.PB(a);
			secik.insert(a);
		}
	}
	sp = SIZ(V);
	sumlen = SIZ(V);
	sort(ALL(V));
	FOR(i, 0, SIZ(V) - 1)
	{
		L[i] = MP(V[i], V[i]);
		T[i] = i;
	}
	
	FOR(i, 0, SIZ(V) - 2)
	{
		difs.PB(MP(V[i + 1] - V[i], i));
	}
	sort(ALL(difs));
	scanf("%lld", &q);
	FOR(i, 1, q)
	{
		int l, r;
		scanf("%lld%lld", &l, &r);
		Q.PB(MP(r - l + 1, i));
	}
	sort(ALL(Q));
	
	int tmp = 0;
	for (auto p : Q)
	{
		while (tmp < SIZ(difs) && difs[tmp].f < p.f)
		{
			join(difs[tmp].s);
			tmp++;
		}
		debug(sumlen, sp, p);
		R[p.s] = sumlen + sp * (p.f - 1);
	}
	FOR(i, 1, q)
	{
		printf("%lld ", R[i]);
	}
	printf("\n");
	return 0;
}