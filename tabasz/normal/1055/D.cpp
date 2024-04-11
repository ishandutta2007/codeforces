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
const int M = 3005;

char C[2][M][M], W[M], W2[M];
PII X[M];
int n, L[M], doo[M], first[M], P[2 * M];
vector<int> ind;

void kmp()
{
	int l = strlen(W);
	FOR(i, 1, n)
	{
		string x = string(W) + "#" + string(C[0][i]);
		P[0] = 0;
		FOR(j, 1, SIZ(x) - 1)
		{
			int tmp = P[j - 1];
			while (tmp > 0 && x[j] != x[tmp])
			{
				tmp = P[tmp - 1];
			}
			if (x[j] == x[tmp])
			{
				tmp++;
			}
			P[j] = tmp;
			if (j > l && tmp == l)
			{
				first[i] = j - l - 1;
				break;
			}
		}
	}
}

bool cmp(int x, int y)
{
	if (X[x].s - X[x].f != X[y].s - X[y].f)
	{
		return false;
	}
	//debug(x, X[x], y, X[y]);
	FOR(i, 0, X[x].s - X[x].f)
	{
		//debug(i, C[0][x][i + X[x].f], C[0][y][X[y].f]);
		if (C[0][x][i + X[x].f] != C[0][y][i + X[y].f])
		{
			return false;
		}
		if (C[1][x][i + X[x].f] != C[1][y][i + X[y].f])
		{
			return false;
		}
	}
	return true;
}

int main() 
{
	bool lol = false;
	scanf("%d", &n);
	FOR(i, 0, 1)
	{
		FOR(j, 1, n)
		{
			scanf("%s", C[i][j]);
			L[j] = strlen(C[i][j]);
		}
	}
	FOR(i, 1, n)
	{
		first[i] = -1;
		vector<int> V;
		FOR(j, 0, L[i] - 1)
		{
			if (C[0][i][j] != C[1][i][j])
			{
				V.PB(j);
			}
		}
		if (!V.empty())
		{
			doo[i] = true;
			lol = true;
			ind.PB(i);
			X[i] = MP(V[0], V.back());
		}
	}
	if (!lol)
	{
		printf("YES\n");
		FOR(i, 1, 4000)
		{
			printf("a");
		}
		printf("\n");
		return 0;
	}
	int pr = -1;
	for (auto i : ind)
	{
		if (pr != -1)
		{
			if (!cmp(pr, i))
			{
				printf("NO\n");
				return 0;
			}
		}
		pr = i;
	}
	
	while (true)
	{
		bool boo = true;
		int pr = -1;
		for (auto i : ind)
		{
			if (X[i].f == 0)
			{
				boo = false;
				break;
			}
			if (pr != -1)
			{
				if (C[0][pr][X[pr].f - 1] != C[0][i][X[i].f - 1])
				{
					boo = false;
					break;
				}
			}
			pr = i;
		}
		if (boo)
		{
			for (auto i : ind)
			{
				X[i].f--;
			}
		}
		else
		{
			break;
		}
	}
	
	while (true)
	{
		bool boo = true;
		int pr = -1;
		for (auto i : ind)
		{
			if (X[i].s == L[i] - 1)
			{
				boo = false;
				break;
			}
			if (pr != -1)
			{
				if (C[0][pr][X[pr].s + 1] != C[0][i][X[i].s + 1])
				{
					boo = false;
					break;
				}
			}
			pr = i;
		}
		if (boo)
		{
			for (auto i : ind)
			{
				X[i].s++;
			}
		}
		else
		{
			break;
		}
	}
	
	int tmp = 0;
	FOR(i, X[ind[0]].f, X[ind[0]].s)
	{
		W[tmp] = C[0][ind[0]][i];
		W2[tmp] = C[1][ind[0]][i];
		tmp++;
	}
	kmp();
	
	FOR(i, 1, n)
	{
		if (!doo[i] && first[i] != -1)
		{
			printf("NO\n");
			return 0;
		}
		if (doo[i] && first[i] != X[i].s)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	printf("%s\n%s\n", W, W2);
	return 0;
}