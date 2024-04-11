#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;

ll arr[maxn],dp[maxn];

int main()
{
    string s;
    ll ans=0;
    cin>>s;
    if(s[0]=='0'||s[0]=='4'||s[0]=='8')ans++;
    for(int i=1;i<s.length();i++)
    {
        if((s[i]-'0')%2==0)
        {
            if((s[i]-'0')%4==0)
            {
                ans++;
                if((s[i-1]-'0')%2==0)
                {
                    ans+=i;
                }
            }
            else if((s[i-1]-'0')%2)
            {
                ans+=i;
            }
        }
    }
    cout<<ans;
}