#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
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
    int n,m,l,r;
    cin>>n>>m>>l>>r;
    if((n*m)%2==1)
    {
        cout<<po(r-l+1,n*m);
        return 0;
    }
    int z=(r-l+1);
    if(z%2==0)
    {
        cout<<(po(z,n*m)*inv(2))%p;
        return 0;
    }
    else
    {
        cout<<((po(z,n*m)+1)*inv(2))%p;
        return 0;
    }
    return 0;
}