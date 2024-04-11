#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,s;
    cin>>n>>s;
    if(s>=2*n)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<(n-1);++i)
        {
            cout<<2<<" ";
            s-=2;
        }
        cout<<s<<endl;
        cout<<1;
        return 0;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}