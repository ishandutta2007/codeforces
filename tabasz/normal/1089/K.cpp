#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
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
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

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

#define int LL

const int BASE = 1 << 20;
struct seg
	{
	int wolne;
	int wystaje;
	seg(int a, int b) : wolne(a), wystaje(b) {}
	seg() {}
	};
seg t[BASE*2];

seg merge(seg a, seg b)
	{
	int wolnez2 = b.wolne - a.wystaje;
	
	int wolne = a.wolne + max(wolnez2, 0LL);
	int wystaje = b.wystaje + max(0LL, -wolnez2);

	return seg(wolne, wystaje);
	}
void calc(int i)
	{
	i += BASE;
	i /= 2;
	while(i)
		{
		t[i] = merge(t[i*2], t[i*2+1]);
		i /= 2;
		}
	}
int timeq[BASE];

seg query(int a, int b)
	{
	a += BASE-1;
	b += BASE+1;
	seg resa(0, 0), resb(0, 0);
	while(a/2!= b/2)
		{
		if(a % 2 == 0)resa = merge(resa, t[a+1]);
		if(b % 2 == 1)resb = merge(t[b-1], resb);
		a /= 2;
		b /= 2;
		} 
	
//	debug(resa.wolne, resa.wystaje, resb.wolne, resb.wystaje);
		
	return merge(resa, resb);
	}


int32_t main()
{
	int q;
	scanf("%lld", &q);
	
	FOR(i, 0, BASE-1)
		{
		t[i+BASE] = seg(1, 0);
		calc(i);
		}
	
	REP(ii, q)
		{
		char c;
		scanf(" %c", &c);
		if(c == '+')
			{
			int i, d;
			scanf("%lld%lld", &i, &d);
			t[BASE+i] = seg(0, d-1);
			calc(i);

			timeq[ii+1] = i;
			}
		if(c == '-')
			{
			int id;
			scanf("%lld", &id);
			int i = timeq[id];
			t[BASE+i] = seg(1, 0);
			calc(i);
			}
		if(c == '?')
			{
			int i;
			scanf("%lld", &i);
			
			auto x = query(1, i-1);
//			debug(x.wolne, x.wystaje);
			
			x.wystaje += (t[i+BASE].wolne == 0) + t[i+BASE].wystaje;
			
			printf("%lld\n", x.wystaje);
			}
		}
}