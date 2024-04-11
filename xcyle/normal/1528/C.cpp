#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 300005
using namespace std;
int T, n, a[maxn], b[maxn], t[maxn];
int dfn[maxn], dep[maxn], tot, siz[maxn];
int t2[maxn];
void add2(int x, int data)
{
	for (; x <= n; x += (x & (-x))) t2[x] += data;
}
int que2(int x)
{
	if(x == 0) return 0;
	int res = 0;
	for (; x; x -= (x & (-x))) res += t[x];
	return res;
}
int ans;
vector<int> Ga[maxn], Gb[maxn];
void init(int x)
{
    dfn[x] = ++tot;
    siz[x] = 1;
    for (int i = 0; i < Gb[x].size(); i++)
    {
        int V = Gb[x][i];
        dep[V] = dep[x] + 1;
        init(V); 
        siz[x] += siz[V];
    }
}
int type[maxn];
inline void add(int x, int d)
{
    for (int p = dfn[x]; p <= n; p += (p & (-p))) t[p] += d * x;
    for (int p = dfn[x] + siz[x]; p <= n; p += (p & (-p))) t[p] -= d * x;
}
inline int que(int x)
{
    int res = 0;
    for (; x; x -= (x & (-x))) res += t[x];
    return res;
}
void work(int x, int res)
{
    if(que2(dfn[x] + siz[x] - 1) > que2(dfn[x]))
    {
        for (int i = 0; i < Ga[x].size(); i++)
        {
            int V = Ga[x][i];
            work(V, res);
        }
        return;
    }
	add2(dfn[x], 1);
    res++;
    int tmp = que(dfn[x]);
    if(tmp)
    {
//        printf("%d %d\n", x, tmp);
        add(tmp, -1);
        res--;
    }
//    printf("! %d %d\n", x, res);
    add(x, 1);
    for (int i = 0; i < Ga[x].size(); i++) work(Ga[x][i], res);
    add(x, -1);
    if(tmp) add(tmp, 1);
    ans = max(ans, res);
    add2(dfn[x], -1);
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            Ga[i].clear(), Gb[i].clear();
        }
        for (int i = 2; i <= n; i++)
        {
            scanf("%d", &a[i]);
            Ga[a[i]].push_back(i);
        }
        for (int i = 2; i <= n; i++)
        {
            scanf("%d", &b[i]);
            Gb[b[i]].push_back(i);
        }
        dep[1] = 1;
        tot = 0;
        init(1);
        for (int i = 1; i <= n; i++) t[i] = t2[i] = type[i] = 0;  
        work(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}