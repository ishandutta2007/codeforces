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
const int M = 1024 * 512;

int n, przes;
int T[2][M], R[2][M], A[M];
PII D[2][2 * M];//f add, s maxi
int D2[2][2 * M];

void pchaj(int ind, int v)
{
	D[ind][2 * v].f += D[ind][v].f;
	D[ind][2 * v + 1].f += D[ind][v].f;
	D[ind][v].f = 0;
}

void popraw(int ind, int v)
{
	D[ind][v].s = max(D[ind][2 * v].f + D[ind][2 * v].s, D[ind][2 * v + 1].f + D[ind][2 * v + 1].s);
}

void add(int ind, int v, int vp, int vk, int l, int r, int s)
{
	if (l > r)
	{
		return;
	}
	if (r < vp || l > vk)
	{
		return;
	}
	if (vp >= l && vk <= r)
	{
		D[ind][v].f += s;
		return;
	}
	int mid = (vp + vk) / 2;
	pchaj(ind, v);
	add(ind, 2 * v, vp, mid, l, r, s);
	add(ind, 2 * v + 1, mid + 1, vk, l, r, s);
	popraw(ind, v);
}

int get(int ind, int v)
{
	v += M;
	int r = D[ind][v].f + D[ind][v].s;
	while (v > 1)
	{
		v /= 2;
		r += D[ind][v].f;
	}
	return r;
}

void add2(int ind, int v, int val)
{
	v += M;
	D2[ind][v] = val;
	while (v > 1)
	{
		v /= 2;
		D2[ind][v] = min(D2[ind][2 * v], D2[ind][2 * v + 1]);
	}
}

int getsmaller(int ind, int v, int x)
{
	if (v >= M)
	{
		return v - M;
	}
	if (D2[ind][2 * v + 1] < x)
	{
		return getsmaller(ind, 2 * v + 1, x);
	}
	return getsmaller(ind, 2 * v, x);
}

void solve(int ind)
{
	add2(ind, 0, 0);
	add2(ind, 1, T[ind][1]);
	add(ind, 1, 0, M - 1, 1, 1, 1);
	R[ind][1] = 1;
	FOR(i, 2, n - 1)
	{
		int pos = getsmaller(ind, 1, T[ind][i]);
		debug("          ", i, T[ind][i], pos);
		
		add(ind, 1, 0, M - 1, pos + 1, i - 1, 1);
		add(ind, 1, 0, M - 1, i, i, get(ind, pos) + 1);
		debug("add2  ", i, T[ind][i]);
		add2(ind, i, T[ind][i]);
		R[ind][i] = D[ind][1].f + D[ind][1].s;
		debug(I(i), I(pos), T[ind][i], R[ind][i]);
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		scanf("%d", A + i);
		if (A[i] == 1)
		{
			przes = i - 1;
		}
	}
	if (n == 1)
	{
		printf("1 0\n");
		return 0;
	}
	FOR(i, 1, n)
	{
		if (i + przes <= n)
		{
			T[0][i - 1] = A[i + przes];
		}
		else
		{
			T[0][i - 1] = A[i + przes - n];
		}
	}
	T[1][0] = 1;
	FOR(i, 1, n - 1)
	{
		T[1][i] = T[0][n - i];
	}
	FOR(i, 0, 1)
	{
		FOR(j, 0, 2 * M - 1)
		{
			D2[i][j] = M;
		}
		solve(i);
	}
	int best = R[0][n - 1], ind = 0;
	FOR(i, 1, n - 1)
	{
		debug(i, R[0][i], R[1][n - 1 - i]);
		if (max(R[0][i], R[1][n - 1 - i]) < best)
		{
			best = max(R[0][i], R[1][n - 1 - i]);
			ind = i + 1;
		}
	}
	debug(przes, ind);
	printf("%d %d\n", best + 1, (przes + ind) % n);
	return 0;
}