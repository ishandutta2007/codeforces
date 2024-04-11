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

#define VPII vector<PII>
struct MXFLOW
	{
	
	struct edge
		{
		int to, flow, id;	
		 edge(int _to, int _flow, int _id)
			{
			to = _to;
			flow = _flow;
			id = _id;
			}	
		};
	
	vector<edge> *V;
	int s, t, n;
	int FLOW;
	bool *odw;
	MXFLOW(int _n, int _s, int _t)
		{
		n = _n;
		s = _s;
		t = _t;
		V = new vector<edge>[n+1];
		odw = new bool[n+1];
		FLOW = 0;
		}
	void addedge(int a, int b, int f = 1)
		{
		debug(a, b, n);
		V[a].PB(edge(b, f, V[b].size()));
		V[b].PB(edge(a, 0, V[a].size()-1));
		}
	
	bool dfs(int x)
		{
		if(x == t)return 1;
		if(odw[x])return 0;
		odw[x] = 1;
		REP(i, V[x].size())
			{
			if(V[x][i].flow && dfs(V[x][i].to))
				{
				V[x][i].flow--;
				V[V[x][i].to][V[x][i].id].flow++;
				return 1;
				}
			}
		return 0;
		}
	void findflow()
		{
		while(1)
			{
			FOR(i, 0, n)odw[i] = 0;
			if(dfs(s) == 0)return;
			FLOW++;
			}
		}
	VPII edges(int m, int n)
		{
		VPII ans;
		FOR(i, 1, m)
			{
			for(auto j : V[i])
				{
				if(m + 1 <= j.to && j.to <= n+m && j.flow == 0)
					{
					ans.PB(MP(i, j.to));
					}
				
				}
			}
		return ans;
		}
	};



const int N = 1207;

int t, n, m, k;

int a[N];
int b[N];
int deg[N];
int ans[N];

VI moje[N];

void clear()
{
	memset(deg, 0, sizeof deg);
	memset(ans, 0, sizeof ans);
	
	for(int i = 1; i <= n; ++i)
	{
		moje[i].clear();
	}
}

void brak()
{
	for(int i = 1; i <= m; ++i)
	{
		cout << 0 << " ";
	}
	
	cout << endl;
}

void solve()
{
	cin >> n >> m >> k;
	
	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i];
		++deg[a[i]];
		++deg[b[i]];
	}
	
	for(int i = 1; i <= n; ++i)
	{
		if(deg[i]>2*k)
		{
			brak();
			clear();
			return;
		}	
	}
		
	MXFLOW flo(n+m+2, 0, n+m+1);
	
	for(int i =	1; i <= m; ++i)
	{
		flo.addedge(0, i);
		flo.addedge(i, a[i]+m);
		flo.addedge(i, b[i]+m);
	}
	
	int chce = 0;
	
	for(int i = 1; i <= n; ++i)
	{
		int x = deg[i]-k;
		
		if(x>0)
		{
			flo.addedge(i+m, n+m+1, 2*x); 
			chce += 2*x;
		}
	}
	
	flo.findflow();
	
	if(flo.FLOW!=chce)
	{
		brak();
		clear();
		return;
	}
	
	VPII match;
	
	match = flo.edges(m, n);
	
	for(auto it:match)
	{
		moje[it.nd-m].pb(it.st);
	}	
	
	int cnt = 0;
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j+1 < moje[i].size(); j += 2)
		{
			++cnt;
			ans[moje[i][j]] = cnt;
			ans[moje[i][j+1]] = cnt;
		}
	} 
	
	for(int i = 1; i <= m; ++i)
	{
		if(!ans[i])
			ans[i] = ++cnt;
	}
	
	for(int i = 1; i <= m; ++i)
	{
		cout << ans[i] << " ";
	}
	
	cout << endl;
	
	clear();
}

int main()
{
	cin >> t;
	
	while(t--)
		solve();
}