#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int n;
int a[Maxn],b[Maxn];
map<int,bool> mp;
int gcd(int x,int y)
{
    if (x==0) return y;
    if (y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int x=a[1];
    for (int i=2;i<=n;i++)
        x=gcd(x,a[i]);
    if (x!=1)
    {
        printf("%d\n",-1);
        return 0;
    }
    sort(a+1,a+n+1);
    int m=1;
    b[1]=a[1];
    mp[a[1]]=true;
    for (int i=2;i<=n;i++)
    {
        bool check=true;
        for (int j=1;j*j<=a[i];j++)
            if (a[i]%j==0&&(mp[j]||mp[a[i]/j])) check=false;
        if (check)
        {
            b[++m]=a[i];
            mp[a[i]]=true;
        }
    }
    n=m;
    for (int i=1;i<=n;i++)
        a[i]=b[i];
    for (int i=1;i<=6;i++)
        for (int j=1;j<=300000;j++)
        {
            int now=0;
            for (int k=1;k<=i;k++)
                now=gcd(now,a[rand()%n+1]);
            if (now==1)
            {
                printf("%d\n",i);
                return 0;
            }
        }
    printf("%d\n",7);
    return 0;
}