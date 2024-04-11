#include <bits/stdc++.h>

using namespace std;
#define int long long
int f(char x)
{
    if(x=='1')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a,b;
    cin>>a>>b;
    int sum1=0;
    int sum=0;
    for(int i=0;i<b.size();++i)
    {
        sum1+=f(a[i]);
        sum1%=2;
    }
    for(int i=0;i<b.size();++i)
    {
        sum+=f(b[i]);
        sum%=2;
    }
    int x=0;
    for(int j=0;j<=(a.size()-b.size());++j)
    {
        if(sum1==sum)
        {
            ++x;
        }
        if(j==(a.size()-b.size()))
            {
                break;
            }
        sum1-=f(a[j]);
        sum1+=f(a[b.size()+j]);
        sum1=(sum1+2)%2;
    }
    cout<<x;
    return 0;
}