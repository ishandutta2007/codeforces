#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    vector <int> a;
    int n;
    cin>>n;
    int l=1e9;
    int sum1=0;
    int x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        a.push_back(x);
        sum1+=x;
    }
    int sum2=0;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        a.push_back(x);
        sum2+=x;
    }
    int s;
    if(sum1!=sum2)
    {
        for(int i=0;i<2*n;++i)
        {
            cout<<a[i]<<" ";
        }
        return 0;
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(a[i]!=a[n+j])
                {
                    s=a[n+j];
                    a[n+j]=a[i];
                    a[i]=s;
                for(int i=0;i<2*n;++i)
                {
                      cout<<a[i]<<" ";
                }
                return 0;
                }
            }
        }
        cout<<(-1);
        return 0;
    }
    return 0;
}