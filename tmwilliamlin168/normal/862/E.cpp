#include <iostream>
#include <set>
using namespace std;
int sign(int x)
{
    if (x%2)
    return -1;
    return 1;
}
long long absll(long long x)
{
    if (x>0)
    return x;
    return -x;
}
set<long long> s;
int b[100005];
long long ans(long long x)
{
    set<long long>::iterator it=s.lower_bound(x);
    if (it==s.end())
    it--;
    long long ret=absll((*it)-x);
    if (it!=s.begin())
    it--;
    return min(ret,absll((*it)-x));
}
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    long long sumA=0;
    for (int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        sumA+=a*sign(i);
    }
    long long cur=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        cur+=sign(i+1)*b[i];
    }
    s.insert(cur);
    for (int i=n;i<m;i++)
    {
        scanf("%d",&b[i]);
        cur+=b[i-n];
        cur=-cur;
        cur+=sign(n)*b[i];
        s.insert(cur);
    }
    printf("%I64d\n",ans(-sumA));
    while (q--)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        if ((r-l)%2==0)
        {
            if (l%2)
            sumA+=x;
            else
            sumA-=x;
        }
        printf("%I64d\n",ans(-sumA));
    }
}