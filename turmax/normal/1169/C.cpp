#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> a;
int n;
int m;
int check(int k)
{
    int ma=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]<(ma-k))
        {
            return 0;
        }
        else if(a[i]>ma)
        {
            if((a[i]+k)<(ma+m))
            {
                ma=a[i];
            }
        }
    }
    return 1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int k;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        a.push_back(k);
    }
    int low=-1;
    int up=(m+1);
    while(true)
    {
        if((up-low)==1)
        {
            cout<<up;
            return 0;
        }
        else
        {
            k=(up+low)/2;
            if(check(k)==1)
            {
                up=k;
            }
            else
            {
                low=k;
            }
        }
    }
    return 0;
}