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
const int M = 55;

int n, dt;
int T[M][M], vis[M][M];
PII pos;
int x1[] = {-2, -1, 0};
int y11[] = {0, -1, -2};
int x2[] = {0, 1, 2};
int y2[] = {2, 1, 0};


int ask(PII a, PII b)
{
	printf("? %d %d %d %d\n", a.f, a.s, b.f, b.s);
	fflush(stdout);
	int qwe;
	scanf("%d", &qwe);
	return qwe;
}

int getcol(PII x)
{
	if (T[x.f + 2][x.s] != T[x.f + 1][x.s + 1])
	{
		pos = MP(x.f + 2, x.s + 1);
		return ask(x, MP(x.f + 2, x.s + 1));
	}
	if (ask(x, MP(x.f + 2, x.s + 1)))
	{
		pos = MP(x.f + 2, x.s + 1);
		return 1;
	}
	if (ask(MP(x.f + 1, x.s), MP(x.f + 2, x.s + 2)))
	{
		pos = MP(x.f + 1, x.s);
		return 0;
	}
	
	if (T[x.f + 1][x.s + 1] == 1)
	{
		pos = MP(x.f + 2, x.s + 1);
		return 0;
	}
	else
	{
		pos = MP(x.f + 1, x.s);
		return 1;
	}
	
}

void dfs(PII v)
{
	FOR(i, 0, 2)
	{
		PII vv = MP(v.f + x1[i], v.s + y11[i]);
		if (vv.f >= 1 && vv.f <= n && vv.s >= 1 && vv.s <= n && !vis[vv.f][vv.s])
		{
			vis[vv.f][vv.s] = 1;
			T[vv.f][vv.s] = T[v.f][v.s] ^ (1 - ask(vv, v));
			dfs(vv);
		}
	}
	FOR(i, 0, 2)
	{
		PII vv = MP(v.f + x2[i], v.s + y2[i]);
		if (vv.f >= 1 && vv.f <= n && vv.s >= 1 && vv.s <= n && !vis[vv.f][vv.s])
		{
			vis[vv.f][vv.s] = 1;
			T[vv.f][vv.s] = T[v.f][v.s] ^ (1 - ask(v, vv));
			dfs(vv);
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	T[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		int j = 1;
		if ((i + j) % 2 == 1)
		{
			j++;
		}
		while (j <= n)
		{
			if (i == 1 && j == 1)
			{
				j += 2;
				continue;
			}
			if (i == n && j == n)
			{
				j += 2;
				continue;
			}
			PII prev = MP(i, j - 2);
			if (j == 1)
			{
				prev = MP(i - 2, j);
			}
			else if (j == 2)
			{
				prev = MP(i - 1, j - 1);
			}
			debug("lolol", i, j);
			int x = ask(prev, MP(i, j));
			if (x)
			{
				T[i][j] = T[prev.f][prev.s];
			}
			else
			{
				T[i][j] = 1 - T[prev.f][prev.s];
			}
			
			j += 2;
		}
	}
	PII par = MP(1, 1);
	
	while (T[par.f + 2][par.s + 2] == 1)
	{
		par.f += 2;
		par.s += 2;
	}
	int col = getcol(par);
	
	T[pos.f][pos.s] = col;
	dfs(pos);
	vis[pos.f][pos.s] = 1;
	
	printf("!\n");
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			printf("%d", T[i][j]);
		}
		printf("\n");
	}
	fflush(stdout);
	return 0;
}