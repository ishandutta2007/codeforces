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
ll a[301000];
ll b[301000];
ll gcd(ll a,ll b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    ll g=0;
    for(int i=2;i<=n;i++)
    {
        g=gcd(g,a[i]-a[i-1]);
    }
    for(int i=1;i<=m;i++)
    {
        if(g%b[i]==0)
        {
            cout<<"YES"<<endl;
            cout<<a[1]<<' '<<i;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}