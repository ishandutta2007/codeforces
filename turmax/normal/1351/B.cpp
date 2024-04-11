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
        int a,b;
        cin>>a>>b;
        if(a<b)
        {
            swap(a,b);
        }
        int c,d;
        cin>>c>>d;
        if(c<d)
        {
            swap(c,d);
        }
        if(a==c && (b+d)==a)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else
        {
            cout<<"NO"<<endl;
            continue;
        }
    }
    return 0;
}