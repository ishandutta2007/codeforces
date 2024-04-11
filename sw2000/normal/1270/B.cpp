#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;
int n,arr[maxn];

void solve()
{
    int mi=2*inf,ma=-inf;
    int miid,maid;
    for(int i=1;i<=n;i++)
    {
        mi++;
        ma--;
        if(arr[i]<mi)
        {
            mi=arr[i];
            miid=i;
        }
        if(arr[i]>ma)
        {
            ma=arr[i];
            maid=i;
        }

        if(arr[i]>mi)
        {
            puts("YES");
            printf("%d %d\n",miid,i);
            return;
        }
        if(arr[i]<ma)
        {
            puts("YES");
            printf("%d %d\n",maid,i);
            return;
        }
    }
    puts("NO");
    return;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",arr+i);
        solve();
    }
    return 0;
}