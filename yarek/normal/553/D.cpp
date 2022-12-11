#include <cstdio>
#include <vector>
using namespace std;

vector<int> g[100001];
int x[100001];
bool given[100001];
double ratio;
int n;
vector<int> fort;

void giveUp(int v)
{
    given[v] = true;
    for(int u: g[v])
    {
	if(given[u]) continue;
	if(++x[u] / (double)g[u].size() > ratio)
	    giveUp(u);
    }
}

bool check(double d)
{
    ratio = d;
    for(int i = 1; i <= n; i++)
    {
	x[i] = 0;
	given[i] = false;
    }
    for(int v: fort)
	if(!given[v])
	    giveUp(v);
    for(int i = 1; i <= n; i++)
	if(!given[i]) return true;
    return false;
}

int main()
{
    int m, k;
    scanf("%d %d %d", &n, &m, &k);
    while(k--)
    {
	int a;
	scanf("%d", &a);
	fort.push_back(a);
    }
    while(m--)
    {
	int a, b;
	scanf("%d %d", &a, &b);
	g[a].push_back(b);
	g[b].push_back(a);
    }
    double a = 0, b = 1;
    for(int i = 0; i < 40; i++)
    {
	double c = (a + b) / 2;
	if(check(c)) b = c;
	else a = c;
    }
    check(b);
    k = 0;
    for(int i = 1; i <= n; i++)
	if(!given[i]) k++;
    printf("%d\n", k);
    for(int i = 1; i <= n; i++)
	if(!given[i]) printf("%d ", i);
    puts("");
}