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
#define PB push_back
#define pb pop_back
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
const int M = 1024 * 256;

struct coss
{
	int hp, ind, co, n;
};

int n, m;
vector<coss> V;

bool cmp(coss a, coss b)
{
	return a.ind < b.ind;
}

pair<int, VI> check(int a, int l, int pier)
{
	vector<coss> X;
	for (auto x : V)
	{
		if (x.ind < a)
		{
			if (l)
			{
				X.PB(x);
			}
			continue;
		}
		if (x.ind > a)
		{
			if (!l)
			{
				x.ind = n - x.ind + 1;
				X.PB(x);
			}
			continue;
		}
		if (pier)
		{
			if (l)
			{
				X.PB(x);
			}
			else
			{
				x.ind = n - x.ind + 1;
				X.PB(x);
			}
		}
	}
	
	int lol = 0;
	for (auto x : X)
	{
		if (x.co != 0)
		{
			lol++;
		}
	}
	
	if (pier && lol == 0)
	{
		return MP(0, VI());
	}
	
	sort(ALL(X), cmp);
	
	vector<int> V1, V2;
	int pre = -1, hp = 0;
	for (auto x : X)
	{
		if (x.co == 0)
		{
			if (pre == -1)
			{
				continue;
			}
			hp += x.hp;
			if (hp < 0)
			{
				return MP(0, vector<int>());
			}
		}
		else
		{
			if (pre == -1)
			{
				pre = x.n;
				hp = x.hp;
				continue;
			}
			if (x.hp > hp)
			{
				V1.PB(pre);
				pre = x.n;
				hp = x.hp;
			}
			else
			{
				V2.PB(x.n);
			}
		}
	}
	if (pre != -1)
	{
		V1.PB(pre);
	}
	vector<int> VV;
	while (!V1.empty())
	{
		VV.PB(V1.back());
		V1.pb();
	}
	while (!V2.empty())
	{
		VV.PB(V2.back());
		V2.pb();
	}
	return MP(1, VV);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		coss x;
		scanf("%d%d", &x.ind, &x.hp);
		x.co = 1;
		x.n = i + 1;
		V.PB(x);
	}
	for (int i = 1; i <= n; i++)
	{
		coss x;
		scanf("%d", &x.hp);
		x.co = 0;
		x.n = 0;
		if (x.hp == 0)
		{
			continue;
		}
		x.ind = i;
		V.PB(x);
	}
	for (int i = 1; i <= n; i++)
	{
		pair<int, VI> x1 = check(i, 1, 1);
		pair<int, VI> x2 = check(i, 0, 0);
		
		if (x1.f && x2.f)
		{
			printf("%d\n", i);
			for (auto x : x1.s)
			{
				printf("%d ", x);
			}
			for (auto x : x2.s)
			{
				printf("%d ", x);
			}
			printf("\n");
			return 0;
		}
		
		x1 = check(i, 0, 1);
		x2 = check(i, 1, 0);
		
		if (x1.f && x2.f)
		{
			printf("%d\n", i);
			for (auto x : x1.s)
			{
				printf("%d ", x);
			}
			for (auto x : x2.s)
			{
				printf("%d ", x);
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}