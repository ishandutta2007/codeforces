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
const int M = 11;

PII dp[M][1<<M];
int T[1024 * 256], n, nn;
queue<int> Q;
vector<vector<int>> R;

int getMask(int l, int ind)
{
	int x = 0;
	for (int i = 0; i < l; i++)
	{
		x = (x * 2) + T[i + ind];
	}
	return x;
}

void add(int a, int b, int c)
{
	T[a] = 1 - T[a];
	T[b] = 1 - T[b];
	T[c] = 1 - T[c];
	R.PB(VI{a + 1, b + 1, c + 1});
}

void add2(int l, int x, int off)
{
	vector<int> V;
	for (int i = 0; i < M; i++)
	{
		if ((x>>i) % 2 == 1)
		{
			V.PB(l - i + off);
		}
	}
	R.PB(V);
}

void build(int l, int x, int off)
{
	while (x != 0)
	{
		//debug(l, x, off);
		add2(l, dp[l][x].s, off);
		x ^= dp[l][x].s;
	}
}

int main() 
{
	for (int i = 3; i <= 10; i++)
	{
		int tmp = 0;
		for (int j = 0; j < (1<<M); j++)
		{
			dp[i][j] = MP(-1, -1);
			dp[i][0] = MP(0, 0);
		}
		while (!Q.empty())
		{
			Q.pop();
		}
		Q.push(0);
		while (!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			for (int j = 0; j < i; j++)
			{
				for (int k = 1; j + 2 * k < i; k++)
				{
					int m = (1<<j) ^ (1<<(j + k)) ^ (1<<(j + 2 * k));
					int xx = x ^ m;
					if (dp[i][xx].f == -1)
					{
						dp[i][xx] = MP(dp[i][x].f + 1, m);
						tmp = max(tmp, dp[i][xx].f);
						Q.push(xx);
					}
				}
			}
		}
	//	debug(tmp);
	}
	scanf("%d", &n);
	nn = n;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", T + i);
		if (n < M)
		{
			x = (x * 2) + T[i];
		}
	}
	if (n < M)
	{
		if (dp[n][x].f == -1)
		{
			printf("NO\n");
			return 0;
		}
		build(n, x, 0);
	}
	else
	{
		int p = 0;
		while (n >= M)
		{
			if (T[p] == 0)
			{
				p++;
				n--;
				continue;
			}
			if (T[p + n - 1] == 0)
			{
				n--;
				continue;
			}
			if (T[p] == 1 && T[p + 1] == 1 && T[p + 2] == 1)
			{
				add(p, p + 1, p + 2);
				n -= 3;
				p += 3;
				continue;
			}
			if (T[p] == 1 && T[p + 1] == 0 && T[p + 2] == 0)
			{
				add(p, p + 3, p + 6);
				n -= 3;
				p += 3;
				continue;
			}
			if (T[p] == 1 && T[p + 2] == 1 && T[p + 1] == 0)
			{
				add(p, p + 2, p + 4);
				n -= 3;
				p += 3;
				continue;
			}
			if (T[p + n - 1] == 1 && T[p + n - 2] == 1 && T[p + n - 3] == 1)
			{
				add(p + n - 1, p + n - 2, p + n - 3);
				n -= 3;
				continue;
			}
			if (T[p + n - 1] == 1 && T[p + n - 2] == 0 && T[p + n - 3] == 0)
			{
				add(p + n - 1, p + n - 4, p + n - 7);
				n -= 3;
				continue;
			}
			if (T[p + n - 1] == 1 && T[p + n - 3] == 1 && T[p + n - 2] == 0)
			{
				add(p + n - 1, p + n - 3, p + n - 5);
				n -= 3;
				continue;
			}
			//debug(p, n);
			if ((p + p + n) % 2 == 1)
			{
				add(p, (p + p + n) / 2, p + n - 1);
				add(p + 1, (p + p + n) / 2, p + n - 2);
			}
			else
			{
				add(p, (p + p + n) / 2 - 1, p + n - 2);
				add(p + 1, (p + p + n) / 2, p + n - 1);
			}
			p += 3;
			n -= 6;
		}
		bool dasie = false;
		for (int i = 0; i < M; i++)
		{
			if (i > p)
			{
				continue;
			}
			if (-i + M - 1 < n)
			{
				continue;
			}
			if (p - i + M - 1 > nn)
			{
				continue;
			}
			int mask = getMask(M - 1, p - i);
			if (dp[M - 1][mask].f != -1)
			{
				//debug(p, n, i, p - i);
				dasie = true;
				build(M - 1, mask, p - i);
				break;
			}
		}
		if (!dasie)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n%d\n", SIZ(R));
	for (auto x : R)
	{
		printf("%d %d %d\n", x[0], x[1], x[2]);
	}
	return 0;
}