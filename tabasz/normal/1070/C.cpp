#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
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
#define ll long long
#define st first
#define nd second
#define pb push_back
#define eb emplace_back
#define mp make_pair
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define Sim template<class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.st << ", " << x.nd << ">";}
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

const int BASE = 1<<20;
int ile[BASE*2];
LL sum[BASE*2];
#define VPII vector<PII>

VPII pom[BASE];
void insert(int x, LL cores)
	{
	sum[x+BASE] += cores * x;
	ile[x+BASE] += cores;
	x += BASE;
	x/=2;
	while(x)
		{
		sum[x] = sum[x*2] + sum[x*2+1];
		ile[x] = ile[x*2] + ile[x*2+1];
		x/=2;
		}
	}
LL query(int i, int k)
	{
	i += BASE;
	LL ss = 0, il = 0;
	while(i > 1)
		{
		ss += sum[i+1];
		il += ile[i+1];
		if(il >= k)
			{
			i++;
			break;
			}
		i /= 2;
		}
	if(i == 1 && ile[1] < k)
		{
		return ss;
		}
	while(i < BASE)
		{
		if(il - ile[i*2+1] < k)
			{
			i = i * 2+ 1;
			}
		else
			{
			il -= ile[i*2+1];
			ss -= sum[i*2+1];
			i *= 2;
			}
		}
	debug(ss, il, ile[i], sum[i], i-BASE);
		
	return ss + (k-il) * (i-BASE);
	}



int main()
	{
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);

	REP(i, m)
		{
		int a, b, c, p;
		scanf("%d%d%d%d", &a, &b, &c, &p);
		pom[a].PB(MP(p, c));
		pom[b+1].PB(MP(p, -c));	
		}
	LL res = 0;
	FOR(i, 1, n)
		{
		for(auto j : pom[i])
			{
			insert(j.f, j.s);
			}	
		
		LL x = query(0, k);	
		res += x;
		debug(i, x);
		}
	printf("%lld\n", res);
	}