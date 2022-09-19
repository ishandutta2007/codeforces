#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if((a[i]+i)%2==0)
        {
            sum1+=a[i]/2;
            sum2+=a[i]-a[i]/2;
        }
        else
        {
            sum2+=a[i]/2;
            sum1+=a[i]-a[i]/2;
        }
    }
    cout<<min(sum1,sum2)<<endl;
    return 0;
}