#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int low=(-1);
    int up=n;
    int k;
    map <int,int> r;
    int d;
    int v=0;
    for(int i=0;i<n;++i)
    {
        cin>>d;
        a[i]=d;
        if(r.count(d)==1)
        {
            if(r[d]==1)
            {
                ++v;
            }
            ++r[d];
        }
        else
        {
            r[d]=1;
        }
    }
    bool y;
    int l=1e9;
    y=false;
    int u;
    if(v==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
    u=(n-i-1);
    for(int j=0;j<(n-i);++j)
            {
                if(r[a[i+j]]==2)
                {
                    v--;
                }
                r[a[i+j]]--;
            if(v==0)
            {
                l=min(l,j+1);
                u=j;
                break;
            }
            }
    for(int j=i;j<(i+u+1);++j)
            {
                d=a[j];
                if(r.count(d)==1)
                {
                    if(r[d]==1)
                    {
                         ++v;
                    }
                    ++r[d];
                }
                else
                {
                   r[d]=1;
                }
            }
        }
        cout<<l;
        return 0;
    return 0;
}