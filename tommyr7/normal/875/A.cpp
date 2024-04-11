#include <bits/stdc++.h>
using namespace std;
int x,ans=0;
int anss[307];
int check(int x)
{
    int res=x;
    while (x>0)
    {
        res+=(x%10);
        x/=10;
    }
    return res;
}
int main()
{
    scanf("%d",&x);
    for (int i=max(x-300,0);i<=x;i++)
        if (check(i)==x) anss[++ans]=i;
    printf("%d\n",ans);
    for (int i=1;i<=ans;i++)
        printf("%d\n",anss[i]);
}