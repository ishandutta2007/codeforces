#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[3],sum=0;
        for(int i=0;i<3;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a,a+3);
        if(a[0]+a[1]<=a[2])
        {
            printf("%d\n",a[0]+a[1]);
        }
        else
        {
            printf("%d\n",sum/2);
        }

    }
    return 0;
}