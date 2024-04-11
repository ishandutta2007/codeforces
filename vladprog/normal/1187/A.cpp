#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,s,t;
        cin>>n>>s>>t;
        int x=s+t-n;
        cout<<max(s-x+1,t-x+1)<<"\n";
    }
}