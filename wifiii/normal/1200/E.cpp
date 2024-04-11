#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

typedef unsigned long long ull;
string a[100005];
ull b[2000005],c[2000005];
ull pw[2000005];
const ull seed = 132523;
const ull mod = 1e9+9999;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pw[0]=1;
    for(int i=1;i<=1000000;++i) pw[i]=pw[i-1]*seed%mod;
    int n;
    cin>>n;
    ii cin>>a[i];
    string ans=a[1];
    int sum=0;
    for(int i=2;i<=n;++i)
    {
        int len=min(a[i].size(), ans.size());
        int len2=ans.size();
        sum+=len;
        for(int j=0;j<len;++j) c[j+1]=(c[j]*seed%mod+a[i][j])%mod;
        for(int j=0;j<len;++j) b[j+1]=(b[j]+ans[len2-j-1]*pw[j])%mod;
        int mi=0;
        for(int j=1;j<=len;++j) if(b[j]==c[j]) mi=j;
        ans+=a[i].substr(mi);
    }
    cout<<ans<<endl;
}