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

int n, in[M];
VI V[M];
queue<int> Q;

int ask(int a, int b)
{
	printf("? %d %d\n", a, b);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

void res(int x)
{
	printf("! %d\n", x);
	fflush(stdout);
	exit(0);
}

void rem(int x)
{
	for (auto v : V[x])
	{
		in[v]--;
		if (in[v] == 1)
		{
			Q.push(v);
		}
	}
}

int32_t main()
{
	scanf("%d", &n);
	FOR(i, 2, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
		in[a]++;
		in[b]++;
	}
	FOR(i, 1, n)
	{
		if (in[i] == 1)
		{
			Q.push(i);
		}
	}
	while (SIZ(Q) > 1)
	{
		int a = Q.front();
		Q.pop();
		int b = Q.front();
		Q.pop();
		int c = ask(a, b);
		if (c == a)
		{
			res(a);
		}
		if (c == b)
		{
			res(b);
		}
		rem(a);
		rem(b);
	}
	assert(SIZ(Q) > 0);
	res(Q.front());
}