#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

string a[100005];
const int mod = 998244353;
int cnt[11];
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i],cnt[a[i].size()]++;
    ll ans=0;
    ii
    {
        string &s=a[i];
        for(int k=1;k<s.size();++k)
        {
            ll tmp=0;
            for(int p=0;p<s.size();++p)
            {
                if(s.size()-p <= k) tmp=tmp*10+s[p]-'0',tmp=tmp*10+s[p]-'0';
                else tmp=tmp*10+2*(s[p]-'0');
                tmp%=mod;
            }
            ans=(ans+tmp*cnt[k]%mod)%mod;
        }
        int tot=0;
        for(int j=s.size();j<=10;++j) tot+=cnt[j];
        ll tmp=0;
        for(int j=0;j<s.size();++j)
        {
            tmp=tmp*10+s[j]-'0';
            tmp=tmp*10+s[j]-'0';
            tmp%=mod;
        }
        ans=(ans+tmp*tot%mod)%mod;
    }
    cout<<ans<<endl;
}