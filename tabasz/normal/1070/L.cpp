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

const int N = 2002;
bitset<N> B[N];

int n;

int deg[N];

VI G[N];

void pisz()
	{
	REP(i, n)
		{
		REP(j, n+1)
			printf("%d", (int)B[i][j]);
		puts("");
		}
	puts("");
	}

VI gauss()
	{
	#ifdef DEB
	pisz();
	#endif
//	bitset<N> x;
//	VPII zam;
	REP(i, n)
		{
		int k = i;
		if(B[i][i] == 0)
			FOR(j, i+1, n-1)
				{
				if(B[j][i] != 0){k = j;break;}
				}
		if(B[k][i] == 0)
			{
//			assert(false);
			continue;
			}
		swap(B[i], B[k]);
//		zam.PB(MP(i, k));
		
		FOR(j, i+1, n-1)
			{
			if(B[j][i])B[j] ^= B[i];
			}
		}
	#ifdef DEB
	pisz();
	#endif
	
	FORD(i, n-1, 0)
		{
		if(B[i][i] == 0)continue;
		FORD(j, i-1, 0)
			{
			if(B[j][i])B[j] ^= B[i];
			}
		}
		
	#ifdef DEB
	pisz();
	#endif
		
//	FORD(i, (int)zam.size()-1, 0){		swap(B[V[i].f], B[V[i].s]);		}
	VI ans;
	REP(i, n)
		ans.PB(B[i][n]);
	return ans;
	}
	
bool verify(VI ans)
{
	for(int i = 0; i < n; ++i)
	{
		int curr = 0;
		
		for(auto it:G[i])
		{
			if(ans[it]==ans[i])
				curr ^= 1;
		}
		
		if(curr)
			return 0;
	}
	
	return 1;
}
int R(int a, int b){return rand() %(b-a+1)+a;}
void solve()
	{
	
	set<PII> S;
	
	int m;
	n = R(1, 6);
	m = R(1, 8);
	mini(m, n*(n-1)/2);	
	//m = rand()%(n*(n-1)/2);

	
	scanf("%d%d", &n, &m);
	
	REP(i, n)B[i].reset();
	for(int i = 0; i < n; ++i)
		{
		G[i].clear();
		deg[i] = 0;
		}
	REP(i, m)
		{
		int a, b;
		
		a = rand()%n+1;
		b = rand()%n+1;
		
		while(a>=b || S.count(mp(a, b)))
		{
			a = rand()%n+1;
			b = rand()%n+1;
		}
		
		S.insert(mp(a, b));
		
		
		scanf("%d%d", &a, &b);
		
		a--;
		b--;
		++deg[a];
		++deg[b];
		G[a].pb(b);
		G[b].pb(a);
		}
		
		
	bool ok = 1;
	REP(i, n)
		{
		if(deg[i] % 2 != 0)
			ok = 0;
		}
	
	if(ok)
		{
		puts("1");
		REP(i, n)printf("1 ");
		puts("");
		return;
		}
		
	for(int i = 0; i < n; ++i)
	{
		if(deg[i]%2==0)
		{
			for(int j = 0; j < G[i].size(); ++j)
			{
				B[i][G[i][j]] = 1;
			}
		}
		else
		{
			for(int j = 0; j < G[i].size(); ++j)
			{
				B[i][G[i][j]] = 1;
			}
			
			B[i][i] = 1;
			B[i][n] = 1;
		}	
	}
	
	VI ans = gauss();
	
	if(!verify(ans))
	{
		debug(I(n), I(m));
		cout << "zle" << endl;
		
		for(int i = 0; i < n; ++i)
		{
			for(auto it:G[i])
			{
				if(i < it)
				cerr << i + 1 << " " << it + 1<< endl;
			}
		}
		
//		while(1);
	}
	
	puts("2");
	for(auto i : ans)printf("%d ", i+1);
	puts("");
	
	}
	
int main()
{
	int z;
	scanf("%d", &z);
	while(z--)
		{
		solve();
		}
}