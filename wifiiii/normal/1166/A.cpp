#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int cnt[30];
int main()
{
    int n;
    cin>>n;
    rep(i,n)
    {
        string s;
        cin>>s;
        cnt[s[0]-'a']++;
    }
    ll ans = 0;
    for(int i=0;i<26;++i)
    {
        ll p = cnt[i]/2, q = cnt[i]-p;
        ans += p*(p-1)/2+q*(q-1)/2;
    }
    cout<<ans<<endl;
}