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
        set <int> a;
        int n;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            int x;
            cin>>x;
            a.insert(x);
        }
        cout<<a.size()<<endl;
    }
    return 0;
}