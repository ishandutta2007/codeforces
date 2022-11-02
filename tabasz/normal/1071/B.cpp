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
const int M = 1024 * 2;

int n, k;
char C[M][M];
int dp[M][M];
int pos[M][M];
vector<PII> V;

bool cmp(PII x, PII y)
{
	if (C[x.f][x.s] == C[y.f][y.s])
	{
		return min(pos[x.f + 1][x.s], pos[x.f][x.s + 1]) < min(pos[y.f + 1][y.s], pos[y.f][y.s + 1]);
	}
	return C[x.f][x.s] < C[y.f][y.s];
}

int main() 
{
	scanf("%d%d\n", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", C[i] + 1);
	}
	int len = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			pos[i][j] = M * M;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = i + j - 2;
			if (i > 1)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			if (j > 1)
			{
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			}
			if (C[i][j] != 'a')
			{
				dp[i][j]++;
			}
			//debug(i, j, dp[i][j]);
			if (dp[i][j] <= k)
			{
				if (i + j - 1 > len)
				{
					V.clear();
					V.PB(MP(i, j));
					len = i + j - 1;
				}
				else if (i + j - 1 == len)
				{
					V.PB(MP(i, j));
				}
			}
		}
	}
	debug(len);
	for (auto x : V)
	{
		//debug(x);
		C[x.f][x.s] = 'a';
	}
	for (int i = 2 * n - 1; i >= max(len, 2); i--)
	{
		vector<PII> X;
		debug(i);
		for (int j = 1; j <= min(i - 1, n); j++)
		{
			if (i - j <= n)
			{
				X.PB(MP(j, i - j));
				debug(j, i - j);
			}
		}
		sort(ALL(X), cmp);
		for (int j = 0; j < SIZ(X); j++)
		{
			pos[X[j].f][X[j].s] = j;
		}
	}

	int pre = 0;
	for (int i = 1; i < SIZ(V); i++)
	{
		if (pos[V[i].f][V[i].s] < pos[V[pre].f][V[pre].s])
		{
			pre = i;
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("a");
	}
	PII x;
	if (SIZ(V) > 0)
	{
		x = V[pre];
	}
	else
	{
		printf("%c", C[1][1]);
		x = MP(1, 1);
	}
	while (x != MP(n, n))
	{
		if (x.f == n)
		{
			x.s++;
		}
		else
		{
			if (x.s == n || pos[x.f + 1][x.s] < pos[x.f][x.s + 1])
			{
				x.f++;
			}
			else
			{
				x.s++;
			}
		}
		printf("%c", C[x.f][x.s]);
	}
	printf("\n");
	return 0;
}