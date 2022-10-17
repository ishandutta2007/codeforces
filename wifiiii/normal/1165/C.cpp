#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int main()
{
    int n;string s;
    cin>>n;cin>>s;
    string ans;
    for(int i=0;i<s.size();++i)
    {
        if(ans.size()%2==0) ans+=s[i];
        else
        {
            if(s[i]!=ans[ans.size()-1]) ans+=s[i];
        }
    }
    if(ans.size()%2) ans=ans.substr(0,ans.size()-1);
    cout<<s.size()-ans.size()<<endl;
    cout<<ans<<endl;
}