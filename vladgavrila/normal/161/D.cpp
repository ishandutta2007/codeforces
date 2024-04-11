#include <cstdio>
#include <vector>

using namespace std;

#define maxn 50010
#define maxd 510

int n, k, a, b;
int d[maxn][maxd], f[maxn];
vector<int> v[maxn];
long long sol;

void df(int nod)
{
    int fiu;
    f[nod]=1;
    d[nod][0]=1;   
    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu])
            continue;
        df(fiu);
        for(int j=1; j<=k; ++j)
            sol=sol+1LL*d[nod][k-j]*d[fiu][j-1];
        for(int j=1; j<=k; ++j)
            d[nod][j]+=d[fiu][j-1];
    }
}

int main()
{
 //   freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
    
    scanf("%d%d", &n, &k);
    for(int i=1; i<n; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    df(1);
    
    printf("%I64d\n", sol);
    return 0;
}