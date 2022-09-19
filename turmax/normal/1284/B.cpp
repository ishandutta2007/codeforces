#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a;
    vector <int> b;
    int k;
    int pr;
    int x;
    vector <bool> h;
    bool z;
    bool d;
    int h1;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        pr=1e18;
        z=true;
        d=false;
        for(int j=0;j<k;++j)
        {
            cin>>x;
            if(j==0)
            {
                h1=x;
            }
            if(j!=0 && x!=pr)
            {
                z=false;
            }
            if(x>pr)
            {
                if(!d)
                {
                d=true;
                }
            }
            pr=x;
        }
        if(!d)
        {
        a.push_back(pr);
        h.push_back(z);
        b.push_back(h1);
        }
    }
    int ans1=0;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();++i)
    {
        ans1+=(a.end()-lower_bound(a.begin(),a.end(),b[i]));
    }
    cout<<n*n-ans1;
    return 0;
}