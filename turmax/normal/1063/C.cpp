#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin>>n;
    int po[41];
    int u=1;
    for(int i=0;i<41;++i)
    {
        po[i]=u;
        u*=2;
    }
    int low=5;
    int up=65*1e7;
    int k;
    int z=0;
    string s;
    bool h=true;
    while(true)
    {
        if((up-low)==1 && z==n)
        {
            cout<<0<<" "<<0<<" "<<2<<" "<<2*low+1<<endl;
            return 0;
        }
        if((up-low)==1)
        {
            cout<<2<<" "<<2*low+1<<endl;
            cin>>s;
            if((s=="black" && h)|| (s=="white" && !h))
            {
            cout<<0<<" "<<0<<" "<<3<<" "<<3*low+1<<endl;
            }
            else
            {
            cout<<0<<" "<<0<<" "<<3<<" "<<3*low+2<<endl;
            }
            return 0;
        }
        if(z==n)
        {
            k=(up+low)/2;
            cout<<0<<" "<<0<<" "<<1<<" "<<k<<endl;
            return 0;
        }
        k=(up+low)/2;
        cout<<1<<" "<<k<<endl;
        cin>>s;
        if(z==0 && s=="white")
        {
            h=false;
        }
        if((s=="black" && h)|| (s=="white" && !h))
        {
            up=k;
        }
        else
        {
            low=k;
        }
        ++z;
    }
    return 0;
}