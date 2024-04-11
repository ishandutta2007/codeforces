#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)
#define debug(i) cout<<#i<<":"<<i<<endl;

int R[300005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int l=0,r=0;
    for(int i=0;i<s.size();++i)
    {
        r = i;
        if(r-l>1)
        {
            for(int d=1;d<=(r-l)>>1;++d)
            {
                if(s[r]==s[r-d]&&s[r]==s[r-2*d])
                {
                    for(int i=l;i<=r-2*d;++i) R[i]=r;
                    l=r-2*d+1;
                    break;
                }
            }
        }
    }
    ll ans = 0;
    int n = s.size();
    for(int i=0;i<n;++i)
    {
        if(R[i]) ans+=n-R[i];
    }
    cout<<ans<<endl;
}