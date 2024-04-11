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
const int inf = 1e9;

int n, m;
PII D[10][2 * M];

void addt(int i, int v, int x)
{
	v += M;
	D[i][v] = MP(x, v - M);
	while (v > 1)
	{
		v /= 2;
		D[i][v] = min(D[i][2 * v], D[i][2 * v + 1]);
	}
}

void add(int ind, int x)
{
	int xx = x;
	FOR(i, 0, 9)
	{
		if (x % 10 != 0)
		{
			addt(i, ind, xx);
		}
		else
		{
			addt(i, ind, inf);
		}
		x /= 10;
	}
}

PII minn(int i, int l, int r)
{
	if (l > r)
	{
		return MP(inf, 0);
	}
	l += M;
	r += M;
	PII res = min(D[i][l], D[i][r]);
	while (l / 2 != r / 2)
	{
		if (l % 2 == 0)
		{
			mini(res, D[i][l + 1]);
		}
		l /= 2;
		if (r % 2 == 1)
		{
			mini(res, D[i][r - 1]);
		}
		r /= 2;
	}
	return res;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &m);
	FOR(i, 0, 9)
	{
		FOR(j, 0, 2 * M - 1)
		{
			D[i][j] = MP(inf, 0);
		}
	}
	FOR(i, 1, n)
	{
		int a;
		scanf("%d", &a);
		add(i, a);
	}
	FOR(i, 1, m)
	{
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if (t == 1)
		{
			add(a, b);
		}
		else
		{
			int sum = inf * 2;
			FOR(i, 0, 9)
			{
				PII x = minn(i, a, b);
				if (x.f != inf)
				{
					PII y = min(minn(i, a, x.s - 1), minn(i, x.s + 1, b));
					if (y.f != inf)
					{
						mini(sum, y.f + x.f);
					}
				}
			}
			if (sum == 2 * inf)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", sum);
			}
		}
	}
	return 0;
}