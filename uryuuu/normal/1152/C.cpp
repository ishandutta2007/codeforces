#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
vector<int>d;
ll gcd(ll a,ll b)
{
    return(b==0)?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return (a/gcd(a,b))*b;
}
int main()
{
    ll a,b;
    cin>>a>>b;
    if(a>b)
        swap(a,b);
    ll c=b-a;
    for(int i=1;i*i<=c;i++)
    {
        if(c%i==0)
        {
            d.push_back(i);
            d.push_back(c/i);
        }
    }
    ll ans=lcm(a,b);
    ll kk=0;
    for(auto f:d)
    {
        ll k=((a+f)/f)*f-a;
        if(lcm(a+k,b+k)<ans)
        {
            kk=k;
            ans=lcm(a+k,b+k);
        }
        else if(lcm(a+k,b+k)==ans)
        {
            kk=min(kk,k);
        }
    }
    cout<<kk<<endl;
    return 0;
}