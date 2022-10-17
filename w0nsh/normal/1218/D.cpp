#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector < LL > VLL;
typedef double D;

const int MN = 100005, inf = 1000000005, p2 = (1 << 17), C = 50;
const LL INF = 1000000000000000005LL;

int mod;

LL rev;

void trans(vector<LL> & P, bool r) {
	int N = p2;
    for (int len = 1; 2 * len <= N; len <<= 1) {
        for (int i = 0; i < N; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                LL u = P[i + j];
                LL v = P[i + len + j];
                P[i + j] = (u + v);
                P[i + len + j] = (u - v);
            }
        }
    }
    for (int i = 0; i < N; i++)
		P[i] = ((P[i] % mod) + mod) % mod;
    if (r) {
        for (int i = 0; i < N; i++)
            P[i] = (P[i] * rev) % mod;
    }
}

LL pot(LL a, LL b)
{
	if(b == 0LL)
		return 1LL;
	LL ret = pot(a, (b >> 1));
	ret = (ret * ret) % mod;
	if(b & 1LL)
		ret = (ret * a) % mod;
	return ret;
}

int ileCyc;

VLL cyc[2][C];

int used[MN];

vector < int > S, G[MN];
map < PII, int> waga;

void dfs(int x, int par)
{
	used[x] = 1;
	S.pb(x);
	for(auto v : G[x])
		if(!used[v])
		{
			dfs(v, x);
		}
		else if(used[v] == 1 && v != par)
		{
			//printf("dupsko\n");
			++ileCyc;
			cyc[0][ileCyc].resize(p2, 0);
			cyc[1][ileCyc].resize(p2, 0);
			int s = S.size() - 1, cur = v;
			while(1)
			{
				//printf("%d %d\n", ileCyc, waga[{S[s], cur}]);
				cyc[0][ileCyc][waga[{S[s], cur}]]++;
				cyc[1][ileCyc][waga[{S[s], cur}]]++;
				cur = S[s];
				--s;
				if(cur == v)
					break;
			}
		}
	S.pop_back();
	used[x] = 2;
}

void licz(int idx)
{
	cyc[idx][0].resize(p2, 0);
	cyc[idx][0][0] = 1LL;
	/*for(auto v : cyc[idx][0])
		printf("%lld ", v);
	printf("\n");*/
	for(int i = 1; i <= ileCyc; ++i)
	{
		/*for(auto v : cyc[idx][i])
			printf("%lld ", v);
		printf("\n");*/
		trans(cyc[idx][i - 1], 0);
		trans(cyc[idx][i], 0);
		for(int j = 0; j < p2; ++j)
		{
			cyc[idx][i][j] *= cyc[idx][i - 1][j];
			cyc[idx][i][j] %= mod;
		}
		trans(cyc[idx][i], 1);
		/*for(auto v : cyc[idx][i])
			printf("%lld ", v);
		printf("\n");*/
	}
}


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if(n == 1)
	{
		printf("0 1");
		return 0;
	}
	int ans = 0;
	for(int i = 1; i <= m; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].pb(v);
		G[v].pb(u);
		waga[{u, v}] = waga[{v, u}] = w;
		ans ^= w;
	}
	dfs(1, 0);
	mod = (int)1e9 + 7;
	rev = pot(p2, mod - 2);
	//printf("%lld\n", rev);
	licz(0);
	mod = 999999929;
	rev = pot(p2, mod - 2);
	licz(1);
	int odp = inf, ileOdp = 0;
	for(int i = 0; i < p2; ++i)
	{
		if(cyc[1][ileCyc][i] == 0)
			continue;
		int cans = i ^ ans;
		if(cans < odp)
		{
			odp = cans;
			ileOdp = cyc[0][ileCyc][i];
		}
	}
	printf("%d %d", odp, ileOdp);
}