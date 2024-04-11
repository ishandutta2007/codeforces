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

int H[M], mex[M];
int n, m, out[M], xo[M], xo2[M];
VI V[M], T[M];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	{
		scanf("%d", H + i);
	}
	FOR(i, 1, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		T[b].PB(a);
		out[a]++;
	}
	queue<int> Q;
	FOR(i, 1, n)
	{
		if (out[i] == 0)
		{
			Q.push(i);
		}
	}
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		VI X;
		for (auto x : V[v])
		{
			X.PB(mex[x]);
		}
		sort(ALL(X));
		X.resize(unique(ALL(X)) - X.begin());
		X.PB(1e9);
		FOR(i, 0, SIZ(X) - 1)
		{
			if (X[i] != i)
			{
				mex[v] = i;
				break;
			}
		}
		for (auto x : T[v])
		{
			out[x]--;
			if (out[x] == 0)
			{
				Q.push(x);
			}
		}
		xo[mex[v]] ^= H[v];
	}
	int t = -1;
	FOR(i, 0, n)
	{
		if (xo[i] != 0)
		{
			t = i;
		}
	}
	if (t == -1)
	{
		printf("LOSE\n");
		return 0;
	}
	printf("WIN\n");
	bool boo = false;
	FOR(i, 1, n)
	{
		if (mex[i] != t || (xo[t] ^ H[i]) >= H[i])
		{
			continue;
		}
		boo = true;
		H[i] = xo[t] ^ H[i];
		for (auto x : V[i])
		{
			if (xo[mex[x]] != 0)
			{
				H[x] = xo[mex[x]] ^ H[x];
				xo[mex[x]] = 0;
			}
		}
		break;
	}
	assert(boo);
	FOR(i, 1, n)
	{
		printf("%d ", H[i]);
		xo2[mex[i]] ^= H[i];
	}
	FOR(i, 0, n)
	{
		assert(xo2[i] == 0);
	}
	printf("\n");
	return 0;
}