#include <bits/stdc++.h>

using namespace std;
#define int long long
int sn(int k)
{
    if(k>0)
    {
        return 1;
    }
    if(k<0)
    {
        return -1;
    }
    return 0;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector <int> u(n+1);
    u[0]=1;
    int k;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        u[i+1]=u[i]*sn(k);
    }
    int sum1=0;
    int sum2=0;
    for(int i=0;i<(n+1);++i)
    {
        if(u[i]==1)
        {
            ++sum1;
        }
        else
        {
            ++sum2;
        }
    }
    cout<<sum1*sum2<<" "<<(sum1*(sum1-1))/2+sum2*((sum2)-1)/2;
    return 0;
}