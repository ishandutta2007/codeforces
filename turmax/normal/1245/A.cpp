#include <bits/stdc++.h>

using namespace std;
#define int long long
int gcd(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    if(b==0)
    {
        return a;
    }
    if(a>=b)
    {
        return gcd(a%b,b);
    }
    else
    {
        return gcd(a,b%a);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b;
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
    cin>>a>>b;
    if(gcd(a,b)==1)
    {
        cout<<"Finite"<<endl;
    }
    else
    {
        cout<<"Infinite"<<endl;
    }
    }
    return 0;
}