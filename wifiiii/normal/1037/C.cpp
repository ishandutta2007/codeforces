#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(s[i] == t[i]) continue;
        if(i+1<n && s[i]==t[i+1] && s[i+1]==t[i]) i++,ans++;
        else ans++;
    }
    cout<<ans<<endl;
}