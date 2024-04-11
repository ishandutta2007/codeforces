#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int a,b,c;
    int x;
    for(int i=0;i<t;++i)
    {
        cin>>a>>b>>c;
        x=(a-b);
        if((x+c)%2==0)
        {
            cout<<max(0LL,min((x+c)/2,c+1))<<endl;
        }
        else
        {
            cout<<max(0LL,min(((x+c-1)/2+1),c+1))<<endl;
        }
    }
    return 0;
}