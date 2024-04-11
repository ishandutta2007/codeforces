#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
const int mod = 1e9+7;

int a[300005];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    ii cin>>a[i];
    ll ans=0;
    for(int i=1;i<=m;++i)
    {
        vector<pair<ll,int>> b;
        int cnt=0,st=i;ll tmp=0;
        for(int j=i;j<=n;++j)
        {
            tmp+=a[j];
            cnt++;
            if(cnt==m) cnt=0,b.push_back({tmp-k,st}),st=j+1,tmp=0;
        }
        if(cnt) b.push_back({tmp-k,st});
        ll cur=0;
        for(auto p:b)
        {
//            cout<<p.first<<" "<<p.second<<" "<<cur<<" "<<ans<<endl;
            ll tmp=0,mtmp=0;
            for(int j=p.second;j<=min(p.second+m-1,n);++j)
            {
                tmp+=a[j];
                mtmp=max(mtmp,tmp);
            }
            if(mtmp>k) ans=max(ans,cur+mtmp-k);
            cur+=p.first;
            ans=max(ans,cur);
            if(cur<0) cur=0;
        }
    }
    cout<<ans<<endl;
}