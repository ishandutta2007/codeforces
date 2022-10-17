#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int main()
{
    int n,x,y;cin>>n>>x>>y;
    string s;cin>>s;
    int ans = 0;
    for(int i=s.size()-x;i<s.size();++i)
    {
        if(s.size()-i-1==y && s[i]=='0') ans++;
        else if(s.size()-i-1!=y && s[i]=='1') ans++;
    }
    cout<<ans<<endl;
}