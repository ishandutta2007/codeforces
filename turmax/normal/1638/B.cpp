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
        vector <int> v0,v1;
        int a[n];for(auto &h:a) {cin>>h;if(h&1) v1.push_back(h); else v0.push_back(h);}
        vector <int> v00=v0,v10=v1;
        sort(v00.begin(),v00.end());sort(v10.begin(),v10.end());
        cout<<((v00==v0 && v10==v1) ? "YES" : "NO")<<'\n';
    }
    return 0;
}