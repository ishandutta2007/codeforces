#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300005;
const ll Mod=1000000007;
const ll mod=998244353;


ll F[maxn],a[maxn],b[maxn];
map<ll,ll>mp;
map<pair<ll,ll>,ll>mp2;


int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    ll sum=1ll;
    for(int i=1;i<=n;i++)
    {
        sum=sum*i%mod;
        F[i]=sum;
    }
    ll ss=1,s=1,d=1;
    for(int i=1;i<=n;i++)
        mp[a[i]]++;
    for(auto f:mp)
    {
        s=(s*F[f.second])%mod;
    }
    mp.clear();
    for(int i=1;i<=n;i++)
        mp[b[i]]++;
    for(auto f:mp)
    {
        ss=(ss*F[f.second])%mod;
    }
    for(int i=1;i<=n;i++)
    {
        mp2[make_pair(a[i],b[i])]++;
    }
    int lx=-1,ly=-1;
    for(auto f:mp2)
    {
        if(f.first.first<lx||f.first.second<ly)
        {
            d=0;
            break;
        }
        d=(d*F[f.second])%mod;
        lx=f.first.first;
        ly=f.first.second;
    }
    
    sum=(sum-ss-s+d+mod+mod+mod+mod)%mod;
    cout<<sum<<endl;
    
    
    return 0;
}