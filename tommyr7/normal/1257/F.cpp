#include <bits/stdc++.h>
using namespace std;
#define modp1 998244353
#define Maxn 107
int a[Maxn],n;
int now[Maxn];
int cnt[1000007],p;
map<pair<int,int>,int>mp;
int main()
{
    srand(time(0));
    mp.clear();
    int modp2=(rand()<<16|rand())%(1000000009-998244353)+998244353;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    cnt[0]=0;
    for (int i=1;i<(1<<15);i++)
    {
        cnt[i]=cnt[i/2];
        if (i%2==1) ++cnt[i];
    }
    for (int i=(1<<15)-1;i>=0;i--)
    {
        for (int j=1;j<=n;j++)
            now[j]=cnt[(a[j]&((1<<15)-1))^i];
        for (int j=n;j;j--)
            now[j]=(now[j]-now[j-1]+67)%67;
        int h1=0,h2=0;
        for (int j=2;j<=n;j++)
        {
            h1=(67LL*h1+now[j])%modp1;
            h2=(67LL*h2+now[j])%modp2;
        }
        mp[make_pair(h1,h2)]=i;
    }
    for (int i=1;i<=n;i++)
        a[i]>>=15;
    for (int i=0;i<(1<<15);i++)
    {
        for (int j=1;j<=n;j++)
            now[j]=cnt[a[j]^i];
        for (int j=n;j;j--)
            now[j]=(now[j]-now[j-1]+67)%67;
        for (int j=2;j<=n;j++)
            now[j]=(67-now[j])%67;
        int h1=0,h2=0;
        for (int j=2;j<=n;j++)
        {
            h1=(67LL*h1+now[j])%modp1;
            h2=(67LL*h2+now[j])%modp2;
        }
        if (mp.find(make_pair(h1,h2))!=mp.end())
        {
            int tmp=mp[make_pair(h1,h2)];
            printf("%d\n",tmp+(1<<15)*i);
            return 0;
        }
    }
    printf("%d\n",-1);
    return 0;
}