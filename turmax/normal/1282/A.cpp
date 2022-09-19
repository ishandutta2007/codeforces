#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    int h;
    for(int cycle=0;cycle<q;++cycle)
    {
    int a,b,c,r;
    cin>>a>>b>>c>>r;
    if(a>b)
    {
        swap(a,b);
    }
    if(c>=b)
    {
        h=c-r;
        if(h<b)
        {
            cout<<max(h-a,0LL)<<endl;
            continue;
        }
        else
        {
            cout<<(b-a)<<endl;
            continue;
        }
    }
    else if(c<=a)
    {
        h=c+r;
        if(h>a)
        {
            cout<<max(b-h,0LL)<<endl;
            continue;
        }
        else
        {
            cout<<(b-a)<<endl;
            continue;
        }
    }
    else
    {
        int h1=(c-r);
        int h2=(c+r);
        int sum=0;
        sum+=max(h1-a,0LL);
        sum+=max(b-h2,0LL);
        cout<<sum<<endl;
        continue;
    }
    }
    return 0;
}