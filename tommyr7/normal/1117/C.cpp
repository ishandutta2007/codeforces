#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,a,b,x,y;
int s1[Maxn],s2[Maxn];
bool tryit(long long k)
{
    long long nowx=-x+(1LL*s1[n]*(k/n))+s1[((int)(k%n)+n)%n];
    long long nowy=-y+(1LL*s2[n]*(k/n))+s2[((int)(k%n)+n)%n];
    if (abs(nowx)+abs(nowy)>k) return false;
    return true;
}
int main()
{
    scanf("%d%d",&a,&b);
    scanf("%d%d",&x,&y);
    x-=a,y-=b;
    s1[0]=0,s2[0]=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        while (ch<'A'||ch>'Z') ch=getchar();
        s1[i]=s1[i-1],s2[i]=s2[i-1];
        if (ch=='U') ++s2[i];
        if (ch=='D') --s2[i];
        if (ch=='L') --s1[i];
        if (ch=='R') ++s1[i];
    }
    long long lx=0,rx=1000000000000000000LL;
    if (!tryit(rx))
    {
        printf("%d\n",-1);
        return 0;
    }
    while (rx-lx>1)
    {
        long long mid=(lx+rx)/2;
        if (tryit(mid)) rx=mid; else lx=mid;
    }
    if (tryit(lx)) printf("%lld\n",lx); else printf("%lld\n",rx);
    return 0;
}