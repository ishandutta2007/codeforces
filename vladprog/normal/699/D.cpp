#include <bits/stdc++.h>

using namespace std;

int n,r,k;
vector<int> a,u;

void dfs(int v)
{
    if(a[v]==v)return;
    switch(u[v])
    {
    case 0:
        u[v]=1;
        dfs(a[v]);
        u[v]=2;
        break;
    case 1:
        if(r==0)r=v;
        a[v]=r;
        k++;
        break;
    }
}

int main()
{
    scanf("%d",&n);
    a.resize(n+1);
    u.resize(n+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(a[i]==i)
            if(r==0)
                r=i;
            else
                a[i]=r,k++;
    for(int i=1;i<=n;i++)
        dfs(i);
    printf("%d\n",k);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
}