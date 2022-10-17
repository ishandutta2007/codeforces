#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;string s;
        cin>>n>>s;
        int ans = 1e9;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='>')
            {
                ans = min(ans, i);
            }
            else
            {
                ans = min(ans, n-1-i);
            }
        }
        cout << ans << endl;
    }
}