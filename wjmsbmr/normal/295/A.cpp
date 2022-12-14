#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100010
int n,m,p,a[N],pl[N],pr[N],pw[N];
ll s[N],ps[N];
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0;i<m;i++)scanf("%d%d%d",pl+i,pr+i,pw+i);
    for(int i=0,l,r;i<p;i++)
        scanf("%d%d",&l,&r),s[l-1]++,s[r]--;
    ll S=0;
    for(int i=0;i<m;i++)
    {
        S+=s[i];
        ps[pl[i]-1]+=S*pw[i],
        ps[pr[i]]-=S*pw[i];
    }
    S=0;
    for(int i=0;i<n;i++)
    {
        S+=ps[i];
        printf("%I64d%c",a[i]+S,i==n-1?'\n':' ');
    }
    return 0;
}