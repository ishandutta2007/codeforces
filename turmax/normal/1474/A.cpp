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
        string s;
        cin>>s;
        int curr=0;
        for(int i=0;i<n;++i)
        {
            if(i==0 || (s[i]+1)!=(s[i-1]+curr)) {cout<<'1';curr=1;}
            else {curr=0;cout<<'0';}
        }
        cout<<endl;
    }
    return 0;
}