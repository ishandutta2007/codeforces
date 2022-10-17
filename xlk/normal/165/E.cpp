#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int n;
int f[6005000],a[1001000];

int dfs(int x)
{
    if(f[x]) return f[x];
    for(int i=0;i<22;i++)
        if(x&(1<<i))
        {
            int res=dfs(x-(1<<i));
            if(res!=-1) return f[x]=res;
        }
    return f[x]=-1;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        f[a[i]]=a[i];
    }
    f[0]=-1;
    for(int i=1;i<=n;i++)
        printf("%d ",dfs((((1<<22)-1)^a[i])));
    return 0;
}