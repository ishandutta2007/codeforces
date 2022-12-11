#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100001, LOGN = 17, K = 11;
int tab[LOGN][N][K];
int par[LOGN][N];
vector<int> g[N];
vector<int> people[N];
int in[N];
int out[N];

void dfs(int v, int prev)
{
    static int time;
    par[0][v] = prev;
    in[v] = time++;
    for(int u: g[v])
	if(u != prev) dfs(u, v);
    out[v] = time++;
}

bool ancestor(int a, int b)
{
    return in[a] <= in[b] && out[a] >= out[b];
}

vector<int*> seg(int a, int b)
{
    int pa = a;
    vector<int*> ans;
    for(int i = LOGN - 1; i >= 0; i--)
	if(!ancestor(par[i][a], b))
	{
// 	    printf("%d %d\n", i, a);
	    ans.push_back(tab[i][a]);
	    a = par[i][a];
	}
    if(!ancestor(a, b))
    {
// 	printf("%d %d\n", 0, a);
	ans.push_back(tab[0][a]);
    }
    a = b;
    b = pa;
    for(int i = LOGN - 1; i >= 0; i--)
	if(!ancestor(par[i][a], b))
	{
// 	    printf("%d %d\n", i, a);
	    ans.push_back(tab[i][a]);
	    a = par[i][a];
	}
    if(!ancestor(a, b))
    {
// 	printf("%d %d\n", 0, a);
	ans.push_back(tab[0][a]);
	a = par[0][a];
    }
    ans.push_back(tab[0][a]);
    return ans;
}

int tmp[2*K];

int main()
{
    int n, m, q;
    const int inf = 10000000;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i < n; i++)
    {
	int a, b;
	scanf("%d %d", &a, &b);
	g[a].push_back(b);
	g[b].push_back(a);
    }
    in[0] = -1;
    out[0] = inf;
    dfs(1, 0);
    for(int i = 0; i <= n; i++)
	for(int j = 0; j < K; j++)
	    tab[0][i][j] = inf;
    for(int i = 1; i <= m; i++)
    {
	int c;
	scanf("%d", &c);
	for(int j = 0; j < K; j++)
	    if(tab[0][c][j] == inf)
	    {
		tab[0][c][j] = i;
		break;
	    }
    }
    for(int i = 1; i < LOGN; i++)
	for(int j = 0; j <= n; j++)
	{
	    merge(tab[i-1][j], tab[i-1][j] + K, tab[i-1][par[i-1][j]], tab[i-1][par[i-1][j]] + K, tmp);
	    copy(tmp, tmp + K, tab[i][j]);
	    par[i][j] = par[i-1][par[i-1][j]];
// 	    printf("par[%d][%d] = %d\n", i, j, par[i][j]);
	}
    /*for(int i = 0; i < 3; i++)
	for(int j = 1; j <= n; j++)
	{
	    printf("%d %d: ", i, j);
	    for(int k = 0; k < K; k++)
		printf("%d ", tab[i][j][k]);
	    puts("");
	}*/
    while(q--)
    {
	int v, u, a;
	scanf("%d %d %d", &v, &u, &a);
	auto s = seg(v, u);
	priority_queue<pair<int, int*>> q;
	for(auto x: s)
	    q.push(make_pair(-(*x), x));
	vector<int> ans;
	while(!q.empty() && ans.size() < a)
	{
	    int *t = q.top().second;
	    q.pop();
	    if(*t == inf) break;
	    ans.push_back(*t);
	    t++;
	    q.push(make_pair(-(*t), t));
	}
	printf("%d ", ans.size());
	for(int x: ans)
	    printf("%d ", x);
	puts("");
    }
}