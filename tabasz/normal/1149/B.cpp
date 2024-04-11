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
const int M = 255;
const int inf = 1e9;

int dp[M][M][M];
int n, q, alf = 26, l[3];
int nxt[1024 * 128][30], last[30];
string s;
vector<char> C[3];
VI V[3];

void popraw(int ind)
{
	VI X[3];
	FOR(i, 0, 2)
	{
		if (i == ind)
		{
			X[i].PB(l[i] - 1);
			X[i].PB(l[i]);
		}
		else
		{
			FOR(j, 0, l[i])
			{
				X[i].PB(j);
			}
		}
	}
	for (auto x : X[0])
	{
		for (auto y : X[1])
		{
			for (auto z : X[2])
			{
				if (dp[x][y][z] == inf)
				{
					continue;
				}
				//debug(V[0], x);
				if (x < l[0] && nxt[dp[x][y][z]][V[0][x] - 'a'] <= n)
				{
					mini(dp[x + 1][y][z], nxt[dp[x][y][z]][V[0][x] - 'a']);
				}
				if (y < l[1] && nxt[dp[x][y][z]][V[1][y] - 'a'] <= n)
				{
					mini(dp[x][y + 1][z], nxt[dp[x][y][z]][V[1][y] - 'a']);
				}
				if (z < l[2] && nxt[dp[x][y][z]][V[2][z] - 'a'] <= n)
				{
					mini(dp[x][y][z + 1], nxt[dp[x][y][z]][V[2][z] - 'a']);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> q >> s;
	s = "#" + s;
	FOR(i, 0, 26)
	{
		last[i] = inf;
	}
	FORD(i, n, 0)
	{
		FOR(j, 0, 25)
		{
			nxt[i][j] = last[j];
		}
		if (i > 0)
		{
			last[s[i] - 'a'] = i;
		}
	}
	FOR(i, 0, M - 1)
	{
		FOR(j, 0, M - 1)
		{
			FOR(k, 0, M - 1)
			{
				dp[i][j][k] = inf;
			}
		}
	}
	dp[0][0][0] = 0;
	FOR(i, 1, q)
	{
		string a, b;
		int ind;
		cin >> a >> ind;
		//debug(a, ind, b);
		if (a[0] == '-')
		{
			if (ind == 1)
			{
				FOR(j, 0, l[1])
				{
					FOR(k, 0, l[2])
					{
						dp[l[0]][j][k] = inf;
					}
				}
			}
			else if (ind == 2)
			{
				FOR(j, 0, l[0])
				{
					FOR(k, 0, l[2])
					{
						dp[j][l[1]][k] = inf;
					}
				}
			}
			else
			{
				FOR(j, 0, l[0])
				{
					FOR(k, 0, l[1])
					{
						dp[j][k][l[2]] = inf;
					}
				}
			}
			V[ind - 1].pb();
			l[ind - 1]--;
		}
		else
		{
			cin >> b;
			V[ind - 1].PB(b[0]);
			l[ind - 1]++;
			popraw(ind - 1);
		}
		if (dp[l[0]][l[1]][l[2]] <= n)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}