#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;cin>>s;
        int mid=(n-1)/2;
        int r=mid;while(r<n && s[r]==s[mid]) ++r; int l=mid;while(l>=0 && s[l]==s[mid]) --l;
        cout<<(r-l-1)<<'\n';
    }
    return 0;
}