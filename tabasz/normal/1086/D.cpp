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

int D[3][2 * M];
char C[M], X[100];

int n, q;
map<char, int> ma;

void add(int ind, int v, int x)
{
	v += M;
	D[ind][v] += x;
	while (v > 1)
	{
		v /= 2;
		D[ind][v] = D[ind][2 * v] + D[ind][2 * v + 1];
	}
}

int sum(int ind, int p, int k)
{
	if (p > k)
	{
		return 0;
	}
	p += M;
	k += M;
	int r = D[ind][p];
	if (p < k)
	{
		r += D[ind][k];
	}
	while (p / 2 != k / 2)
	{
		if (p % 2 == 0)
		{
			r += D[ind][p + 1];
		}
		p /= 2;
		if (k % 2 == 1)
		{
			r += D[ind][k - 1];
		}
		k /= 2;
	}
	return r;
}

int getF(int ind, int v)
{
	if (D[ind][v] == 0)
	{
		return M - 1;
	}
	if (v >= M)
	{
		return v - M;
	}
	if (D[ind][2 * v])
	{
		return getF(ind, 2 * v);
	}
	return getF(ind, 2 * v + 1);
}

int getL(int ind, int v)
{
	if (D[ind][v] == 0)
	{
		return 0;
	}
	if (v >= M)
	{
		return v - M;
	}
	if (D[ind][2 * v + 1])
	{
		return getL(ind, 2 * v + 1);
	}
	return getL(ind, 2 * v);
}

int getR()
{
	int res = D[0][1] + D[1][1] + D[2][1];
	
	FOR(i, 0, 2)
	{
		PII x = MP(getF((i + 1) % 3, 1), getF((i + 2) % 3, 1));
		PII y = MP(getL((i + 2) % 3, 1), getL((i + 1) % 3, 1));
		PII z = MP(max(x.f, y.f), min(x.s, y.s));
		res -= sum(i, x.f, x.s);
		res -= sum(i, y.f, y.s);
		res += sum(i, z.f, z.s);
	}
	return res;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d%s", &n, &q, C);
	ma['R'] = 0;
	ma['P'] = 1;
	ma['S'] = 2;
	
	FOR(i, 0, n - 1)
	{
		add(ma[C[i]], i + 1, 1);
	}
	
	printf("%d\n", getR());
	
	FOR(i, 1, q)
	{
		int a;
		scanf("%d%s", &a, X);
		add(ma[C[a - 1]], a, -1);
		add(ma[X[0]], a, 1);
		C[a - 1] = X[0];
		
		printf("%d\n", getR());
	}
	return 0;
}