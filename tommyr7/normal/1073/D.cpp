#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n;
long long T;
long long ans=0;
int a[Maxn];
void calc()
{
    long long sum=0,now=T;
    int x=0;
    for (int i=1;i<=n;i++)
        if (now>=a[i])
        {
            now-=a[i];
            sum+=a[i];
            ++x;
        }
    if (x==0)
    {
        T=0;
        return;
    }
    long long tmp=T/sum;
    ans+=1LL*tmp*x;
    T%=sum;
}
int main()
{
    scanf("%d%lld",&n,&T);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while (T>0) calc();
    printf("%lld\n",ans);
}