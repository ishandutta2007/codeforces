#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct song
{
    ll t,b;
    bool operator < (const song & so) const
    {
        return b>so.b;
    }
};
song ss[300005];
priority_queue<ll,vector<ll>,greater<ll> > Q;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>ss[i].t>>ss[i].b;
    sort(ss+1,ss+1+n);
    ll ans = 0, sum = 0;
    for(int i=1;i<=n;++i)
    {
        Q.push(ss[i].t);
        sum += ss[i].t;
        if(Q.size()>k)
        {
            ll p=Q.top();Q.pop();
            sum -= p;
        }
        ans = max(ans, sum*ss[i].b);
    }
    cout << ans << endl;
}