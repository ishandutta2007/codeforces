#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n;
    cin>>n;
    string s;
    if(n%2==1)
    {
        s+='7';
        n-=3;
    }
    else
    {
        s+='1';
        n-=2;
    }
    while(n>=2)
    {
        s+='1';
        n-=2;
    }
    cout<<s<<endl;
    }
    return 0;
}