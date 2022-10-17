#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int a[105],b[105];
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int ans = 0;
    for(int i=1;i<=s.size();++i)
    {
        if(s[i-1]=='+') ans++;
        else ans=max(0,ans-1);
    }
    cout<<ans<<endl;
}