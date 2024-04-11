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
    int a,b,n,m;
    cin>>a>>b>>n>>m;
    if(a>=b)
    {
        swap(a,b);
    }
    a-=m;
    if(a>=0 && (a+b)>=n)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    }
    return 0;
}