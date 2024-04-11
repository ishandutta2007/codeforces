#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=2e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

ll jie[N];
ll qm(ll a,int b)
{
    ll ret=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)ret=ret*a%mod;
    return ret;
}
ll C(int a,int b)
{
    return jie[a]*qm(jie[b],mod-2)%mod*qm(jie[a-b],mod-2)%mod;
}
ll pre[3][N],c[3],cnt,now;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    jie[0]=1;
    for(int i=1;i<N;i++)jie[i]=jie[i-1]*i%mod;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(auto i:s)if(i=='?')cnt++;
    ll ans=0;

    for(auto i:s)
    {
        if(i=='?')
        {
            ans=(ans+c[1]*qm(3,cnt-1))%mod;
        }
        else if(i=='a')c[0]++;
        else if(i=='b')c[1]=(c[1]+c[0])%mod;
        else if(i=='c')ans=(ans+c[1]*qm(3,cnt))%mod;
    }
    c[1]=0;
    for(int i=n-1;~i;i--)
    {
        if(s[i]=='?')
        {
            ans=(ans+c[1]*qm(3,cnt-1))%mod;
        }
        else if(s[i]=='c')c[2]++;
        else if(s[i]=='b')c[1]=(c[1]+c[2])%mod;
    }
    
    for(int i=0;i<s.size();i++)
    {
        if(i)
        {
            pre[0][i]=pre[0][i-1];
            pre[1][i]=pre[1][i-1];
            pre[2][i]=pre[2][i-1];
        }
        if(s[i]!='?')pre[s[i]-'a'][i]++;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='?')
        {
            ans=(ans+qm(3,cnt-1)*pre[0][i]%mod*(pre[2][n-1]-pre[2][i]))%mod;
        }
    }
    if(cnt>=2)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b')
            {
                ans=(ans+now*(cnt-now)%mod*qm(3,cnt-2))%mod;
            }
            else if(s[i]=='?')
            {
                now++;
                ans=(ans+pre[0][i]*(cnt-now)%mod*qm(3,cnt-2))%mod;
                ans=(ans+(pre[2][n-1]-pre[2][i])*(now-1)%mod*qm(3,cnt-2))%mod;
            }
        }
    }
    if(cnt>=3)ans=(ans+C(cnt,3)*qm(3,cnt-3))%mod;
    cout<<ans<<endl;
    return 0;
}