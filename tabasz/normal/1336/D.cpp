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
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "
const int M = 1024;

int n;
int a, b;
int add[M], ile[M * M], R[M], mam[M];
PII A[M];

PII get(int i)
{
	add[i]++;
	int aa, bb;
	printf("+ %d\n", i);
	fflush(stdout);
	scanf("%d%d", &aa, &bb);
	PII r = MP(aa - a, bb - b);
	a = aa;
	b = bb;
	debug(i, r);
	if (r.f > 0)
	{
		R[i] = ile[r.f * 2] + 1 - add[i];
		mam[i] = 1;
		debug(i, R[i], aa);
	}
	A[i] = r;
	return r;
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	FOR(i, 2, M - 1)
	{
		ile[i * (i - 1)] = i;
	}
	scanf("%d%d%d", &n, &a, &b);
	FOR(i, 2, n - 2)
	{
		get(i);
	}
	PII a2 = get(n);
	if (a2.s == 0)
	{
		R[n - 1] = 0;
		mam[n - 1] = 1;
	}
	PII a3 = get(n - 1);
	PII a4 = get(n);
	if (!mam[n - 1])
	{
		mam[n - 1] = 1;
		R[n - 1] = 1;
	}
	int tn2 = a4.s / (R[n - 1] + add[n - 1]);
	mam[n - 2] = 1;
	R[n - 2] = tn2 - add[n - 2];
	
	int tn3 = (a3.s - (R[n - 2] + add[n - 2]) * (R[n] + add[n] - 1)) / (R[n - 2] + add[n - 2]);
	mam[n - 3] = 1;
	R[n - 3] = tn3 - add[n - 3];
	
	FOR(i, 1, n)
	{
		debug(i, R[i], A[i], add[i]);
	}
	FORD(i, n - 2, 3)
	{
		int il = (A[i].s - R[i + 1] * R[i + 2] - R[i + 1] * (R[i - 1] + 1)) / (R[i - 1] + 1);
		R[i - 2] = il - add[i -   2];
	}
	printf("! ");
	FOR(i, 1, n)
	{
		printf("%d ", R[i]);
	}
	printf("\n");
	fflush(stdout);
}