#include <cstdio>
#include <queue>
#include <set>
using namespace std;

set<int> s[300000];
int ans[300000];
bool vis[300000];
int nr[500000];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    priority_queue<pair<int, int> > pq;
    for(int i = 0; i <= 2 * m; i++)
	nr[i] = -1;
    for(int i = 0; i < n; i++)
    {
	int k, x;
	scanf("%d", &k);
	while(k--)
	{
	    scanf("%d", &x);
	    nr[x+m] = i;
	    s[i].insert(x);
	}
	pq.push(make_pair(-s[i].size(), i));
    }
    while(!pq.empty())
    {
	int k = pq.top().second;
	pq.pop();
	if(vis[k]) continue;
	vis[k] = true;
	if(s[k].empty())
	{
	    puts("NO");
	    return 0;
	}
	int x = *s[k].begin();
	if(x > 0) ans[x] = 1;
	if(nr[m-x] != -1)
	{
	    s[nr[m-x]].erase(-x);
	    pq.push(make_pair(-s[nr[m-x]].size(), nr[m-x]));
	}
    }
    puts("YES");
    for(int i = 1; i <= m; i++)
	printf("%d", ans[i]);
    puts("");
}