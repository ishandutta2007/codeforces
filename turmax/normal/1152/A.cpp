#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int k;
    int sum1=0,sum2=0,sum3=0,sum4=0;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        if(k%2==0)
        {
            sum1++;
        }
        else
        {
            sum2++;
        }
    }
    for(int i=0;i<m;++i)
    {
        cin>>k;
        if(k%2==0)
        {
            sum3++;
        }
        else
        {
            sum4++;
        }
    }
    cout<<min(sum1,sum4)+min(sum2,sum3);
    return 0;
}