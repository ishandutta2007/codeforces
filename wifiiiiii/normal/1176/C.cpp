

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
typedef long long ll;

int a[500005],cnt[10];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,n) cin>>a[i];
    int ans = 0;
    rep(i,n)
    {
        if(a[i]==4) cnt[1]++;
        else if(a[i]==8)
        {
            if(cnt[1]) --cnt[1],++cnt[2];
            else ans++;
        }
        else if(a[i]==15)
        {
            if(cnt[2]) --cnt[2],++cnt[3];
            else ans++;
        }
        else if(a[i]==16)
        {
            if(cnt[3]) --cnt[3],++cnt[4];
            else ans++;
        }
        else if(a[i]==23)
        {
            if(cnt[4]) --cnt[4],++cnt[5];
            else ans++;
        }
        else if(a[i]==42)
        {
            if(cnt[5]) --cnt[5];
            else ans++;
        }
    }
    for(int i=1;i<=6;++i) ans+=cnt[i]*i;
    cout<<ans<<endl;
}