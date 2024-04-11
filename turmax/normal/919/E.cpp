#include <bits/stdc++.h>

using namespace std;
#define int long long
int p;
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    int u=po(a,b-1);
    return (a*u)%p;
}
int inv(int x)
{
    return po(x,p-2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,x;
    cin>>a>>b>>p>>x;
    int ans=0;
    ans+=(p-1)*(x/(p*(p-1)));
    x%=(p*(p-1));
    for(int i=0;i<(p-1);++i)
    {
        int z=(x-i+(p-1))/(p-1);
        int t=po(a,i);
        int h=inv(t)*b;
        h%=p;
        //cout<<h<<" h "<<endl;
        int r=(h-i);
        r*=(-1);
        r%=p;
        r+=p;
        r%=p;
        //cout<<r<<" "<<z<<endl;
        if(r<z)
        {
            //cout<<" i "<<i<<endl;
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}