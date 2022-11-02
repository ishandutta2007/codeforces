#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
ll a[200005],b[200005],c[200005];
int main()
{
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    for(int i=0;i<=n;i++)
        scanf("%I64d",&a[i]);
    int tot_b=n;
    for(int i=0;i<=n;i++)
        b[i]=a[i];
    for(int i=0;i<n;i++)
        if(b[i]%2==0)
        {
            b[i+1]+=b[i]/2;
        }
        else
        {
            tot_b=i;
            break;
        }
    int tot_c=0;
    for(int i=0;i<=n;i++)
        c[i]=a[i];
    for(int i=n;i>0;i--)
        if(abs(c[i])<INF)
        {
            c[i-1]+=c[i]*2;
        }
        else
        {
            tot_c=i;
            break;
        }
    int cnt=0;
    for(int i=tot_c;i<=tot_b;i++)
    {
        if(abs(b[i]+c[i]-2*a[i])<=k)cnt++;
        if(i==n && b[i]+c[i]-2*a[i]==0)cnt--;
    }
    printf("%d\n",cnt);
    return 0;
}