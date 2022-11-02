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
const int M = 1<<18;

int n, T[M];
int V[M], cnt[M];
LL res;

int find(int a)
{
	return T[a] == a ? a : T[a] = find(T[a]);
}

int32_t main()
{
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		int a;
		scanf("%d", &a);
		V[a] = i;
		cnt[a]++;
		T[i] = i;
		res -= a;
	}
	cnt[0]++;
	FORD(i, M - 1, 0)
	{
		for (int j = i; true; j = i&(j-1))
		{
			int k = j ^ i;
			if (cnt[k] && cnt[j] && find(V[j]) != find(V[k]))
			{
				T[find(V[j])] = find(V[k]);
				res += (LL)i * (cnt[j] + cnt[k] - 1);
				cnt[j] = 1;
				cnt[k] = 1;
			}
			if(j == 0)
			{
				break;
			}
		}
	}
	
	printf("%lld\n", res);
}