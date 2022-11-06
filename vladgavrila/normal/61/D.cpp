#include <cstdio>
#include <vector>

using namespace std;

#define maxn 100010

int n, m, f[maxn], t[maxn], d[maxn];
vector<int> v[maxn], w[maxn];
long long sol;

void df(int nod)
{
    f[nod]=1;
    int fiu;

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu]==1)
            continue;
        df(fiu);

        d[nod]=max(d[nod], d[fiu]+w[nod][i]);
    }
}


int main()
{
 //   freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);

    int a, b, c;
    for(int i=1; i<n; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        v[a].push_back(b);
        v[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
        sol=sol+c*2;
    }

    df(1);

    sol-=d[1];

    printf("%I64d\n", sol);

    return 0;
}