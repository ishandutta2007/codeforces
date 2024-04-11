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

int n, m, q;
PII D[2 * M];
int A[M], B[M];

void pchaj(int v)
{
	D[2 * v].f += D[v].f;
	D[2 * v + 1].f += D[v].f;
	D[v].f = 0;
}

void popraw(int v)
{
	D[v].s = max(D[2 * v].f + D[2 * v].s, D[2 * v + 1].f + D[2 * v + 1].s);
}

void add(int v, int vp, int vk, int p, int k, int x)
{
	if (vp > k || vk < p)
	{
		return;
	}
	if (vp >= p && vk <= k)
	{
		D[v].f += x;
		return;
	}
	pchaj(v);
	int mid = (vp + vk) / 2;
	
	add(2 * v, vp, mid, p, k, x);
	add(2 * v + 1, mid + 1, vk, p, k, x);
	popraw(v);
}

int query(int v, int x)
{
	//debug(v, x, D[v]);
	if (v >= M)
	{
		return v - M;
	}
	x -= D[v].f;
	//debug(D[2 * v + 1].f, D[2 * v + 1].s);
	if (D[2 * v + 1].f + D[2 * v + 1].s > x)
	{
		return query(2 * v + 1, x);
	}
	return query(2 * v, x);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	{
		int a;
		scanf("%d", &a);
		A[i] = a;
		add(1, 0, M - 1, 0, A[i], 1);
	}
	FOR(i, 1, m)
	{
		int a;
		scanf("%d", &a);
		B[i] = a;
		add(1, 0, M - 1, 0, B[i], -1);
	}
	add(1, 0, M - 1, 0, 0, M);
	scanf("%d", &q);
	FOR(i, 1, q)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		
		if (a == 1)
		{
			add(1, 0, M - 1, 0, A[b], -1);
			A[b] = c;
			add(1, 0, M - 1, 0, A[b], 1);
		}
		else
		{
			add(1, 0, M - 1, 0, B[b], 1);
			B[b] = c;
			add(1, 0, M - 1, 0, B[b], -1);
		}
		//debug(D[1]);
		int ind = query(1, 0);
		if (ind == 0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", ind);
		}
	}
	return 0;
}