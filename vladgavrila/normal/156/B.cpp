#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define maxn 100010

int n, m, act, dt, ca;
int v[maxn], a[maxn], d[maxn];
set<int> pc;

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        if(v[i]>0)
        {
            ++act;
            ++a[v[i]];
        }
        else
        {
            ++dt;
            ++d[-v[i]];
        }
    }

    for(int i=1; i<=n; ++i)
    {
        ca=a[i]+dt-d[i];
        if(ca==m)
            pc.insert(i);
    }

    for(int i=1; i<=n; ++i)
    {
        if(v[i]>0)
        {
            if(pc.find(v[i])!=pc.end())
            {
                if(pc.size()==1)
                    printf("Truth\n");
                else
                    printf("Not defined\n");
            }
            else
                printf("Lie\n");
        }
        else
        {
            if(pc.find(-v[i])!=pc.end())
            {
                if(pc.size()==1)
                    printf("Lie\n");
                else
                    printf("Not defined\n");
            }
            else
                printf("Truth\n");
        }
    }

    return 0;
}