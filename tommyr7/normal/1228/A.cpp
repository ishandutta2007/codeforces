#include <bits/stdc++.h>
using namespace std;
int l,r;
bool vis[27];
bool check(int x)
{
    for (int i=0;i<10;i++)
        vis[i]=false;
    while (x>0)
    {
        if (vis[x%10]) return false;
        vis[x%10]=true;
        x/=10;
    }
    return true;
}
int main()
{
    scanf("%d%d",&l,&r);
    for (int i=l;i<=r;i++)
        if (check(i))
        {
            printf("%d\n",i);
            return 0;
        }
    printf("%d\n",-1);
    return 0;
}