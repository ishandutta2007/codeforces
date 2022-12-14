#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;
int arr[maxn],brr[maxn],crr[maxn];
int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    for(scanf("%d",&t);t--;)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            scanf("%d",arr+i);
            crr[arr[i]]=i+1;
        }
        for(int i=0;i<m;i++)scanf("%d",brr+i);
        int ma=0;
        ll ans=0;
        for(int i=0;i<m;i++)
        {
            if(crr[brr[i]]<ma)ans++;
            else
            {
                ma=crr[brr[i]];
                ans+=ma*2-1-i*2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}