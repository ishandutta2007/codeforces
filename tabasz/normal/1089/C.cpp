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

const int MXN = 505;
int odl[MXN][MXN];
VI sas[MXN];
VI jakie[MXN][MXN];
int cnt[MXN][MXN];

int n, m;

int where(VI V)
	{
	for(auto v : V)
		{
		for(auto v2 : V)
			{
			for(auto ii : jakie[v][v2])
				{
				cnt[v][ii]++;
				}	
			}
		}
	
	PII best = MP(2e9, 0);
	for(auto v : V)
		{
		int mx = 0;
		for(auto i : V)
			{
			maxi(mx, cnt[v][i]);
			}
		mini(best, MP(mx, v));
		}
		
	
	for(auto v : V)
		{
		for(auto v2 : V)
			{
			for(auto ii : jakie[v][v2])
				{
				cnt[v][ii] = 0;
				}	
			}
		}
		
		
//	debug(I(best));
	return best.s;
	}


void go()
	{
	VI V;
	FOR(i, 1, n)
		V.PB(i);
	
	while(1)
		{
		int x = where(V);
		
		cout << x << endl;
		string s;
		cin >> s;
		if(s == "FOUND")break;
		int w;
		cin >> w;
		
		VI V2;
		for(auto res : V)
			{
			if(odl[x][res] == odl[w][res]+1)V2.PB(res);
			}
//		debug(I(V.size()), I(V2.size()));
		V = V2;
		}
	
	
	}

int main()
{
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
		{
		FOR(j, 1, n)
			odl[i][j] = 1e9;
		odl[i][i] = 0;
		}
	FOR(i, 1, m)
		{
		int k;
		scanf("%d", &k);

		int pp = -1;
		FOR(j, 1, k)
			{
			int a;
			scanf("%d", &a);
			if(pp != -1)
				{
				sas[pp].PB(a);
				sas[a].PB(pp);
				odl[pp][a] = odl[a][pp] = 1;
				}
			pp = a;
			}
		}

	FOR(i, 1, n)
		FOR(j, 1, n)
			FOR(u, 1, n)
				mini(odl[j][u], odl[j][i] + odl[i][u]);

	FOR(i, 1, n)
		FOR(j, 1, n)
			FOR(u, 1, n)
				if(odl[i][u] == 1 && odl[i][j] == odl[u][j] + 1)
					jakie[i][j].PB(u);


	FOR(i, 1, n)
		{
		go();
		}
}