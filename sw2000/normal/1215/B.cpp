#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int arr[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    arr[0]=1;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a<0)
        {
            arr[i]=arr[i-1]*(-1);
        }
        else arr[i]=arr[i-1];
    }
    int po=1,ne=0;
    ll ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==-1)
        {
            ans1+=ne;
            ans2+=po;
            ne++;
        }
        else
        {
            ans1+=po;
            ans2+=ne;
            po++;
        }
    }
    cout<<ans2<<' '<<ans1;
    return 0;
}