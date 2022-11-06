#include <cstdio>
#include <vector>

using namespace std;

#define maxn 200010

int n, m, nod, mc, fiu, q0;
int f[maxn], a[maxn], b[maxn], fl[maxn], o[maxn], q[maxn];
vector<int> v[maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d%d", &a[i], &b[i], &fl[i]);

        f[a[i]]+=fl[i];
        f[b[i]]+=fl[i];

        v[a[i]].push_back(i);
        v[b[i]].push_back(i);
    }

    q0=1;
    q[q0]=1;

    for(int i=1; i<=q0; ++i)
    {
        nod=q[i];
        for(int j=0; j<v[nod].size(); ++j)
        {
            mc=v[nod][j];
            if(o[mc]!=0)
                continue;

            fiu=a[mc];
            o[mc]=1;
            if(fiu==nod)
            {
                o[mc]=2;
                fiu=b[mc];
            }

            f[fiu]-=2*fl[mc];

            if(f[fiu]==0 && fiu!=n)
                q[++q0]=fiu;
        }
    }

    for(int i=1; i<=m; ++i)
        printf("%d\n", 2-o[i]);

    return 0;
}