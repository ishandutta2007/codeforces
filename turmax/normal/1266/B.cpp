#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        if(x<=14)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(x%14>=1 && x%14<=6)
        {
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
        continue;
    }
    return 0;
}