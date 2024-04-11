#include <bits/stdc++.h>

using namespace std;
#define int long long
#define div trheijdk
const int p=1e9+7;
const int maxn=1e5+5;
vector<int> div[maxn];int f[maxn];
int lcm(int a,int b) {return (a*b)/__gcd(a,b);}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<maxn;++i) for(int j=i;j<maxn;j+=i) div[j].push_back(i);
    int n;cin>>n;int ans=0;f[1]=1;for(int i=2;i<maxn;++i) {f[i]=i;for(int j:div[i]) if(j!=i) f[i]-=f[j];}
    for(int c=1;c<=n-1;++c)
    {
        int s=(n-c);
        for(int d:div[s])
        {
            ans+=((lcm(c,d))%p)*(f[s/d]-(d==s));ans%=p;
        }
    }
    cout<<ans;
    return 0;
}