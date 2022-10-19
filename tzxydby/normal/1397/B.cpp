#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,a[N],ans=1e18;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;;i++)
    {
        int p=1,s=0;
        for(int j=1;j<=n;j++)
        {
            s+=abs(a[j]-p);
            if(p>=1e16/i)
            {
                cout<<ans<<endl;
                return 0;
            }
            p*=i;
        }
        if(s>ans&&p>a[n])
        {
            cout<<ans<<endl;
            return 0;
        }
        ans=min(ans,s);
    }
    return 0;
}