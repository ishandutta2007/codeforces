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

int n, m, q;
int P[M], T[M], L[M], R[M], last[M];
int D[2 * M];
VPII V[M];

void add(int v, int w)
{
	debug(v, w);
	v += M;
	mini(D[v], w);
	while (v > 1)
	{
		v /= 2;
		D[v] = min(D[2 * v], D[2 * v + 1]);
	}
}

int minn(int p, int k)
{
	p += M;
	k += M;
	int r = min(D[p], D[k]);
	while (p / 2 != k / 2)
	{
		if (p % 2 == 0)
		{
			mini(r, D[p + 1]);
		}
		p /= 2;
		if (k % 2 == 1)
		{
			mini(r, D[k - 1]);
		}
		k /= 2;
	}
	return r;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d%d", &n, &m, &q);
	FOR(i, 1, 2 * M - 1)
	{
		D[i] = M;
	}
	FOR(i, 1, n)
	{
		int a;
		scanf("%d", &a);
		P[a] = i;
		last[i] = -1;
	}
	FOR(i, 1, m)
	{
		int a;
		scanf("%d", &a);
		T[i] = P[a];
		L[i] = -1;
		R[i] = m + 1;
		
	}
	FOR(i, 1, m)
	{
		if (T[i] == 1)
		{
			L[i] = i;
		}
		else
		{
			if (last[T[i] - 1] != -1)
			{
				L[i] = L[last[T[i] - 1]];
			}
		}
		last[T[i]] = i;
	}
	FOR(i, 1, n)
	{
		last[i] = -1;
	}
	FORD(i, m, 1)
	{
		if (T[i] == n)
		{
			R[i] = i;
		}
		else
		{
			if (last[T[i] + 1] != -1)
			{
				R[i] = R[last[T[i] + 1]];
			}
		}
		last[T[i]] = i;
	}
	FOR(i, 1, m)
	{
		V[T[i]].PB(MP(L[i], i));
	}
	FOR(i, 1, m)
	{
		debug(i, L[i], R[i]);
	}
	FOR(i, 1, m)
	{
		if (T[i] == 1)
		{
			add(i, R[i]);
		}
		else
		{
			int want = T[i] - 1;
			VPII::iterator it = lower_bound(ALL(V[want]), MP(R[i] + 1, -1));
			if (it == V[want].end())
			{
				add(i, m + 1);
			}
			else
			{
				debug(i, T[i], want, *it);
				add(i, (*it).s);
			}
		}
	}
	FOR(i, 1, q)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		//debug(i, l, r, minn(l, r));
		if (minn(l, r) <= r)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
	return 0;
}