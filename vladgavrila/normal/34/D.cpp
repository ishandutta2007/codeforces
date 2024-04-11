#include <stdio.h>
#include <vector>

using namespace std;

#define maxn 100010

int n, i, j, k, r1, r2;
int t[maxn], tn[maxn], f[maxn];
vector<int> v[maxn];

void df(int nod, int tata)
{
    if(f[nod]==1)
        return;
    f[nod]=1;
    tn[nod]=tata;
    for(int y=0; y<v[nod].size(); ++y)
        df(v[nod][y], nod);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &r1, &r2);
    for(int i=1; i<=n; ++i)
    {
        if(i!=r1)
        {
            scanf("%d", &t[i]);
            v[i].push_back(t[i]);
            v[t[i]].push_back(i);
        }
    }
    df(r2, 0);
    for(int i=1; i<=n; ++i)
    {
        if(i!=r2)
            printf("%d ", tn[i]);
    }
    printf("\n");
    return 0;
}