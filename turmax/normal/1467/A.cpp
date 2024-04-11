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
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<"9"<<'\n';
        }
        if(n==2)
        {
            cout<<"98"<<'\n';
        }
        if(n<=2) continue;
        cout<<"98";
        char u='9';
        for(int i=0;i<(n-2);++i)
        {
            cout<<u;
            if(u=='9') u-=10;
            u++;
        }
        cout<<'\n';
    }
    return 0;
}