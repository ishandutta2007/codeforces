
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

// uu->w
// nn->m
const int mod = 1e9+7;
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
ll fib[100005];
int main()
{
    fib[1] = 1, fib[2] = 2;
    vector<pair<char,int>> v;
    string s;
    cin>>s;
    for(int i=3;i<=s.size();++i) fib[i]=fib[i-1]+fib[i-2],fib[i]%=mod;
    int cnt=1;
    for(int i=0;i<s.size();++i)
    {
        if(s[i] == 'w' || s[i] == 'm') return cout<<"0"<<endl,0;
        if(s[i] != s[i+1])
        {
            v.push_back({s[i], cnt});
            cnt=1;
        }
        else ++cnt;
    }
    ll ans = 1;
    for(auto p : v)
    {
        if(p.first=='u' || p.first=='n')
        {
            ans *= fib[p.second];
            ans %= mod;
        }
    }
    cout << ans << endl;
}