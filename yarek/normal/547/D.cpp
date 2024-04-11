#include <cstdio>
#include <vector>
using namespace std;

vector<int> g[200001];
int col[200001];
int lx[200001];
int ly[200001];

void dfs(int v, int c = 1)
{
    col[v] = c;
    for(int u: g[v])
	if(col[u] == 0)
	    dfs(u, 3 - c);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
	int x, y;
	scanf("%d %d", &x, &y);
	if(lx[x] == 0) lx[x] = i;
	else
	{
	    g[i].push_back(lx[x]);
	    g[lx[x]].push_back(i);
	    lx[x] = 0;
	}
	if(ly[y] == 0) ly[y] = i;
	else
	{
	    g[i].push_back(ly[y]);
	    g[ly[y]].push_back(i);
	    ly[y] = 0;
	}
    }
    for(int i = 1; i <= n; i++)
    {
	if(col[i] == 0) dfs(i);
	putchar(col[i] == 1 ? 'r' : 'b');
    }
    puts("");
}