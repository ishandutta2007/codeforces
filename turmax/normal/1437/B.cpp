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
        int sum=0;
        for(int i=0;i<(n-1);++i)
        {
            if(s[i]==s[i+1])
            {
                ++sum;
            }
        }
        cout<<((sum+1)/2)<<endl;
    }
    return 0;
}