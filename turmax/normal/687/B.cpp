#include <bits/stdc++.h>

using namespace std;
#define int long long
int gcd(int x,int y)
{
    if(x==0)
    {
        return y;
    }
    if(y==0)
    {
        return x;
    }
    if(x>=y)
    {
        return gcd(x%y,y);
    }
    else
    {
        return gcd(y%x,x);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector <int> a;
    int u;
    for(int i=0;i<n;++i)
    {
        cin>>u;
        a.push_back(u);
    }
    int r;
    int l;
    while(k!=1)
    {
        r=k;
        for(int i=0;i<a.size();++i)
        {
            l=gcd(a[i],k);
            if(l>1)
            {
                a.erase(a.begin()+i);
                k/=l;
                for(int j=0;j<a.size();++j)
                {
                    a[j]/=gcd(l,a[j]);
                }
                break;
            }
        }
        if(r==k)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}