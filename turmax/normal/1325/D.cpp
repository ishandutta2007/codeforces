#include <bits/stdc++.h>

using namespace std;
#define int long long
int po[60];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;
    for(int i=0;i<60;++i)
    {
        po[i]=u;
        u*=2;
    }
    int a,b;
    cin>>b>>a;
    int x=(a-b);
    if(a==0 & b==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(x==0)
    {
        cout<<1<<endl;
        cout<<a<<endl;
        return 0;
    }
    if(x%2==1 || x<0)
    {
        cout<<(-1);
        return 0;
    }
    bool h=true;
    int s1=b,s2=0;
    if(x%2==1)
    {
        h=false;
    }
    for(int i=1;i<60;++i)
    {
        if((x/po[i])%2==1 && (b/po[i-1])%2==1)
        {
            h=false;
        }
        else if((x/po[i])%2==1)
        {
            s1+=po[i-1];
            s2+=po[i-1];
        }
    }
    if(h)
    {
        cout<<2<<endl;
        cout<<s1<<" "<<s2<<endl;
        return 0;
    }
    else
    {
        cout<<3<<endl;
        cout<<b<<" "<<x/2<<" "<<x/2<<endl;
    }
    return 0;
}