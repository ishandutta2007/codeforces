#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int a[n];
    int u[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]--;
        u[a[i]]=i;
    }
    int mi=0;
    int r=n;
    bool h=true;
    while(true)
    {
        if(mi==n)
        {
            break;
        }
        //cout<<mi<<" "<<r<<endl;
        int x=u[mi];
        int z=mi;
        while((x+1)<r)
        {
            if(a[x+1]==(a[x]+1))
            {
                ++x;
                ++mi;
            }
            else
            {
                cout<<"No"<<endl;
                h=false;
                break;
            }
        }
        if(!h)
        {
            break;
        }
        r=u[z];
        ++mi;
    }
    if(h)
    {
        cout<<"Yes"<<endl;
    }
    }
    return 0;
}