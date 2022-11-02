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

int n, m;

VI V[M];

int go(VI X)
{
	debug(X);
	VI A;
	FOR(i, 1, SIZ(X) - 1)
	{
		A.PB(X[i] - X[i - 1]);
	}
	A.PB(X[0] + n - X.back());

	debug(A);
	VI P;
	P.PB(0);
	FOR(i, 1, SIZ(A) - 1)
	{
		int tmp = P[i - 1];
		while (tmp != 0 && A[tmp] != A[i])
		{
			tmp = P[tmp - 1];
		}
		if (A[tmp] == A[i])
		{
			tmp++;
		}
		P.PB(tmp);
	}

	debug(P);
	if (P.back() != 0 && SIZ(P) % (SIZ(P) - P.back()) == 0)
	{
		int sum = 0;
		FOR(i, 0, SIZ(P) - P.back() - 1)
		{
			sum += A[i];
		}
		debug(sum);
		return sum;
	}
	else
	{
		return -1;
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &m);
	FOR(i, 1, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a < b)
		{
			swap(a, b);
		}
		int l = min(a - b, n - (a - b));
		
		V[l].PB(a);
		V[l].PB(b);
	}
	LL res = 1;
	FOR(i, 1, n)
	{
		sort(ALL(V[i]));
		if (V[i].empty())
		{
			continue;
		}
		debug(i);
		LL x = go(V[i]);
		if (x == -1)
		{
			printf("No\n");
			return 0;
		}
		LL gc = __gcd(res, x);
		res = res * x / gc;
		if (res >= n)
		{
			printf("No\n");
			return 0;
		}
	}
	debug(res);
	printf("Yes\n");
	return 0;
}